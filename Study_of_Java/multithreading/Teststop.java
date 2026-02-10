
/*
终止线程我们一般不使用JDK提供的stop()/destroy()方法(它们本身也被JDK废弃了)。通常的做法是提供一个boolean型的终止变量，当这个变量置为false，则终止线程的运行。
 */
import java.io.IOException;

public class Teststop implements Runnable {

    public static void main(String[] args) throws IOException {
        System.out.println("主线程开始运行");
        Teststop teststop = new Teststop();
        Thread thread = new Thread(teststop, "测试线程");
        thread.start(); // 启动线程
        System.in.read();
        teststop.stop(); // 停止线程，不能使用thread.stop()，因为该方法已经被废弃，这个stop方法就是属于Teststop()的对象teststop
        System.out.println("主线程结束运行");
    }

    private boolean running = true; // 用于控制线程的运行状态

    @Override
    public void run() {
        System.out.println("线程开始运行");
        while (running) {
            for (int i = 0; i < 10; i++) {
                // 模拟线程的工作
                System.out.println("线程" + Thread.currentThread().getName() + "正在运行，i=" + i);
            }
            // 这里可以添加其他的业务逻辑代码，例如处理一些数据、执行任务等
            // 模拟线程的工作
            try {
                Thread.sleep(1000); // 让线程休眠1秒钟
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("线程停止运行");
    }

    public void stop() {
        // 停止线程的逻辑
        // 这里可以设置一个标志位来控制线程的停止
        this.running = false;
    }

}
