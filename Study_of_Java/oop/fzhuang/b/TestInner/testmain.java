package fzhuang.b.TestInner;

public class testmain {

    public void test1(A a){
        a.run();
    }

    public static void main(String[] args) {

        //测试非静态内部类
        Outer o=new Outer();
        Outer.Inner i=new Outer().new Inner();
        i.show();

        //测试静态内部类
        Outer.Inner2 a=new Outer.Inner2();
        a.test();

        //匿名类，不需要再定义去实现接口的一个类，适合那种只需要使用一次的类，比如键盘监听器
        testmain t=new testmain();
        //创建了一个没有名字的匿名实现类
        t.test1(new A() {
            @Override
            public void run() {
                System.out.println("创建了第一个匿名实现类"); //同样格式还可以定义第二个，是两个不同的匿名类
            }
        });

        //局部内部类，不常用，略

    }
}
interface A{
    void run();
}