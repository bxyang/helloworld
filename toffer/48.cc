/*
 * =====================================================================================
 *
 *       Filename:  48.cc
 *
 *    Description:  design class which can not be inherited
 *
 *        Version:  1.0
 *        Created:  06/25/2013 04:38:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */

class SealedClass1 {
 public:
    static SealedClass1* get_instance() {
        return new SealedClass1();
    } 
    static void del_instance(SealedClass1* p_instance) {
        delete p_instance;
    } 
 private:
    SealedClass1() {}
    ~SealedClass1() {}
};


int main() {

    return 0;
}
