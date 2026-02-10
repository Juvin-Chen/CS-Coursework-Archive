/*
继承Thread类实现多线程的步骤：
在Java中负责实现线程功能的类是java.lang.Thread 类。
此种方式的缺点：如果我们的类已经继承了一个类（如小程序必须继承自 Applet 类），则无法再继承 Thread 类。
可以通过创建 Thread的实例来创建新的线程。
每个线程都是通过某个特定的Thread对象所对应的方法run( )来完成其操作的，方法run( )称为线程体。
通过调用Thread类的start()方法来启动一个线程。
 */
public class Testthread extends Thread{
    /*  线程方法，该方法不能直接调用，必须通过start方法来调用
        run方法是线程的入口方法，线程启动后会自动调用该方法
        run方法中可以放置线程要执行的代码
        如果直接调用run方法，那么就只是一个普通方法的调用，并不会开启新的线程
        如果想要开启新的线程，必须调用start方法，start方法会自动  */
    @Override
    public void run() {
        for(int i = 0; i < 10; i++){  //getname()不是静态方法
            System.out.println("线程" + this.getName() + "正在运行，i=" + i);
        }
    }
        //主线程
    public static void main(String[] args) {
        Testthread t1 = new Testthread();
        t1.start();
        Testthread t2 = new Testthread();
        t2.start();
    }
}
