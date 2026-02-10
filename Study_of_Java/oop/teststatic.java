public class teststatic {
    static String company;
    static{
        System.out.println("执行类的初始化工作");
        company="baizhan";
        print();
    }
    public static void print(){
       System.out.println(company);
    }

    public static void main(String[] args) {
        //main方法里面虽然没代码，但是会有类被加载时需要执行的代码
    }
}
