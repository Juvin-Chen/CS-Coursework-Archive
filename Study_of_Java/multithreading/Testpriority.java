class PriorityThread implements Runnable{
    private boolean sign=true;
    private int num=0;
    @Override
    public void run() {
        while (sign){
            //System.out.println(Thread.currentThread().getName()+"正在运行，num="+(++num));
        }
    }
    public void stop(){
        this.sign=false;
    }
}
public class Testpriority {
    public static void main(String[] args) {
        PriorityThread t1=new PriorityThread();
        PriorityThread t2=new PriorityThread();
        Thread thread1=new Thread(t1,"线程1");
        Thread thread2=new Thread(t2,"线程2");
        //一定要在线程启动之前设置优先级
        //优先级的范围是1-10，1最低，10最高，5
        System.out.println(thread1.getPriority()); // 默认优先级是5，会输出5
        thread1.setPriority(Thread.MIN_PRIORITY); // 设置线程1的优先级为最低
        thread2.setPriority(Thread.MAX_PRIORITY); // 设置线程2的优先级为最高
        thread1.start();
        thread2.start();
        try {
            Thread.sleep(1000); // 让主线程休眠1秒钟
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        t1.stop(); // 停止线程的运行
        t2.stop(); // 停止线程的运行
        System.out.println("主线程结束运行");
    }
}
