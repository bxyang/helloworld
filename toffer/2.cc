/*
 * =====================================================================================
 *
 *       Filename:  2.cc
 *
 *    Description:  Singleton
 *
 *        Version:  1.0
 *        Created:  05/28/2013 01:59:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdlib>
#include<pthread.h>

class SingletonA {
 public:
    static SingletonA* getInstance();
 private:
    SingletonA();
    static SingletonA* m_instance;
};
SingletonA* SingletonA::m_instance;
SingletonA::SingletonA() {

}
SingletonA* SingletonA::getInstance() {
    if (m_instance == NULL)
        m_instance = new SingletonA();
    return m_instance;
}

class SingletonAGC {
 private:
    static SingletonAGC gc_obj;
    ~SingletonAGC() {
        SingletonA* m_instance = SingletonA::getInstance();
        if (m_instance != NULL)
            delete m_instance;
    }
};



class SingletonB {
 public:
    static SingletonB& getInstance();
 private:
    SingletonB();
    SingletonB(const SingletonB& );
    SingletonB& operator=(const SingletonB& );
};
SingletonB::SingletonB() {
}
SingletonB& SingletonB::getInstance() {
    static SingletonB m_instance;
    return m_instance;
}

class SingletonC {
 public:
    static SingletonC* getInstance();
    static void delInstance();
 private:
    SingletonC();
    static pthread_mutex_t m_mutex;
    static SingletonC* m_instance;
};
SingletonC* SingletonC::m_instance;
pthread_mutex_t SingletonC::m_mutex = PTHREAD_MUTEX_INITIALIZER;
SingletonC::SingletonC() {

}
SingletonC* SingletonC::getInstance() {
    if (m_instance == NULL)
    {
        pthread_mutex_lock(&m_mutex);
        if (m_instance == NULL)
            m_instance = new SingletonC();
        pthread_mutex_unlock(&m_mutex);
    }
    return m_instance;
}
void SingletonC::delInstance() {
    if (m_instance != NULL)
    {
        pthread_mutex_lock(&m_mutex);
        if (m_instance != NULL)
            delete m_instance;
        pthread_mutex_unlock(&m_mutex);
    }


}
int main() {

    return 0;
}
