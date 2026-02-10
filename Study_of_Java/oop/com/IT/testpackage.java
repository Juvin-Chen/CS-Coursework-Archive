package com.IT;

/**
 * 测试包的导入
 */


import com.test.Car;
import com.test.*;
//这个*代表的就是导入包下面的所以类，一个包下面的类可以直接使用
//静态导入，Math下面很多方法都是静态的
import static java.lang.Math.*;
import static java.lang.Math.PI;

public class testpackage {
    public static void main(String[] args) {
        Car car=new Car();
        System.out.println(car.a);
        System.out.println(random());
        System.out.println(PI);

    }
}
