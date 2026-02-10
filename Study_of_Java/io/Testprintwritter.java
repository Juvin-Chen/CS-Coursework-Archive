import java.io.*;
/*  可以简化之前写的那种方法，这个方法让整个过程变得很简单《字符输出流对象》
在Java的IO流中专门提供了用于字符输出的流对象PrintWriter。该对象具有自动行刷新缓冲字符输出流，特点是可以按行写出字符串，并且可通过println();方法实现自动换行。
 */
public class Testprintwritter {
    public static void main(String[] args) {
        //创建字符输出流对象
        try(PrintWriter pw = new PrintWriter("d:/sxt5.txt")){
            //调用不带换行方法完成内容的输出
            pw.print("abc");
            pw.print("def");
            //调用带有自动换行方法完成内容的输出
            pw.println("Oldlu");
            pw.println("sxt");
            pw.flush();
        }catch(IOException e){
            e.printStackTrace();
        }

        //下面补充一个关于它的应用：通过字符输出流添加行号
        //创建字符输入缓冲流对象与文件字符输入流对象
        try(BufferedReader br = new BufferedReader(new FileReader("d:/sxt.txt"));
            //创建字符输出流对象
            PrintWriter pw = new PrintWriter("d:/sxt6.txt")){
            //操作流
            String temp = "";
            //定义序号变量
            int i = 1;
            while((temp = br.readLine()) != null){
                pw.println(i+","+temp);
                //序号累加
                i++;
            }
            //刷新
            pw.flush();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}
