import java.io.File;
import java.util.*;

public class TestFile {
    public static void main(String[] args) throws Exception {
        System.out.println(System.getProperty("user.dir")); // 获取当前项目路径，这句话只不过是获取当前项目的路径，不影响下面在当前目录下面创建文件
        /*
        关于new操作的本质理解
        操作本质：File 对象是内存中的 “路径描述符”，它的存在是为了关联磁盘上的某个路径（可能存在也可能不存在），但不会主动创建 / 修改磁盘上的实际文件 / 目录。
         */
        File f = new File("a.txt"); //相对路径。默认放在user.dir目录下,显示使用相对路径("./test.txt"); 等价于上面的写法
        f.createNewFile();
        f.delete();

        File f2 = new File("d:/b.txt"); // 创建File对象，指定绝对路径
        f2.createNewFile(); // 创建一个新的文件
        f2.delete();

        /*
        mkdir() 方法
        功能：尝试创建一个目录。
        特点：仅能创建单级目录；若创建路径中中间某个父级目录缺失（比如要创建 a/b，但 a 不存在 ），则整个创建操作会失败，返回 false 。
        mkdirs() 方法
        功能：尝试创建目录（支持多级目录创建 ）。
        特点：若创建路径中中间某个父级目录缺失（比如要创建 a/b/c，但 a 或 a/b 不存在 ），会自动创建缺失的父级目录，最终完成整个多级目录的创建，创建成功返回 true ；若因权限不足等其他问题导致创建失败，返回 false 。
         */
        File f3= new File("d:/test/dir1/dir2/dir3"); // 创建多级目录
        boolean flag=f3.mkdir();
        System.out.println(flag); //false
        flag=f3.mkdirs();
        System.out.println(flag); //true

        //printfiletree
        File dir = new File("d:/VSCODE-C++"); // 创建一个目录对象，准确来说是创建一个 “指向它的对象”，真正的创建是create的那个
        printFileTree(dir, 0); // 打印目录树，从根目录开始，缩进级别为0
        File ff=new File(System.getProperty("user.dir")); // 获取当前项目路径
        printFileTree(ff, 0); // 打印当前项目路径的目录树
    }
    //递归打印目录树结构
    static void printFileTree(File file, int level) {
        for(int i = 0; i < level; i++) {
            System.out.print("-"); // 打印缩进
        }
        System.out.println(file.getName()); // 打印文件或目录的名称

        if (file.isDirectory()) {
                // 如果是目录，递归打印其子文件和子目录
            File[] files = file.listFiles();
                for (File f : files) {
                    printFileTree(f, level + 1);
                }
            }

    }
}
