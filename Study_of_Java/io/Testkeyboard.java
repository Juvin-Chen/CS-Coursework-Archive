import java.io.*;

/*
通过转换流实现键盘输入屏幕输出
 */
public class Testkeyboard {
    public static void main(String[] args) {
        /* 补充知识：
        在文件存储或网络传输等场景下（编码转换后）
        当涉及到文件存储或者网络传输时，字符会根据具体的编码格式被转换为字节序列，此时 'a' 占用字节数由编码格式决定：
        ASCII 编码：ASCII 编码只对英文字母、数字、标点等 128 个字符进行了编码，编码范围是 0 - 127 ，刚好可以用一个字节（8 位）来表示。在 ASCII 编码中，'a' 的编码值是 97 ，二进制表示为 0110 0001 ，占用 1 个字节。
         */
        // 创建字符输入和输出流:使用转换流将字节流转换成字符流
        //这个方法没用自动关闭的那个try
        BufferedReader br = null;
        BufferedWriter bw = null;
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
            // 使用字符输入和输出流
            String str = br.readLine();
            // 一直读取，直到用户输入了exit为止
            while (!"exit".equals(str)) {
                // 写到控制台
                bw.write(str);
                bw.newLine();// 写一行后换行
                bw.flush();// 手动刷新
                // 再读一行
                str = br.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            // 关闭字符输入和输出流
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (bw != null) {
                try {
                    bw.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
/*  关于上面这个例子try里面的内容以及整个过程的讲解
我们一步步拆解 bw = new BufferedWriter(new OutputStreamWriter(System.out)); 这句话，结合 “字节流→字符流→缓冲字符流” 的分层设计，就能明白它的作用和必要性：
1. 先看最底层：System.out 是字节输出流
System.out 的本质是 PrintStream，属于 字节输出流（继承自 OutputStream）。它的作用是：向控制台输出字节数据。
但我们日常写代码时，更习惯输出字符 / 字符串（比如 System.out.println("你好")）。这里 Java 其实默默做了一件事：把字符串自动转换成字节，再通过 PrintStream 输出。
2. 中间层：OutputStreamWriter 是 “字节→字符” 的桥梁
new OutputStreamWriter(System.out) 的作用是：
把底层的字节输出流（System.out）转换成 字符输出流（Writer 类型），并且可以指定编码（如果不指定，用系统默认编码）。
它的核心价值是：让字节流具备 “理解字符” 的能力。
比如你要输出中文字符 你好，OutputStreamWriter 会按照编码（如 UTF-8/GBK）把 你好 转换成对应的字节，再交给 System.out 输出。
如果直接用 System.out（字节流），你需要自己手动把字符转成字节（比如 System.out.write("你好".getBytes("UTF-8"))），而 OutputStreamWriter 帮你封装了这个过程。
3. 最上层：BufferedWriter 是 “带缓冲的字符流”
new BufferedWriter(...) 的作用是：
给字符输出流（这里是 OutputStreamWriter）套一层缓冲，让字符输出更高效。
缓冲的意义是：
字符流默认是 “写一个字符就立即输出”，而缓冲流会先把字符临时存在内存缓冲区，攒一批再输出（比如满 8KB 再真正写入），减少 IO 次数，提升性能。
同时，BufferedWriter 还提供了 newLine() 方法，能自动适配系统换行符（Windows 用 \r\n，Linux 用 \n），比直接用 System.out.println 更灵活。
一句话总结：
这句话的作用是 “给字节流套两层：先转成字符流，再套缓冲”，每一层都解决了特定问题：
System.out（字节流）→ 只能输出字节，不理解字符；
OutputStreamWriter（字符流）→ 让字节流能 “理解字符”，支持编码转换；
BufferedWriter（缓冲字符流）→ 让字符输出更高效，还能方便地换行。
为什么必须这么多层？
因为 Java 的 IO 设计是 “分层职责”：
字节流（OutputStream）：负责最底层的 “字节搬运”，不关心字符；
字符流（Writer）：负责 “字节→字符” 的编码转换，让开发者能用字符编程；
缓冲流（BufferedWriter）：负责 “性能优化”，让 IO 更高效。
如果跳过某一层（比如直接用 BufferedWriter 包裹 System.out），会发现 类型不匹配（BufferedWriter 的构造方法需要 Writer，但 System.out 是 OutputStream，不是 Writer 类型）。因此必须用 OutputStreamWriter 做中间转换，让字节流先变成字符流，才能被缓冲字符流处理。
举个更直观的例子
假设你想高效输出一行中文到控制台，需要三个步骤：
有一个 “能输出字节” 的流 → System.out（字节流）；
让这个流 “能处理字符和编码” → 用 OutputStreamWriter 转换成字符流；
让字符输出更高效、更方便 → 用 BufferedWriter 套缓冲，支持 newLine()。
这三层是 各司其职 的：
字节流负责 “搬砖”（输出字节）；
转换流负责 “翻译”（字节↔字符）；
缓冲流负责 “优化”（性能和便捷方法）。
所以 bw = new BufferedWriter(new OutputStreamWriter(System.out)) 本质是 “给控制台输出套上字符处理和缓冲的能力”，让字符输出更灵活、高效。
 */