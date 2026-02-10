import java.io.*;
/*
这部分代码中包含了一些换行操作，至于在这个内容之前的Fileoutputstream内容如果需要换行，是通过添加\r\n来实现的。
换行符\r\n是Windows系统的换行符，Linux系统是\n，Mac则是别的
 */

public class Testzifu {
    public static void main(String[] args) {

        //创建文件字符输入流对象
        try(FileReader fr = new FileReader("d:/a.txt")){
            StringBuilder sb = new StringBuilder(); //可变字符串
            //读取文件
            int temp = 0;
            while((temp = fr.read()) != -1){
                sb.append((char)temp);
            }
            System.out.println(sb);
        }catch (IOException e){
            e.printStackTrace();
        }

        //文件字符输出流，创建文件字符输出流对象，这个文件如果没有的话系统也会自动帮忙创建
        try(FileWriter fw = new FileWriter("d:/aa.txt")){
            fw.write("您好尚学堂\r\n"); //这个可以直接以字符串的形式写入
            fw.write("您好Old Lu\r\n"); //换行符\r\n是Windows系统的换行符
            fw.write("何以解忧\r\n");
            fw.write("唯有尚学堂\r\n");
            //刷新流，强制将缓冲区中的数据写入到文件中
            fw.flush();
        }catch (IOException e){
            e.printStackTrace();
        }

        //Buffer部分
        // 创建字符输入缓冲流以及文件字符流对象
        try (BufferedReader br = new BufferedReader(new FileReader("d:/aa.txt"))) {

            // 操作字符输入缓冲流,因为是字符的这种就可以用字符串String接收
            String temp = "";
            while ((temp = br.readLine()) != null) {  //readLine()方法是按行读取，读取一行返回一行，遇到换行符就停止
                System.out.println(temp);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
        //创建文件字符输出流对象
        try(FileWriter fw = new FileWriter("d:/sxt.txt");
            //创建字符输出缓冲流对象
            BufferedWriter bw = new BufferedWriter(fw)){
            //操作缓冲流
            bw.write("您好尚学堂");
            bw.write("您好Oldlu");
            //换行
            bw.newLine();
            bw.write("何以解忧");
            bw.newLine();
            bw.write("唯有尚学堂");
            bw.flush();
        }catch (IOException e){
            e.printStackTrace();
        }



        //给文件加行数的方式
        //创建字符输入缓冲流与文件字符输入流
        try(BufferedReader br = new BufferedReader(new FileReader("d:/sxt.txt"));
            //创建字符输出缓冲流与文件字符输出流
            BufferedWriter bw = new BufferedWriter(new FileWriter("d:/sxt2.txt"))){

            String temp ="";
            //定义序号变量
            int i = 1;
            while((temp = br.readLine()) != null){
                //将读取到的内容添加序号，并输出到指定文件中。
                bw.write(i+","+temp);
                //换行处理
                bw.newLine();
                //序号变量累加
                i++;
            }
            //刷新
            bw.flush();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}
