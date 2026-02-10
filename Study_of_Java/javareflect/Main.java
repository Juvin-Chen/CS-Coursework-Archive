class Person{
    String name;
    int age;
}
public class Main {
    public static void main(String[] args) {
        //1 getclass()方法获取Class对象，非静态的，需要对象调用
        Person p=new Person();
        Class c=p.getClass(); //获取Class对象的引用
        System.out.println(c); //这样默认调用ToString()，这个类这个方法也是被改写
        System.out.println(c.getName());
        Person p2=new Person();
        System.out.println(p2.getClass()==p.getClass()); //true，Class对象只有一个。

        //2 通过类名.class获取Class对象，这是静态方法
        Class c2=Person.class;
        System.out.println(c2.getName());
        System.out.println(1);

        //3 通过Class的静态方法forName(String className)获取Class对象
        try {
            Class c3=Class.forName("Person"); //注意这里的类名是带包名的全类名,这里我能够直接打印出来是因为这个类在默认包下，一般来讲是需要使用包声明的，就是package xxx.xxx.xxx;
            System.out.println(c3.getName());
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

    }
}