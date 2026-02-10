import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

//创建客户端
class Send2 extends Thread{
    private Socket socket;
    Send2(Socket socket) {
        this.socket = socket;
    }
    public void run() {
        try(Scanner scanner = new Scanner(System.in)){
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
class Rece2 extends Thread{
    private Socket socket;
    Rece2(Socket socket) {
        this.socket = socket;
    }
    public void run() {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
            String str;
            while((str=br.readLine())!=null){
                System.out.println("服务端说："+str);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
public class doubletx2 {
    public static void main(String[] args) {
        try{
            Socket socket=new Socket("127.0.0.1",8888);
            System.out.println("连接成功！");
            //启动发送线程
            new Send2(socket).start();
            //启动接收线程
            new Rece2(socket).start();
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
