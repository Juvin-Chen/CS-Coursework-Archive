import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

public class UDP1 {
    public static void main(String[] args) {
        try(DatagramSocket ds=new DatagramSocket(9999)){
            System.out.println("UDP服务端启动，开始监听。。。。。");
            //创建数据缓存区
            byte[] b=new byte[1024];
            //创建数据报对象
            DatagramPacket dp=new DatagramPacket(b,b.length);
            //等待接收客户端发送的数据
            ds.receive(dp);
            //读取数据
            String str=new String(dp.getData(),0,dp.getLength());
            System.out.println("客户端说："+str);
    } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
