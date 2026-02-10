import java.io.*;

public class Testdatastream {
    public static void main(String[] args) {
        /*
        数据流将“基本数据类型与字符串类型”作为数据源，从而允许程序以与机器无关的方式从底层输入输出流中操作Java基本数据类型与字符串类型。
        DataInputStream和DataOutputStream提供了可以存取与机器无关的所有Java基础类型数据（如：int、double、String等）的方法。
        */
        //创建数据输出流对象与文件字节输出流对象,这里后面创建的文件必须要是字节流
        try(DataOutputStream dos = new DataOutputStream(new FileOutputStream("d:/data"));
            //创建数据输入流对象与文件字节输入流对象
            DataInputStream dis = new DataInputStream(new FileInputStream("d:/data"))){
            //将如下数据写入到文件中
            dos.writeChar('a');
            dos.writeInt(10);
            dos.writeDouble(Math.random());
            dos.writeBoolean(true);
            dos.writeUTF("北京尚学堂");
            //手动刷新缓冲区：将流中数据写入到文件中
            dos.flush();
            //直接读取数据：读取的顺序要与写入的顺序一致，否则不能正确读取数据。
            System.out.println("char: " + dis.readChar());
            System.out.println("int: " + dis.readInt());
            System.out.println("double: " + dis.readDouble());
            System.out.println("boolean: " + dis.readBoolean());
            System.out.println("String: " + dis.readUTF());

        }catch(IOException e){
            e.printStackTrace();
        }

        //Oldlu提示：使用数据流时，读取的顺序一定要与写入的顺序一致，否则不能正确读取数据。
    }
}
