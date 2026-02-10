class Mantou {
    int id;

    Mantou(int id) {
        this.id = id;
    }
}

// 缓冲区
class SyncStack {
    int index = 0; // 栈顶指针
    Mantou[] mantous = new Mantou[6]; // 缓冲区大小为6

    // 生产馒头
    public synchronized void push(Mantou m) {
        // 如果缓冲区满了，就等待
        if (index == mantous.length) {
            try {
                this.wait(); // wait()方法会释放锁
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        // 如果没有满，就把馒头放入缓冲区
        mantous[index] = m;
        index++;
        System.out.println("生产了馒头" + m.id);
        this.notify(); // 通知消费者可以消费了
    }

    // 消费馒头
    public synchronized Mantou pop() {
        // 如果缓冲区空了，就等待
        if (index == 0) {
            try {
                this.wait(); // 当前线程由运行状态变为阻塞状态，wait()方法会释放锁，这个是Object类的方法，需要在synchronized同步方法或同步块中使用
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        // 如果没有空，就从缓冲区取出馒头
        index--;
        Mantou m = mantous[index];
        System.out.println("消费了馒头" + m.id);
        this.notify(); // 通知生产者可以生产了
        return m;
    }
}

// 生产者
class Producer implements Runnable {
    SyncStack ss = null;

    Producer(SyncStack ss) {
        this.ss = ss;
    }

    @Override
    public void run() {
        for (int i = 0; i < 20; i++) {
            Mantou m = new Mantou(i);
            ss.push(m);
            try {
                Thread.sleep((int) (Math.random() * 1000)); // 随机休眠0-1秒
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

// 消费者
class Consumer implements Runnable {
    SyncStack ss = null;

    Consumer(SyncStack ss) {
        this.ss = ss;
    }

    @Override
    public void run() {
        for (int i = 0; i < 20; i++) {
            Mantou m = ss.pop();
            try {
                Thread.sleep((int) (Math.random() * 1000)); // 随机休眠0-1秒
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class Testshengchanzhe {
    public static void main(String[] args) {

    }
}
