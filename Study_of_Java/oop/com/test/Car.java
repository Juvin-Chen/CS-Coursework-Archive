package com.test;

public class Car {
    public int a=9;
    //两个数相加的函数
    public int add(int a, int b) {
        return a + b;
    }
    //两个数相减的函数
    public int sub(int a, int b) {
        return a - b;
    }
    //两个数相乘的函数
    public int mul(int a, int b) {
        return a * b;
    }
//两个数相除的函数
    public int div(int a, int b) {
        if (b == 0) {
            throw new IllegalArgumentException("除数不能为0");
        }
        return a / b;
    }
    public static void main(String[] args) {

    }
}
