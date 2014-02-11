/*
 * =====================================================================================
 *
 *       Filename:  ClassConstructor.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/12 15:52:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
using namespace std;

/* 
class A {
 public:
    A() {
        i = 0;
        cout << "A() is called" << endl;
    }
    A(const A& a) {
        i = 1;
        cout << "A(const A& a) is called" << endl;
    }
    ~A() {
        cout << "~A() is called" << endl;
    }
    int i;
};
*/

class A {
 public:
	~A();
};
A::~A() {
	printf("delete A ");
}

class B : public A {
 public:
	~B();
};
B::~B() {
	printf("delete B ");
}

int main() {
    //A* pa = new A[10];
    //delete pa;
    //A ar[5];

    /* 
    vector<A> va(5);
    cout << va[0].i << endl;
    */
    A* pa = new B();
    delete pa;
    return 0;
}
