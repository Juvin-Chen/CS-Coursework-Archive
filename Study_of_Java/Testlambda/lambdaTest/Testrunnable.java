package lambdaTest;

public class Testrunnable {
    public static void main(String[] args) {
        System.out.println(Thread.currentThread().getName()+"主线程开始");
        Runnable r=()-> {
                for(int i=0;i<10;i++){
                    try {
                        Thread.sleep(100);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                    System.out.println(Thread.currentThread().getName()+"线程在运行"+i);
            }
        };
        new Thread(r,"lambda thread").start();
        System.out.println(Thread.currentThread().getName()+"主线程结束");
    }
}
