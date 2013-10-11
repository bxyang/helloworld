/*
 * =====================================================================================
 *
 *       Filename:  Drop.java
 *
 *    Description:  my anwser to the following questions
 *                  http://docs.oracle.com/javase/tutorial/essential/concurrency/QandE/questions.html 
 *
 *        Version:  1.0
 *        Created:  2013/10/3 12:08:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

// only re-implement the drop class extends from linkedblockingqueue
// http://docs.oracle.com/javase/tutorial/essential/concurrency/examples/Producer.java
// http://docs.oracle.com/javase/tutorial/essential/concurrency/examples/Consumer.java 
// http://docs.oracle.com/javase/tutorial/essential/concurrency/examples/ProducerConsumerExample.java
public class Drop extends LinkedBlockingQueue<String> {
	public void put(String elem) {
		try {
			super.put(elem);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public String take() throws InterruptedException {
		return super.take();
	}
}


