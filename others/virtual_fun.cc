/*
 * =====================================================================================
 *
 *       Filename:  virtual_fun.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/7 21:17:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<iostream>
using namespace std;

class Base {
 public:
     Base() {
        cout << "base ctor" << endl;
        foo();
     }

     virtual ~Base() {
        cout << "base dtor" << endl;
        foo();
     }
     virtual void foo() {
        cout << "base foo" << endl;
     }
};

class Derived: public Base {
 public:
     Derived() {
        cout << "derived ctor" << endl;
        foo();
     }
     
     ~Derived() {
        cout << "derived dtor" << endl;
        foo();
     }
     
     virtual void foo() {
        cout << "derived foo" << endl;
     }
};

int main() {
    Base* p = new Derived();
    delete p;
    cout << endl;
    return 0;
}
