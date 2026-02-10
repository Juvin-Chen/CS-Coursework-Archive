package fzhuang.b.Teststring;

/**
 每个类都是自己的常量池，常量池里面的可以复用，但是如果是用new创建，就是在堆上面创建的新对象了
 */
public class teststring {
    public static void main(String[] args) {
        String s0=null;
        String s1="";
        String s2="java";
        String s3=new String("apple");
        String s4=new String("java");
        String s5="java";
        System.out.println(s3.length());
        System.out.println(s4.length());
        //System.out.println(s0.length()); 会报空指针异常
        System.out.println(s2==s5); //这个比较的是地址 true
        System.out.println(s2==s4); //false
        System.out.println(s2.equals(s4)); //true,比较它们的字符是不是一样的

        String str1="core java";
        String str2="Core java";
        System.out.println(str1.charAt(3)); //打印下标为3的字符，本质上字符串是一个字符数组，string是不可变的 e
        System.out.println(str1.equalsIgnoreCase(str2)); //跟equals的区别是忽略了大小写 true
        System.out.println(str1.indexOf("java")); //是否包含，包含的话返回第一个出现的字符的下标 5
        System.out.println(str1.indexOf("hello")); //不包含则返回-1 -1
        String str=str1.replace(' ','&'); //core&java，将两个字符进行替换
        System.out.println(str);


        //index是从前往后找，lastIndexOf从后往前找

        String s="";
        String s1="how are you?";
        System.out.println(s1.startsWith("how"));  //是否以how开头
        System.out.println(s1.endsWith("you"));  //是否you结尾
        s=s1.substring(4); //提取子字符串，从下标4开始一直到结尾
        System.out.println(s);
        s=s1.substring(4,7); //提取下标：[4,7)
        System.out.println(s);
        s=s1.toLowerCase(); //Lower Upper一个是转小写一个转大写
        System.out.println(s);
        String s2=" how old are you ";
        s=s2.trim(); //去除字符串首尾的空格，注意：中间的空格不能去除
        System.out.println(s);
        String s3="I love";
    }
}

