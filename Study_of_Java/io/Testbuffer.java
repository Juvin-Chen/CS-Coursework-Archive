import java.io.*;

public class Testbuffer {
    public static void main(String[] args) {
        //使用字节缓冲区提高读写效率 ,buffer默认数组大小是8192
        long t1=System.currentTimeMillis();
        copyFileWithBuffer("d:/a.txt", "d:/c.txt");
        long t2=System.currentTimeMillis();
        System.out.println("复制文件耗时："+(t2-t1)+"毫秒");
        /* 更简洁的写法，直接写
        try (BufferedInputStream bis = new BufferedInputStream(new FileInputStream("largeFile.txt"), 8192)) {
            // 这里设置缓冲区大小为 8192 字节，即 8KB
            int data;
            while ((data = bis.read()) != -1) {
                System.out.print((char) data);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        关于这个代码的解释：
        1. 缓冲流的核心原理：内部自带缓冲区（数组）
        `BufferedInputStream` 的本质是在普通流（如 FileInputStream）之外包装了一层内存缓冲区（字节数组），它的工作流程是：
        - 当你创建 `BufferedInputStream` 时（比如指定大小 8192 字节），它会在内存中创建一个 8192 字节的字节数组作为缓冲区。
        - 第一次调用 `bis.read()` 时，缓冲流会一次性从文件中读取 8192 字节的数据到缓冲区（批量读取，减少磁盘 IO）。
        - 之后每次调用 `bis.read()`，并不会直接读磁盘，而是从缓冲区中“取”一个字节返回。 （记住这种方式它也是只取一个字节返回）
        - 当缓冲区的数据被取完后，缓冲流会自动再次从文件中读取一批数据填满缓冲区，重复上述过程。

        2. 代码中 `read()` 方法的特殊性
        代码中用的 `bis.read()` 是单字节读取的方法，但它的底层是从缓冲流的内部数组中获取数据，而不是直接操作磁盘：
        while ((data = bis.read()) != -1) {  // 每次从缓冲区取1个字节
            System.out.print((char) data);   // 转成字符打印
        }
        - 这里的 `read()` 虽然每次只返回一个字节，但缓冲流已经提前通过内部数组批量读取了数据，避免了频繁的磁盘 IO（这正是缓冲流提高效率的关键）。
        - 对比普通的 `FileInputStream.read()`（直接读磁盘），`BufferedInputStream.read()` 实际是“从内存缓冲区取数据”，速度快得多。

        3. 缓冲流与“手动用数组读取”的关系
        缓冲流本质上是自动实现了“数组缓冲区”的功能，省去了我们手动定义数组的麻烦：
        - 如果你不用缓冲流，想提高效率，需要自己写数组逻辑（可参考之间代码中的定义）
        - 用缓冲流时，`BufferedInputStream` 内部已经包含了类似的数组逻辑，我们只需要调用简单的 `read()` 即可，底层自动完成批量读取和缓冲。

        这段代码的核心是：
        - 缓冲流内部通过数组（缓冲区）实现高效读取，即使我们调用单字节的 `read()` 方法，实际也是从内部数组中取数据，避免了频繁的磁盘操作。
        - 代码中的 `(char) data` 只是将读取到的单个字节转成字符打印（适合 ASCII 等单字节编码），不影响缓冲流的底层工作机制。
        缓冲流的优势在于：自动管理缓冲区数组，简化代码的同时保证高效 IO。
         */
    }
    public static void copyFileWithBuffer(String srcPath, String destPath) {
        //括号里可以创建多个对象要加分号。关闭流的顺序：后开先关，按照IO流对象创建的顺序的逆序关闭
        try ( //实例化节点流对象，实例化处理流对象，这里的BufferedInputStream(InputStream in, int size)
            BufferedInputStream bis = new BufferedInputStream(new FileInputStream(srcPath)); //fis后面没有跟一个数组大小，使用的是默认的构造8192大小的数组
            BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(destPath,true))) {
            int temp = 0;
            while ((temp = bis.read()) != -1){
                bos.write(temp);  //其实这里的底层都是二进制的，无论是英文还是中文，都是字节的形式存储的，即使是中文字符，它也是由多个字节组成的，计算机会识别这为中文然后再进行存储，具体可见下
            }
            bos.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
/*
为什么没有类型转换也能成功复制英文？以及文件编码详解
1. 为什么没有类型转换也能正确复制英文？
int temp;
while ((temp = bis.read()) != -1){
    bos.write(temp);
}
底层机制：read() 返回的是 0-255 范围的 int 值（字节的无符号表示），不是真正的字符
write(int) 会取 int 值的 低 8 位（即一个字节）写入文件
英文在 ASCII/UTF-8 编码中都是 单字节字符，所以：
'h' → ASCII 104 → 写入字节 01101000
读取时 01101000 → 104 → 显示为 'h'
关键点：这本质是字节级的二进制复制，不是字符转换。只要文件编码一致，任何内容都能复制（包括图片、视频）。

2. 为什么中文也可能正常复制？
中文在 UTF-8 中占 3 个字节（如 "你" = 0xE4 0xBD 0xA0）
字节流会原样复制这 3 个字节，只要：
源文件是 UTF-8 编码
目标文件也用 UTF-8 打开
复制过程没有破坏字节序列
示例流程：
源文件："你" → [0xE4, 0xBD, 0xA0]
字节流复制 → 目标文件：[0xE4, 0xBD, 0xA0] → 显示为 "你"
3. 何时会出问题？
场景	                结果	        原因
用 char 强制转换中文	乱码	        单字节 char 截断多字节字符
源编码和目标编码不同	乱码	        相同字节在不同编码中含义不同
用字符流处理二进制文件	文件损坏	    图片/视频被误解释为字符
4. 编码核心知识
常见编码：
编码	        特点	        适用场景
ASCII	    单字节，    仅英文	纯英文文本
ISO-8859-1	单字节，    支持西欧	西方语言
UTF-8	    1-4字节，  兼容ASCII	现代标准（推荐）
GBK	        双字节中文	旧中文系统
 */
