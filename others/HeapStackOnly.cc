/*
 * =====================================================================================
 *
 *       Filename:  HeapStackOnly.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/23 16:00:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<iostream>

using namespace std;

class HeapOnly  { 
 public:
    HeapOnly() {   
        cout<<"constructor. "<<endl;   
    } 
    void destroy() {   
        delete this;   
    } 
 private: 
    ~HeapOnly(){}
};

class StackOnly {
 public:
     StackOnly() {
        cout<<"constructor. "<<endl;   
     }
     ~StackOnly() {
        cout<<"destructor. "<<endl;   
     }
 private:
     void* operator new(size_t size);
};
 
int main() 
{ 
    StackOnly* p = new StackOnly();
    HeapOnly obj;
    return 0; 
}
