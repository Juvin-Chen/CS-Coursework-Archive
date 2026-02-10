import java.io.*;
/*
要注意关于编码的实际含义，通过转换流可以有效解决乱码问题
 */
public class Testchangestream {
    public static void main(String[] args) {
        //转换流 new InputStreamReader(FileInputStream,"gbk（一种字符编码）")
        /* 补充知识
        ANSI(American National Standards Institute)美国国家标准协会，一般来讲如果我们电脑txt文件设置这种字符编码的话，我们的电脑操作系统如果是中文的，它的ANSI就是中文的，如果txt文件对应的是这种编码，那么我们设置文件的一些编码操作需要用到GBK编码。
        GBK(Guojia Biaozhun Kuozhan 国家标准扩展)，是GB2312的扩展，包含了更多的汉字字符，常用于中文Windows系统
        UTF-8(Unicode Transformation Format 8-bit)，是一种可变长度的字符编码方式，能够表示世界上几乎所有的字符，广泛用于互联网和现代操作
         */

        //创建文件字节输入流对象，字节->字符的转换（InputStreamReader）
        try(FileInputStream fis = new FileInputStream("d:/sxt.txt");
            //创建转换流(字节到字符的转换)流对象，并在该对象中指定编码。
            InputStreamReader isr = new InputStreamReader(fis,"UTF-8")){
            StringBuilder sb = new StringBuilder();
            //操作流对象
            int temp = 0;  //字节刚开始读入的值都是int类型的
            while((temp = isr.read()) != -1){
                //int 类型和 char 类型的转换之所以能得到正确的字符，核心是因为 InputStreamReader 已经按照 GBK 编码规则完成了字节到字符（Unicode）的转换。否则如果按之前的直接进行读取会出现乱码现象
                sb.append((char) temp);
            }
            System.out.println(sb);
        }catch(IOException e){
            e.printStackTrace();
        }

        //通过字节流读取文本文件并添加行号，要实现三层转换，先用字节输入流进行读入然后再进行字节流到字符流的转换，再用缓冲字符流进行按行的方式的读取和写入，最后再用字节流进行写入到文件中

        //创建字符输入缓冲流、输入字节到字符转换流、文件字节输入流对象
        try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("d:/sxt.txt")));
            //创建字符输出缓冲流、输出字符到字节转换流、文件字节输出流对象
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("d:/sxt4.txt")))){

            //操作流
            String temp = "";
            //序号变量
            int i = 1;
            //按照行读取
            while((temp = br.readLine()) != null){
                bw.write(i+","+temp);
                //换行
                bw.newLine();
                //序号累加
                i++;
            }
            //刷新
            bw.flush();
        }catch(IOException e){
            e.printStackTrace();
        }


    }
}
