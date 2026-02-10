import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

class Sends extends Thread{
    private Socket socket;
    private Scanner scanner;
    Sends(Socket socket,Scanner scanner){
        this.socket = socket;
        this.scanner=scanner;
    }
    @Override
    public void run() {
        //发送数据，不用创建Scanner对象了，因为在主线程中创建完了并且以参数形式传进来了。
        try (PrintWriter pw=new java.io.PrintWriter(this.socket.getOutputStream())){
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
//接受信息的线程
class Receive extends Thread{
    private Socket socket;
    public Receive(Socket socket){
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
    public class GoodTcp {
    public static void main(String[] args) {
        ServerSocket serverSocket = null;
        try {
            //键盘输入对象
            Scanner scanner = new Scanner(System.in);
            System.out.println("请输入：server,<port> / <ip>,<port>");
            String str = scanner.nextLine();
            String[] arr = str.split(",");  //split(",") 是 String 类的方法，作用是按照逗号 , 把字符串拆分成多个部分，返回一个字符串数组（String[]）。
            Socket socket=null;
            if ("server".equals(arr[0])) {
                //启动服务端
                serverSocket = new ServerSocket(Integer.parseInt(arr[1]));  //将字符串转化为整型int
                System.out.println("服务端启动，开始监听。。。。。");
                //监听客户端连接
                socket = serverSocket.accept();
                System.out.println("有客户端连接了");
            } else {
                //启动客户端
                socket = new java.net.Socket(arr[0], Integer.parseInt(arr[1]));
                System.out.println("连接成功！");
            }
            //启动发送消息线程
            new Thread(new Sends(socket,scanner)).start();
            //启动接受消息线程
            new Thread(new Receive(socket)).start();

        }catch (Exception e){
            e.printStackTrace();
        }finally {
            if(serverSocket!=null){
                try {
                    serverSocket.close();
                }catch (Exception e){
                    e.printStackTrace();
                }
            }
        }
    }
}
