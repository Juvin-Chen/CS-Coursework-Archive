import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class Twowaysocket2 {
    public static void main(String[] args) {
        //创建客户端
        try (Socket socket = new Socket("127.0.0.1",8888);) {
            //创建向服务端发送消息的输出流对象
            System.out.println("客户端启动，连接服务端");
            //创建键盘输入对象
            Scanner scanner = new Scanner(System.in);
            //通过与服务端对应的Socket对象获取输出流对象
            PrintWriter pw = new PrintWriter(socket.getOutputStream());
            //通过与服务端对应的Socket对象获取输入流对象
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));

                while(true) {
                    //通过键盘输入获取需要向服务端发送的消息
                    String str = scanner.nextLine();

                    //将消息发送到服务端
                    pw.println(str);
                    pw.flush();

                    if ("exit".equals(str)) {
                        break;
                    }

                    //读取服务端返回的消息
                    String serverInput = br.readLine();
                    System.out.println("服务端返回的：" + serverInput);

                }
            }catch (Exception e) {
            e.printStackTrace();
        }
    }
}
