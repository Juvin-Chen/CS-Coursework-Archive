import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


/**
 1 测试Checked Exception，try-catch-finally语句捕获异常
 2 测试throws声明式异常处理，在main方法后面添加throw语句模块
 */
public class Main {

    public static void main(String[] args){
        FileReader reader = null; //FileReader是一个类，代表文件读取器
        //main 方法声明的 throws FileNotFoundException 可以去掉，但需要确保 FileReader 的创建操作放在 try 块内部（因为它可能抛出 FileNotFoundException）
        try {
            reader = new FileReader("d:/a.txt");
            char c = (char) reader.read(); //原本返回的是int类型的ASCII码
            char c1 = (char) reader.read(); //每次读取一个字符
            System.out.println("" + c + c1);
        } catch (FileNotFoundException e) {
            e.printStackTrace(); //打印 异常信息
            System.out.println("文件不存在");
        } catch (IOException e) {  //catch的子类在前，父类在后
            e.printStackTrace();
        }finally {
            //finally中的代码无论是否发生异常都会执行
            //通常用于释放资源
            System.out.println("执行了finally");
            try {
                if(reader!=null)  reader.close();
            } catch (IOException e) {
                e.printStackTrace();  //e.printStackTrace(); 侧重于输出异常信息辅助调试
            }
        }
        /* try-with-resources 语法，自动关闭资源，可自动关闭实现AutoCloseable接口的资源，实现类需要实现close()方法
                try (FileReader reader = new FileReader(filePath)) {
                    char c = (char) reader.read(); ......
                    System.out.println("" + c + c2 + c3);
                } catch (IOException e) {
                    // 捕获并打印异常堆栈信息
                    e.printStackTrace();
                }    */
    }
}