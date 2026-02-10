/*
sleep()方法：可以让正在运行的线程进入阻塞状态，直到休眠时间满了，进入就绪状态。sleep方法的参数为休眠的毫秒数。
 */
public class Testsleep implements Runnable {
    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName() + "线程开始运行");
        for (int i = 0; i < 10; i++) {
            // 模拟线程的工作
            System.out.println("线程" + Thread.currentThread().getName() + "正在运行，i=" + i);
            try { // sleep：静态方法
                Thread.sleep(1000); // 让线程休眠1秒钟
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("主线程开始运行");
        // 包装成线程对象
        Testsleep runnable = new Testsleep();
        Thread thread1 = new Thread(runnable, "线程1");
        thread1.start();
        System.out.println("主线程结束运行");
    }

}
