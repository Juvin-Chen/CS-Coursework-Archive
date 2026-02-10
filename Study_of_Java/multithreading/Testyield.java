/*
"活雷锋"  线程让步
yield()让当前正在运行的线程回到就绪状态，以允许具有相同优先级的其他线程获得运行的机会。因此，使用yield()的目的是让具有相同优先级的线程之间能够适当的轮换执行。但是，实际中无法保证yield()达到让步的目的，因为，让步的线程可能被线程调度程序再次选中。
使用yield方法时要注意的几点：
yield是一个静态的方法。
调用yield后，yield告诉当前线程把运行机会交给具有相同优先级的线程。
yield不能保证，当前线程迅速从运行状态切换到就绪状态。
yield只能是将当前线程从运行状态转换到就绪状态，而不能是等待或者阻塞状态。
 */
public class Testyield implements Runnable{
    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            //getName() 是 Thread 类的实例方法（非静态），只有 Thread 类的对象才能调用。
            //因此不能直接写 getName()，必须先通过 Thread.currentThread() 获取当前线程对象，再调用其 getName() 方法。
            System.out.println("线程" + Thread.currentThread().getName() + "正在运行，i=" + i);
            if (i % 2 == 0) {
                // 当i为偶数时，调用yield方法
                System.out.println(Thread.currentThread().getName() + "让步");
                Thread.yield(); // 让出CPU时间片
            }
        }
    }

    public static void main(String[] args) {
        Testyield runnable = new Testyield();
        Thread thread1 = new Thread(runnable, "线程1");
        Thread thread2 = new Thread(runnable, "线程2");
        //启动线程
        thread1.start();
        thread2.start();

    }
}
