import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Testfileinputstream {
    public static void main(String[] args) {
        //testFileInputStream();
        StringBuilder s = new StringBuilder();
        try (FileInputStream fis = new FileInputStream("d:/a.txt")) {
            int temp;
            while((temp = fis.read()) != -1){
                s.append((char) temp);
            }
            System.out.println(s);
        }catch(Exception e){
            e.printStackTrace();
        }
        //输出FileOutputStream，后面的布尔值。  true:内容会追加 false：内容会覆盖
        try(FileOutputStream fos= new FileOutputStream("d:/b.txt",true)) {
            String content = "Hello, World!";
            /*
            FileOutputStream 的 write 方法重载
            FileOutputStream 的 write 方法有多种重载形式，并非只能接收字符数组：
            1 write(int b)：写入单个字节（参数是 int 类型，但实际只取低 8 位作为字节数据）
            2 write(byte[] b)：写入整个字节数组
            3 write(byte[] b, int off, int len)：写入字节数组的一部分（从 off 位置开始，长度为 len）
             */
            fos.write(content.getBytes());  //write这个方法的参数是一个字符数组，.getBytes()方法将字符串转换为字节数组
            //刷新，将数据从内存中写入到磁盘中
            fos.write(s.toString().getBytes()); //这里的s是StringBuilder对象，这个方法的参数要求我们需要先把它转换为string对象之后再调用getBytes()方法将其转换为字节数组
            fos.flush();
            System.out.println("内容已写入 b.txt");
        } catch (Exception e) {
            e.printStackTrace();
        }

        //通过字节缓冲区提高读写效率
        /*
        通过字节缓冲区提高读写效率
        通过创建一个指定长度的字节数组作为缓冲区，以此来提高IO流的读写效率。该方式适用于读取较大文件时的缓冲区定义。注意：缓冲区的长度一定是2的整数幂。一般情况下1024长度较为合适。

        long t1=System.currentTimeMillis();
        copyFile("d:/a.txt","d:/c.txt");
        long t2=System.currentTimeMillis();
        System.out.println("复制文件耗时："+(t2-t1)+"毫秒");
        */

    }
    public static void copyFile(String srcPath,String destPath) {
        //括号里可以创建多个对象要加分号。关闭流的顺序：后开先关，按照IO流对象创建的顺序的逆序关闭
        try (FileInputStream fis = new FileInputStream(srcPath);
             FileOutputStream fos = new FileOutputStream(destPath)) {
            int temp = 0;
            //这是不用缓冲流的方式
//            while ((temp= fis.read())!=-1){
//                fos.write(temp);
//            }
//            /*
//            使用 FileOutputStream 写文件时，如果不调用 flush() 方法，大部分情况下数据最终也能写入文件，但存在一些特殊场景可能导致问题，核心原因和 Java 的 I/O 流 “缓冲区” 机制有关
//             */
//            fos.flush(); //刷新，将数据从内存中写入到磁盘中
//            System.out.println("文件复制完成");

            //创建字节缓冲区
            byte[] buffer = new byte[1024]; // 1KB 缓冲区
            //使用缓冲区进行读写
            while ((temp = fis.read(buffer)) != -1)
                fos.write(buffer, 0, temp); // 只写入实际读取的，用这样的重载方法，直接写fos.write(buffer)的话每次都读取1024大小的，会导致最后一些空的字符也会被读取进来
                //这个参数列表里面的0是从buffer的第0个位置开始写，temp是写多少个字节
                fos.flush(); //刷新，将数据从内存中写入到磁盘中
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
    }
}
