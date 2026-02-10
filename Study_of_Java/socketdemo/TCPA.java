import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

/*
为什么服务器端和客户端的代码要分开写？
服务器端和客户端的代码写在同一个main方法中，导致执行顺序被阻塞，无法真正建立连接。
一、代码无法运行的关键原因
服务器端的accept()方法是阻塞的
当执行ServerSocket serverSocket = new ServerSocket(8888);后，调用serverSocket.accept()时，程序会暂停在这里等待客户端连接（阻塞状态），不会继续执行后面的客户端代码。
因此，你的客户端代码（new Socket(...)部分）永远没有机会运行，导致服务器一直等待，客户端从未启动，最终超时或无响应。
单线程执行顺序问题
main方法是单线程执行的，必须等服务器端代码执行完毕（或退出阻塞），才会执行客户端代码。但服务器端的accept()会一直阻塞到有客户端连接，而客户端代码又在它后面，形成了 “死锁”。
 */

public class TCPA {
    public static void main(String[] args) {
        //创建服务端
        System.out.println("服务端启动，等待监听");
        //创建ServerSocket对象
        //指定监听的端口号
        try {
            ServerSocket serverSocket = new ServerSocket(8888); //监听8888端口，此时线程阻塞，等待客户端连接
            //调用accept方法，等待客户端连接，accept是一个阻塞方法
            Socket socket = serverSocket.accept(); //返回的这个Socket对象，就是客户端的Socket对象
            System.out.println("有客户端连接了"); //当有客户端连接时，程序才会继续往下执行，会解除阻塞
            //通过客户端对应的Socket对象中的输入流对象，获取客户端发送过来的消息
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            System.out.println(br.readLine()); //读取客户端发送过来的一行字符串

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
