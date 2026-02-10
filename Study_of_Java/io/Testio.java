import java.io.*;

public class Testio {
    public static void main(String[] args) throws IOException {
        //创建一个流对象,点击ctrl+ALT+t,这个是处理这种异常的快捷键
        //System.out.println(new File("d:/a.txt").exists());  // 输出true才说明路径正确

        // 下面这种为经典写法需要掌握
        FileInputStream fis2 = null;
        try {
            fis2=new FileInputStream("d:/a.txt");
            StringBuilder s=new StringBuilder();
            int temp=0;
            while ((temp= fis2.read())!=-1){
                s.append((char) temp);
            }
            System.out.println(s);

        }catch (Exception e){
            e.printStackTrace();
        }finally {
            //关闭流，流对象使用完之后一定要关闭，否则会占用系统资源
            if (fis2 != null) {
                try {
                    fis2.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        //IO流新语法写法，现代 Java 推荐使用 try-with-resources 语法自动关闭流，简化代码(无需手动写 finally)
        //对于实现类java.lang.AutoCloseable的对象，使用try-with-resources语法可以自动关闭资源
        //这种写法是Java 7之后的写法，推荐使用
        try (FileInputStream fis3 = new FileInputStream("d:/a.txt")) {
            StringBuilder s = new StringBuilder();
            int temp=0;
            while ((temp = fis3.read()) != -1) {
                s.append((char) temp);
            }
            System.out.println(s);
        } catch (IOException e) {  //像这种直接写IOExpection / Expection 可以涵盖的错误比较多，就只需要写一个，而不用多个错误分开去写
            e.printStackTrace();
        }

        /*
        流的概念细分 （输入流：数据源到程序（以InputStream,Reader结尾） 输出流（以OutputStream,Writer结尾））

        按处理的数据单元分类：
        - 字节流：以字节为单位获取数据，命名上以Stream结尾的流一般是字节流，如FileInputStream、FileOutputStream。(像图片就是字节流)
        - 字符流：以字符为单位获取数据，命名上以Reader/Writer结尾的流一般是字符流，如FileReader、FileWriter。

        按处理对象不同分类：
        - 节点流：可以直接从数据源或目的地读写数据，如FileInputStream、FileReader、DataInputStream等。（说白了就是直接跟数据源挂钩）
        - 处理流：不直接连接到数据源或目的地，是“处理流的流”。通过对其他流的处理提高程序的性能，如BufferedInputStream、BufferedReader等。处理流也叫包装流。

        节点流处于IO操作的第一线，所有操作必须通过它们进行；处理流可以对节点流进行包装，提高性能或提高程序的灵活性。
         */

    }
}