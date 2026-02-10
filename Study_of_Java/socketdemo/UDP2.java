import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;

public class UDP2 {
    public static void main(String[] args) {
        //创建客户端
        try(DatagramSocket ds=new DatagramSocket(8888)){
            //创建数据缓存区
            byte[] b="itbaizhan".getBytes();
            //创建数据报对象
            DatagramPacket dp=new DatagramPacket(b,b.length,new InetSocketAddress("127.0.0.1",9999));
            ds.send(dp);
            System.out.println("数据发送成功");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
