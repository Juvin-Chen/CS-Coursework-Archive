package fzhuang.b.TestInner;

import java.sql.SQLOutput;

public class Outer {
    private int age=10;
    private static int age2=100;
    public void show(){
        System.out.println("Outer.show");
        System.out.println(age);
    }

    //内部类可以访问外部类，反之则不可以
    //非静态内部类
    public class Inner{
        int age=20;
        public void show(){
            System.out.println("Inner.show");
            System.out.println(age);
            System.out.println(Outer.this.age);
            Outer.this.show();
        }
    }

    //静态内部类，可以访问外部类的静态成员，但是普通成员就不可以
    static class Inner2{
        public void test(){
            System.out.println(age2);
            //System.out.println(age); 普通属性无法
        }
    }
}
