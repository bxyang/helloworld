
public class ThreadJoinTest implements Runnable{

    private int mVal;
    public static Thread mTh1;
    public static Thread mTh2;
    public ThreadJoinTest(int i) {
        // TODO Auto-generated constructor stub
        mVal = i;
    }

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        mTh1 = new Thread(new ThreadJoinTest(1));
        mTh2 = new Thread(new ThreadJoinTest(2));
        mTh1.start();
        mTh2.start();
    }

    @Override
    public void run() {
        // TODO Auto-generated method stub
        try {
            if (this.mVal == 1)
                mTh2.join();
        } catch (InterruptedException e1) {
            // TODO Auto-generated catch block
            e1.printStackTrace();
        }
        System.out.print("thread " + mVal + "\n");
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        System.out.print("thread " + mVal + "\n");
    }
}
