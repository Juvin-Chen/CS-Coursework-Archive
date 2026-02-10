package www;

/**
 * 继承，以及继承中类内方法的重写，final的修饰用法，组合
 */

/*
测试包的导入
import com.test.Car;
import com.test.*;
//这个*代表的就是导入包下面的所以类，一个包下面的类可以直接使用
//静态导入，Math下面很多方法都是静态的
import static java.lang.Math.*;
import static java.lang.Math.PI;
*/

public class testextend {
    public static void main(String[] args) {
        Student s1=new Student("chen",164,"physics");
        System.out.println(s1 instanceof Student);
        System.out.println(s1 instanceof Person); //两个都·但会返回true，用于判断从属于这个类
        Boy xiaoxin=new Boy();
        xiaoxin.print();
    }
}

class Person{
    String name;
    int height;
    public void rest(){
        System.out.println("persons have a rest!");
    }
    Person(String a,int height){
        name=a;
        this.height=height;
    }
}

class Student extends Person{
    String major;

    @Override //可加可不加，这个是方法的重写，而且有规定返回值子类小于父类
    public void rest() {
        System.out.println("students have a rest!");
    }

    public void study(){
        System.out.println("start to study now!");
        rest();
        System.out.println(name);
    }
    Student(String name,int height,String major){
        super(name, height);  // 调用父类的构造函数初始化 name 和 height
        this.major=major;
    }
}

//测试组合part,组合的核心是将父类对象作为子类的属性
class Boy{
    Person Eddie=new Person("Eddie",180);
    Student chen=new Student("chen",175,"java");
    void print(){
        System.out.println(Eddie.name);
        System.out.println(this.chen.major);
    }
}
