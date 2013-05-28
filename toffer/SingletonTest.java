
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
    private static Object obj = new Object();
    
    public static void main( String args[] ){
        System.out.println("hello world");
        SingletonTest.getInstance();
    }
}

