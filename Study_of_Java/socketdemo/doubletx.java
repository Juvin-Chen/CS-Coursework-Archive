import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

//创建发送线程的线程
class Sendmsg extends Thread{
    private Socket socket;
    Sendmsg(Socket socket){
        this.socket = socket;
    }
    @Override
    public void run() {
        //发送数据
        Scanner scanner = new Scanner(System.in);
        try {
            PrintWriter pw=new PrintWriter(this.socket.getOutputStream());
            while(true) {
                String str = scanner.nextLine();
                if ("exit".equals(str)) break;
                pw.println(str);
                pw.flush();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
//创建接收线程的线程
class Rece extends Thread{
    private Socket socket;
    Rece(Socket socket){
        this.socket = socket;
    }
    @Override
    public void run() {
        //接收数据
        try(BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
            String str;
            while((str=br.readLine())!=null){
                System.out.println("客户端说："+str);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

public class doubletx {
    public static void main(String[] args) {
        try(ServerSocket serverSocket=new ServerSocket(8888)){
            System.out.println("服务端启动，开始监听。。。。。");
            Socket socket=serverSocket.accept();
            System.out.println("连接成功！");
            //启动发送线程
            new Sendmsg(socket).start();
            //启动接收线程
            new Rece(socket).start();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
