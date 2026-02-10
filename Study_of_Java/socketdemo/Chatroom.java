import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.*;
import java.util.Scanner;

//接受客户端信息线程
class Chatreceive extends Thread {
    private Socket socket;

    public Chatreceive(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
            while(true){
                String msg = br.readLine();
                synchronized ("a") {
                    Chatroom.buf = "["+this.socket.getInetAddress()+"] "+msg;
                    "a".notifyAll(); //通知所有发送线程可以发送数据了
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
//发送信息线程
class Chatsend extends Thread {
    private Socket socket;
    Chatsend(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        //发送数据
        try (PrintWriter pw = new PrintWriter(this.socket.getOutputStream())) {
            while (true) {
                synchronized ("a") {
                "a".wait();
                //将公共数据区的数据发送出去
                String str = Chatroom.buf;
                if ("exit".equals(str)) break;
                pw.println(str);
                pw.flush();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
public class Chatroom {
    public static String buf;
    public static void main(String[] args) {
        System.out.println("chatroom started");
        System.out.println("listen at 8888");
        try (ServerSocket serverSocket = new ServerSocket(8888);) {
            while (true) {
                Socket socket = serverSocket.accept();
                System.out.println("a client connected");
                System.out.println("连接到"+""+socket.getInetAddress());
                new Chatreceive(socket).start();
                new Chatsend(socket).start();
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
