public class TestThis {
    int a,b,c;
    TestThis(){
        System.out.println("正要初始化对象"+this);//输出为：正要初始化对象TestThis@7dc5e7b4，这个是system定义的一种的输出格式
    }
    TestThis(int a,int b){
        //TestThis() 这样是无法调用构造方法的
        this(); //调用无参的构造方法，必须位于第一行
        this.a=a;
        this.b=b;
    }
    TestThis(int a,int b,int c){
        this(a,b);//必须位于第一行，调用带参的构造方法
        this.c=c;
    }
    void sing(){ }
    void eat(){
        System.out.println("当前对象"+this);
        sing();//加不加sing都可以
        this.sing();//调用本类中的sing()
        System.out.println("你妈妈喊你回家吃饭");
    }
    public static void main(String[] args) {
        TestThis hi=new TestThis(2,3);
        hi.eat();
    }
}
