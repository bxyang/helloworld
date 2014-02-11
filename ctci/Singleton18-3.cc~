/*
 * =====================================================================================
 *
 *       Filename:  Singleton18-3.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/29 16:17:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<cstdlib>
#include<iostream>
using namespace std;


class Lock {
 public:
    Lock(){
        cout << "Singleton constructor is called!" << endl;
    }
    ~Lock() {}
    void acquireLock() {}
    void releaseLock() {}

};
template<class T> class Singleton {
 private:
    static Lock mLock;
    static T* mInstance;
 protected:
    Singleton(){
    }
 public:
    static T* getInstance() {
        if (mInstance != NULL)
            return mInstance;
        mLock.acquireLock();
        if (mInstance == NULL)
            mInstance = new T();
        mLock.releaseLock();
        return mInstance;
    } 
}; 
template<class T>
Lock Singleton<T>::mLock;
template<class T>
T* Singleton<T>::mInstance = NULL;

int main() {
    Singleton<Lock>::getInstance();
    Singleton<Lock>::getInstance();
    return 0;
}
