import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Twowaysocket {
    public static void main(String[] args) {
        System.out.println("服务器启动 监听8888端口");
        try(ServerSocket serverSocket = new ServerSocket(8888);){
            Socket socket=serverSocket.accept();
            //创建键盘输入对象
            Scanner scanner = new Scanner(System.in);
            //创建向服务端发送消息的输出流对象
            PrintWriter pw = new PrintWriter(socket.getOutputStream());
            //通过与服务端对应的Socket对象获取输入流对象，这几步跟之前的写法一样
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            while(true){
                //读取客户端发送的消息
                String str = br.readLine();
                System.out.println("客户端说："+str);
                if("exit".equals(str)){
                    break;
                }
                System.out.print("请输入回复内容：");
                String reply = scanner.nextLine();
                pw.println(reply);
                pw.flush();
            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
