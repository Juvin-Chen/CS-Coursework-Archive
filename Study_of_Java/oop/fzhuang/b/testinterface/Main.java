package fzhuang.b.testinterface;

public class Main {

    public static void main(String[] args) {
        Test01 a=new Test01();
        a.print();

        System.out.println("测试静态方法");
        testinterface01.teststatic();
        Test01.tesestatic();

        System.out.println("测试接口的多继承");
        Cexample c=new Cexample();
        c.A();
        c.C();
    }
}
interface A{
    void A();
}
interface B{
    void B();
}
interface C extends A,B{
    void C();
    //C的实现类就需要定义的是三个方法
}
class Cexample implements C{

    @Override
    public void C() {
        System.out.println('C');
    }

    @Override
    public void A() {
        System.out.println('A');
    }

    @Override
    public void B() {

    }
}