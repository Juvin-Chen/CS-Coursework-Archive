/*
爸爸让儿子去买烟案例
这个案例相对前面来讲的区别就是它直接将另一个线程的创建放在了run方法中，从而不需要在main中创建又需要在类中写一个方法再进行传递，主要是看事情的逻辑方式判断使用哪种join方式
 */

class father implements Runnable {
    @Override
    public void run() {
        System.out.println("lack smoke");
        Thread t = new Thread(new son());
        t.start();
        try {
            t.join(); // 等待儿子买烟回来
        } catch (InterruptedException e) {
            e.printStackTrace();
            System.out.println("儿子买烟的路上发生了意外");
            System.out.println("father go to find the son");
            System.exit(1);
        }
        System.out.println("son buy the smoke back successfully");
    }
}

class son implements Runnable {
    @Override
    public void run() {
        System.out.println("go to buy smoke");
        for (int i = 0; i < 10; i++) {
            System.out.println("第" + i + "分钟");
            try {
                Thread.sleep(5000); // 模拟买烟的时间
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class Testjoin2 {
    public static void main(String[] args) {
        System.out.println("father start to smoke");
        Thread t = new Thread(new father());
        t.start();
    }
}
