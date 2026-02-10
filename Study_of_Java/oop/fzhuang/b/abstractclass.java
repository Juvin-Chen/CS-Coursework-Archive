package fzhuang.b;

/*
抽象方法：
1. 使用 abstract 修饰的方法，没有方法体，只有声明。
2. 定义的是一种 “规范”，就是告诉子类必须要给抽象方法提供具体的实现。

抽象类：
包含抽象方法的类就是抽象类。
通过抽象类，我们就可以做到严格限制子类的设计，使子类之间更加通用。

不能被调用，它是用来被继承的；
再说接口，接口一般只能包含静态常量和抽象方法，由类去实现接口，需要实现接口中的所有方法，而且这些方法也都是public  class _ implements _
 */

//接口的实现，注意，如果Vic需要用public修饰符，必须要和.java文件名一致
interface Vic{
    /*public abstract*/void speed();
    void length();
}

public abstract class abstractclass {
    int age;
    public abstract void rest();
    public abstract void run();
    abstractclass(int age){
        this.age=age;
    }
    public void shout(){
    //抽象类里面自己定义自己的方法
    }

    public static void main(String[] args) {
        Vic a=new Car();
        a.length();
        a.speed();
    }
}
//抽象类
class Rat extends abstractclass{
    Rat(int age) {
        super(age);
    }

    @Override
    public void rest() {}
    @Override
    public void run() {}
}
//接口
class Car implements Vic{

    @Override
    public void speed() {
        System.out.println("speed:13m/s");
    }

    @Override
    public void length() {
        System.out.println("length:100m");
    }
}