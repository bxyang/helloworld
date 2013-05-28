
public class SingletonTest {
    private SingletonTest() {
        
    }
    public static SingletonTest getInstance() {
        return mInstance;
    }
    static {
        mInstance = new SingletonTest();
    }
    private static SingletonTest mInstance;
    
    public static void main( String args[] ){
        System.out.println("hello world");
        SingletonTest.getInstance();
    }
}

public class SingletonTestB {

    private SingletonTestB {

    }
    
    public static getInstance() {
        if (mInstance == null) {
            synchronized(obj) {
                if (mInstance == null)
                    mInstance = new SingletonTestB();
            }
        }   
    }
    
    private static SingletonTestB mInstance;
    private static Object obj = new Object();
}

