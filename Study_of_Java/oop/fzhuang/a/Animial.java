package fzhuang.a;

/**
 * 多态及向上（向下）转型问题
 */

public class Animial {
    public void shout(){
        System.out.println("lalala");
    }

    public static void main(String[] args) {
        animialshout(new Dog());
        animialshout(new Cat());
        animialshout(new Animial());
        Animial animial=new Dog(); //编译运行时候判断的类型是不一样的
        animial.shout();
        //animial.more(); 这个方法Dog内部有，但编译器认为是Animial,会报错，它不知道实际运行时候创建的对象是Dog
        //进行转型
        Dog d=(Dog)animial;
        d.more();
        //必须先判断是否那个类型再进行转型，否则编译器会报转型错误
        if(animial instanceof Cat){
            Cat c=(Cat)animial;
            c.cats();
        }
    }
    //多态方法
    public static void animialshout(Animial a){
        a.shout();
    }

}
class Dog extends Animial{
    private int year;
    @Override
    public void shout(){
        System.out.println("wangwang");
    }
    public void more(){
        System.out.println("different");
    }
}
class Cat extends Animial{
    @Override
    public void shout(){
        System.out.println("miaomiao");;
    }
    public void cats(){
        System.out.println("1111");
    }
}

