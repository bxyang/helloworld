/*
 * =====================================================================================
 *
 *       Filename:  sizeof_related.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/9/7 14:37:11
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

class NoVirtual {
    int a;
 public:
    void x() const {}
    int i() const { return 1; }
};

class OneVirtual {
    int a;
 public:
    virtual void x() const {}
    int i() const { return 1; }
};

class TwoVirtuals {
    int a;
 public:
    virtual void x() const {}
    virtual int i() const { return 1; }
};

int main() {
    cout << "void* " << sizeof(void*) << endl;
    cout << "NoVirtual " << sizeof(NoVirtual) << endl;
    cout << "OneVirtual " << sizeof(OneVirtual) << endl;
    cout << "TwoVirtuals " << sizeof(TwoVirtuals) << endl;
    TwoVirtuals obj;
    cout << "TwoVirtuals Object "<< sizeof(obj) << endl;
    char s[] = "hello";
    strcpy(s, "no");
    cout << s << endl;
    cout << "char s[] = \"hello\" " << sizeof(s) << endl;
    return 0;
}
