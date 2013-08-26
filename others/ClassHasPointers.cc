/*
 * =====================================================================================
 *
 *       Filename:  ClassHasPointers.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/25/2013 11:33:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */



#include<iostream>
#include<cstdlib>

using namespace std;


/*

class HasPtr {
 public:
    HasPtr(int* p, int i): ptr(p), val(i) {}
    int *get_ptr() const { return ptr; }
    int get_int() const { return val; }
    
    void set_ptr(int* p) { ptr = p; }
    void set_int(int i) { val = i; }
    
    int get_ptr_val() const { return *ptr; }
    void set_ptr_val(int val) { *ptr = val; }

 private:
    int* ptr;
    int val;

};
*/

class U_Ptr {
    friend class HasPtr;
    int* ip;
    size_t use;
    U_Ptr(int* p): ip(p), use(1) {}
    ~U_Ptr() { delete ip; }
};

class HasPtr {
 public:
    HasPtr(int* p, int i): ptr(new U_Ptr(p)), val(i) { }
    HasPtr(const HasPtr &orig): ptr(orig.ptr), val(orig.val) { ++(ptr -> use); }
    HasPtr& operator=(const HasPtr &rhs) {
        ++(rhs.ptr -> use);
        (ptr -> use) --;
        if (ptr -> use == 0)
            delete ptr;
        ptr = rhs.ptr;
        val = rhs.val;
        return *this;
    }
    ~HasPtr() {
        cout << "~HasPtr Called" << endl;
        if (--(ptr->use) == 0) delete ptr; 
    }
    int *get_ptr() const { return ptr->ip; }
    int get_int() const { return val; }
    
    void set_ptr(int* p) { ptr -> ip = p; }
    void set_int(int i) { val = i; }
    
    int get_ptr_val() const { return *(ptr -> ip); }
    void set_ptr_val(int val) { *(ptr -> ip)= val; }
 private:
    U_Ptr *ptr;
    int val;
};


int main() {
    // dangling pointers
    int* ip = new int(42);
    {
        HasPtr ptr(ip, 10);
    }
    delete ip;
    return 0;
}
