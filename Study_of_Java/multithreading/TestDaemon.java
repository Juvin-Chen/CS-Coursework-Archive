/*
在这几个示例里面只是演示了守护线程的基本用法，实际开发中不建议使用守护线程，因为守护线程的生命周期不受控制，可能会导致一些不可预知的问题。
而且基本上判断谁是谁的守护线程就是在哪个线程里面创建的线程谁就是谁的守护线程。
 */

class Daemon implements Runnable {
    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println("守护线程" + Thread.currentThread().getName() + "正在运行，i=" + i);
            try {
                Thread.sleep(500); // 让线程休眠0.5秒钟
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println(Thread.currentThread().getName() + "运行结束");
    }
}

class User implements Runnable {
    @Override
    public void run() {
        Thread t = new Thread(new Daemon(), "守护线程");
        t.setDaemon(true); // 将它设置为这个user的守护线程
        t.start();
        for (int i = 0; i < 5; i++) {
            System.out.println(Thread.currentThread().getName() + "正在运行，i=" + i);
            try {
                Thread.sleep(1000); // 让线程休眠1秒钟
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("用户线程" + Thread.currentThread().getName() + "运行结束");
    }
}

public class TestDaemon {
    public static void main(String[] args) {
        Thread f = new Thread(new User(), "用户线程");
        f.start();
        try {
            Thread.sleep(4000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        System.out.println("主线程结束运行");
    }
}
