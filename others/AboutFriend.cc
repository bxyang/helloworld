/*
 * =====================================================================================
 *
 *       Filename:  AboutFriend.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/24/2013 07:44:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include<cstdlib>
#include<iostream>

using namespace std;

class ChildClass;
class FriendClass;

class ParentClass{
    friend class FriendClass;
 private:
    virtual void print() {
        cout << "ParentClass" << endl;
    }
};


class FriendClass{
 public:
    void print(ParentClass pobj) {
        pobj.print();
    }

    void print(ChildClass cobj) {
        //cobj.print();
    }
    
    void print(ParentClass* p) {
        p -> print();
    }
};

class ChildClass: public ParentClass{
 private:
    virtual void print() {
        cout << "ChildClass" << endl;
    }
};

int main() {
    FriendClass fobj;
    ParentClass pobj;
    ChildClass cobj;
    fobj.print(pobj);
    fobj.print(&cobj);
    return 0;
}

