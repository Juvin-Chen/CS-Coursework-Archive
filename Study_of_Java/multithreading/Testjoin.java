/*
当前线程邀请调用方法的线程优先执行，在调用方法的线程执行结束之前，当前线程不能再次执行。线程A在运行期间，可以调用线程B的join()方法，让线程B和线程A联合。这样，线程A就必须等待线程B执行完毕后，才能继续执行。
join方法的使用
join()方法就是指调用该方法的线程在执行完run()方法后，再执行join方法后面的代码，即将两个线程合并，用于实现同步控制。
 */
//如果想在A B两个线程进行join操作，就需要在一个类中添加构造方法
class A implements Runnable {
    private Thread b;

    public A(Thread b) {
        this.b = b;
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println("线程" + Thread.currentThread().getName() + "正在运行，i=" + i);
            if (i == 5) {
                try {
                    this.b.join(); // 让当前线程等待b线程执行完毕后再继续执行
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            try {
                Thread.sleep(500); // 让线程休眠0.5秒钟
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class B implements Runnable {
    @Override
    public void run() {
        for (int i = 0; i < 20; i++) {
            System.out.println("线程" + Thread.currentThread().getName() + "正在运行，i=" + i);
            try { // 这个可以帮助我们在运行代码的时候更好地帮助我们看见变化，因为这个速度是比较缓慢的
                Thread.sleep(500); // 让线程休眠0.5秒钟
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class Testjoin {
    public static void main(String[] args) {
        Thread t2 = new Thread(new B());
        Thread t = new Thread(new A(t2));
        t2.start();
        t.start();
        // 这段代码没有体现主线程的执行
        try { // 课程代码中使用了一个for循环 是等i=2时才发生join操作 这里我直接在主线程中使用join操作
            t.join(); // 主线程等待t线程执行完毕后再继续执行,此时出现的情况应该是t2线程和t线程交替运行
            // t2.join(); // 主线程等待t2线程执行完毕后再继续执行,此时出现的情况应该是t线程运行完毕后t2线程才开始运行
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        // 等t线程执行结束之后可能出现的情况是t2线程还没有执行完毕，主线程和t2线程一起执行
        System.out.println("主线程结束运行");
    }
}
