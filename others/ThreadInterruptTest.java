


public class ThreadTest implements Runnable{

    private int i;

    public ThreadTest(int v) {
        // TODO Auto-generated constructor stub
        i = v;
    }

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Thread th1 = new Thread(new ThreadTest(1));
        Thread th2 = new Thread(new ThreadTest(2));
        th1.start();
        System.out.print("+:" + th1.isInterrupted());
        th1.interrupt();
        th1.isInterrupted();
        System.out.print("+:" + th1.isInterrupted());
        th2.start();
    }

    @Override
    public void run() {
        // TODO Auto-generated method stub
        System.out.print(i+"\n");


        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            System.out.print("interrupted exception" + i+"\n");
        }

        for (int j = 0; j < 100; j++) {
            System.out.print(i+"thread"+ j + "\n");
            if (Thread.interrupted()){
                System.out.print("interuppted "+ j + "time "+ "thread " + i+"\n");
            }

        }
        System.out.print(i + "\n");
    }

}
