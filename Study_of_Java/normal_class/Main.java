import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        //包装类，主要的功能也就是下面示例的两个
        Integer i=new Integer(10); //java9开始废弃
        Integer j=Integer.valueOf(20); //官方推荐

        int a=j.intValue(); //把包装类转换为基本数据类型
        double b=j.doubleValue();
        System.out.println(a);
        System.out.println(b);

        //字符串转化为数字
        Integer m=Integer.valueOf("100");  //方法重载的作用,Java 中允许在同一个类中定义多个同名方法，只是它们的参数列表不同
        System.out.println(Integer.MAX_VALUE);

        //自动装箱和拆箱，将基本数据类型和包装类之间的转换自动完成
        Integer n=100; //自动装箱，编译器会自动将基本数据类型转换为包装类，本质上编译器会变成.valuof的写法
        int k=n; //自动拆箱，编译器会自动将包装类转换为基本数据类型，本质上编译器会变成.intValue的写法
        //空指针问题
        Integer o=null; //包装类可以为null
        //int p=o; //编译错误，不能将null转换为基本数据类型，会报错

        //自动装箱的缓存处理
        /* 类的内部会将-128-127存在数组中，这个做法是为了提高效率，具体可参照下面的类的编写代码
        public static Integer valueOf(int i) {
            if (i >= IntegerCache.low && i <= IntegerCache.high)
            return IntegerCache.cache[i + (-IntegerCache.low)];
            return new Integer(i);
        }
         */
        Integer x=127; //在-128到127之间的数字会被缓存
        Integer y=127; //在-128到127之间的数字会被缓存
        System.out.println(x==y); //true，因为是同一个对象
        Integer z=128; //超过127的数字不会被缓存
        Integer w=128;  //超过127的数字不会被缓存
        System.out.println(z==w); //false，因为是两个不同的对象

        //自定义包装类（仅限于练习）
        MyInteger myInt1 = new MyInteger(10);

    }
}
//仿照Integer类的设计，创建一个自定义的包装类MyInteger
class MyInteger {
    private final int value;  //final 修饰的变量确实需要赋值，但不一定要在声明时赋值，赋值之后则不可以被修改
    private static MyInteger[] cache = new MyInteger[256];
    private static final int LOW=-128;
    private static final int HIGH=127;

    static {
        for (int i = 0; i < cache.length; i++) {
            cache[i] = new MyInteger(i - 128); // 缓存-128到127的整数
        }
        System.out.println(Arrays.toString(cache)); // 打印缓存数组
    }
    public MyInteger(int value) {
        this.value = value;
    }

    public static MyInteger valueof(int value) {
        if (value >= LOW && value <= HIGH) {
            return cache[value + 128]; // 返回缓存中的对象
        }
        return new MyInteger(value);
    }

    @Override
    public String toString() {
        return "MyInteger{" +
                "value=" + value +
                '}';
    }
}