package fzhuang.b.testinterface;
/*
接口里面默认的方法需要加default 静态方法，实现接口的类也可以直接调用接口中的默认方法
接口里的多继承
 */

public interface testinterface01{
    void print();
    default void moren(){
        System.out.println("111");
        System.out.println("222");
        teststatic(); //普通方法里面可以调用静态方法
    }
    //这个的静态方法是从属于类的 实现的代码就是testinterface01.teststatic
    public static void teststatic(){
        System.out.println("teststatic");
    }
}
class Test01 implements testinterface01{

    @Override
    public void print() {
        System.out.println("成功定义了接口中的抽象方法");
    }
    //接口中的默认方法也可以重写
    public static void tesestatic(){
        System.out.println("在子类中定义的静态方法");
    }
}

