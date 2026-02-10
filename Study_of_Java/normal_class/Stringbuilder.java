/*
字符串相关类
StringBuffer 和 StringBuilder 都是可变的字符序列。
StringBuffer 线程安全，做线程同步检查，效率较低。
StringBuilder 线程不安全，不做线程同步检查，因此效率较高。建议采用该类。因为大多数情况下不需要做线程安全。
 */
public class Stringbuilder {
    public static void main(String[] args) {
        String a="aa";
        StringBuilder b=new StringBuilder("bb");
        for (int i=0; i < 7; i++) {
            //a+=i; 每次都会创建一个新的字符串对象，效率低下，切记在String中不要使用+=操作符
            b.append('a'+i); //使用StringBuilder的append方法
        }
        System.out.println(b);
        System.out.println(b.toString()); //将StringBuilder转换为String输出
        b.append("end"); //在末尾追加字符串
        System.out.println(b);  //和上面的toString()方法效果一样

        //StringBuffer和StringBuilder的区别与共同点，下面的方法同样适用于StringBuilder
        StringBuffer c=new StringBuffer("cc");
        c.insert(0,"bb").insert(0,"aa"); //在开头插入字符串，从0位置开始插入
        System.out.println(c); //输出结果为aabbcc
        c.delete(0,2); //删除开头的两个字符
        c.deleteCharAt(0).deleteCharAt(0); //删除开头的两个字符，和上面的一样
        c.append("abc");
        System.out.println(c.reverse()); //将字符串反转
        System.out.println(c.charAt(2)); //获取指定位置的字符
    }
}
