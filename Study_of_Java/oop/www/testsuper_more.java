package www;

import java.sql.SQLOutput;
import java.util.Objects;

/**
 equal方法的重写：equal()提供对象内容相等的逻辑，默认是比较两个对象的hashcode(可以理解为地址),每个对象都有一个唯一的hashcode，它是根据地址生成的
 super的使用，super可以看作是 直接父类对象的引用,可通过super来访问在父类中被子类覆盖的方法/属性，重写只是修改方法，并没有清除父类中的方法等
 */

public class testsuper_more extends Object{
    String name;
    int id;
    String pwd;
    testsuper_more(String name,int id,String pwd){
        this.name=name;
        this.pwd=pwd;
        this.id=id;
    }

    //在这里开始重写equal方法，右键点击生成equal方法操作
    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        testsuper_more that = (testsuper_more) o;
        return id == that.id;
    }
    //这个可保留也可以不保留
    @Override
    public int hashCode() {
        return Objects.hashCode(id);
    }

    public static void main(String[] args) {
        testsuper_more t1=new testsuper_more("chen",001,"123456");
        testsuper_more t2=new testsuper_more("wang",003,"654321");
        testsuper_more t3=new testsuper_more("zhang",001,"900001");
        System.out.println(t1.toString()); //我们也可以重写toString方法
        System.out.println(t2.toString()); //toString()默认答应的是一串东西+@+地址
        //当使用的是默认的equal方法 System.out.println(t1.equals(t2));//地址不用所以实际上打印false
        System.out.println(t1.equals(t3));
        //测试写法只能用一次
        new Child2();
    }
}
class Father{
    public int value;
    public int age;
    public void f(){
        value=100;
        System.out.println("age:"+age);
        System.out.println("value:"+value);
    }
}
class Child extends Father{
    public Father father;
    public void f(){
        super.f();
        value=200;
        System.out.println(value);
        System.out.println(super.value); //调用父类的成员变量
    }
    public void f2(){
    //......
    }
}

//继承树的追溯
class Father2{
    static {
        System.out.println(1);
    }
    public Father2(){
        System.out.println("set up Father.");
    }
}
class Child2 extends Father2{
    //静态初始化也是先加载父类，同理的
    static {
        System.out.println(2);
    }
    public Child2(){
        //super(); 构造函数若是第一行没有调用super()或者this()，Java都会默认调用super(),这个是父类的无参构造
        System.out.println("set up Child.");
    }
}

