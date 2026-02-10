package com.phone;

import java.util.*;

public class DataValidation {
    /*
    补充一点：为什么我们不直接在类中定义Scanner对象呢？
    如果我们在类中定义Scanner对象，那么这个Scanner对象的生命周期就会和类的生命周期一样长，
    这样会导致Scanner对象一直存在，直到类被销毁，这样也会导致资源浪费和性能问题。占用内存空间
    然后在方法中定义这个Scanner对象，这个对象会随着方法消失被JVM垃圾回收，是作为一个局部变量形式来定义。
    而且主要是这个scanner一直存在没有太大的意义。
     */
    //菜单输入验证,是在1-6之间的数字
    public int menuValidate(int min, int max) {
        String regex = "[1-9]{1}";
        Scanner scanner = new Scanner(System.in);
        while(true) {
            System.out.println("请输入菜单选项，范围是" + min + "-" + max);
            String input = scanner.nextLine();
            if (input.matches(regex)) {
                int choice = Integer.parseInt(input);
                if(choice >= min && choice <= max){
                    return choice;
                }else{
                    System.out.println("您输入的菜单选项不符，请输入" + min + "到" + max + "之间的数字");
                }
            } else {
                System.out.println("输入菜单选项错误，请检查");
            }
        }
    }
    //姓名 字母（长度是1-10之间）大小写无所谓
    public String nameValidate() {
        String regex = "[a-zA-Z]{1,10}";
        Scanner scanner = new Scanner(System.in);
        while(true) {
            System.out.println("请输入姓名，长度是1-10之间");
            String input = scanner.nextLine();
            if (input.matches(regex)) {
                return input;
            } else {
                System.out.println("输入姓名错误，请检查");
            }
        }
    }
    //年龄输入验证，规定为10-99
    public int ageValidate() {
        //对年龄的验证
        String regex = "[1-9]{1}[0-9]{1}";
        Scanner scanner = new Scanner(System.in);
        while(true) {
            System.out.println("请输入年龄，范围是10-99");
            String input = scanner.nextLine();
            if (input.matches(regex)) {
                int age = Integer.parseInt(input);
                if(age >= 10 && age <= 99){
                    return age;
                }else{
                    System.out.println("您输入的年龄不符，请输入10到99之间的数字");
                }
            } else {
                System.out.println("输入年龄错误，请检查");
            }
        }
    }
    //性别输入验证，性别的输入要求 男（m/M）女（f/F）
    public String sexValidate() {
        String regex = "[m|M|f|F]{1}";
        Scanner scanner = new Scanner(System.in);
        while(true) {
            System.out.println("请输入性别，男（m/M）女（f/F）");
            String input = scanner.nextLine();
            if (input.matches(regex)) {
                return input;
            }
            else {
                System.out.println("输入性别错误，请检查");
            }
        }
    }
    //电话号码输入验证，电话号码的输入要求是允许带有区号的座机号 也允许手机号11位
    public String telnumValidate() {
        String regex = "(\\d{3,4}-)?\\d{7,8}|1[3-9]\\d{9}";
        Scanner scanner = new Scanner(System.in);
        while(true) {
            System.out.println("请输入电话号码，允许带有区号的座机号 也允许手机号");
            String input = scanner.nextLine();
            if (input.matches(regex)) {
                return input;
            } else {
                System.out.println("输入电话号码错误，请检查");
            }
        }
    }
    //住址输入验证，允许是字母/数字，长度1-50
    public String addressValidate() {
        String regex = "[a-zA-Z0-9]{1,50}";
        Scanner scanner = new Scanner(System.in);
        while(true) {
            System.out.println("请输入住址，允许是字母/数字，长度1-50");
            String input = scanner.nextLine();
            if (input.matches(regex)) {
                return input;
            } else {
                System.out.println("输入住址错误，请检查");
            }
        }
    }

    public static void main(String[] args) {
        DataValidation dv = new DataValidation();
        System.out.println(dv.menuValidate(1,6));
        System.out.println(dv.nameValidate());
        System.out.println(dv.ageValidate());
        System.out.println(dv.sexValidate());
        System.out.println(dv.telnumValidate());
        System.out.println(dv.addressValidate());
    }
}
