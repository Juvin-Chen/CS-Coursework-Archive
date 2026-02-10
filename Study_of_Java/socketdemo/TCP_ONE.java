import java.io.*;
import java.net.*;

public class TCP_ONE {
    public static void main(String[] args) {
        //单向通信
        System.out.println("服务端启动，开始监听。。。。。");
        try(ServerSocket serverSocket = new ServerSocket(8888);
            //监听8888端口，获与取客户端对应的Socket对象
            Socket socket = serverSocket.accept();
            //通过与客户端对应的Socket对象获取输入流对象
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            //通过与客户端对应的Socket对象获取输出流对象
            PrintWriter pw = new PrintWriter(socket.getOutputStream())){
            System.out.println("连接成功！");
            while(true){
                //读取客户端发送的消息
                String str = br.readLine();
                System.out.println("客户端说："+str);
                if("exit".equals(str)){
                    break;
                }
                pw.println(str);
                pw.flush();
            }
        }catch(Exception e){
            e.printStackTrace();
            System.out.println("服务端启动失败。。。。。");
        }
    }
}
