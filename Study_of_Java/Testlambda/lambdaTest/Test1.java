package lambdaTest;

@FunctionalInterface  //这个注解的作用：只能含有一个抽象方法
interface noreturn {
    void show();
}

interface f2 {
    int add(int a, int b);
}

interface f3 {
    void fun(int a, int b);
}
interface f4{
    int sub();
}
public class Test1 {
    public static void main(String[] args) {
        //1.无参无返回值
        noreturn nreturn = () -> {
            System.out.println("hello lambda");
        };  //通过lambda表达式对接口做了一个具体的实现
        nreturn.show();
        //简化写法
        noreturn n = () -> System.out.println("hello lambda");

        //2.有参有返回值
        f2 f = (a, b) -> a + b;
        int sum = f.add(10, 20);
        System.out.println("sum=" + sum);
        System.out.println("the second sum:"+f.add(100,200));

        //3.有参无返回值
        f3 f33 = (a, b) -> {
            System.out.println("a=" + a + ",b=" + b);
            System.out.println("a+b=" + (a + b));
        };
        f33.fun(10, 20);

        f4 f44=()->10-5;
        System.out.println("f44.sub()="+f44.sub());

        //4.引用已有的方法 (使用这种方法必须保证接口中的抽象方法和已有的方法的形参列表和返回值类型都一样)并且main方法和addnum方法都在同一个Test1类下面，都是静态的
        //这个静态方法也可以不出现在Test1类中，如果是在Test2类中，那么引用的时候就要写成Test2::addnum
        f2 f222=Test1::addnum;
        System.out.println("f222.add(100,200)="+f222.add(100,200));
        //引用非静态方法
        Test1 t1=new Test1();
        f4 f444=t1::subnum;
        System.out.println("f444.sub()="+f444.sub());

    }

    public static int addnum(int a,int b){
        return a+b;
    }
    public int subnum(){
        return 2;
    }
}
