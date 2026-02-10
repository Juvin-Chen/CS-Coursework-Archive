/*
通过Runnable接口实现多线程
在开发中，我们应用更多的是通过Runnable接口实现多线程。这种方式克服了继承Thread类的缺点，即在实现Runnable接口的同时还可以继承某个类。
从源码角度看，Thread类也是实现了Runnable接口。Runnable接口的源码如下：
public interface Runnable {
   void run();
}
两种方式比较看，实现Runnable接口的方式要通用一些。
 */
public class Testrunnable implements Runnable{
    public static void main(String[] args) {
        //包装成线程对象
        Testrunnable runnable = new Testrunnable();
        Thread thread1 = new Thread(runnable, "线程1");
        Thread thread2 = new Thread(runnable, "线程2");
        //启动线程
        thread1.start();
        thread2.start();
        System.out.println(thread1.getName()); //可以大概理解为包装成了一个thread对象,所以可以直接调用getname这个方法
        //主线程
        for (int i = 0; i < 10; i++) {
            //getName()不是静态方法
            System.out.println("主线程" + Thread.currentThread().getName() + "正在运行，i=" + i);
        }
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            /* getName() 是 Thread 类的实例方法（非静态），只有 Thread 类的对象才能调用。这里的this指向的是实现Runnable接口的对象，而不是Thread对象。
            因此不能直接写 getName()，必须先通过 Thread.currentThread() 获取当前线程对象，再调用其 getName() 方法。*/
            System.out.println("线程" + Thread.currentThread().getName() + "正在运行，i=" + i);
        }
    }
}
