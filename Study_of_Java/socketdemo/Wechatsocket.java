/*
发送信息和接受信息的线程
 */

import java.net.ServerSocket;
import java.net.Socket;

//发送消息的线程
class Send implements Runnable {
    //与客户端对应的Socket对象
    private Socket socket;

    public Send(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        try {
            //创建键盘输入对象
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            //创建向服务端发送消息的输出流对象
            java.io.PrintWriter pw = new java.io.PrintWriter(socket.getOutputStream());
            while (true) {
                System.out.print("请输入回复内容：");
                String reply = scanner.nextLine();
                pw.println(reply);
                pw.flush();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

public class Wechatsocket {
    public static void main(String[] args) {
        try(ServerSocket serverSocket = new ServerSocket(8888);){
            System.out.println("服务端启动，等待监听");
            Socket socket=serverSocket.accept();
            System.out.println("有客户端连接了");
            while(true){
                //监听客户端连接
                System.out.println("有客户端连接了");
                //启动发送消息线程
                new Thread(new Send(socket)).start();
                //启动接受消息线程

            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
