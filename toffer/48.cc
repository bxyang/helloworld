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

template <typename T> class MakeSealed {
	friend T;
 private:
	MakeSealed() {}
	~MakeSealed() {}
};

class SealedClass2: virtual public MakeSealed<SealedClass2> {
 public:
	SealedClass2() {}
	~SealedClass2() {}
};

class Try: public SealedClass2 {
 public:
	Try() {}
	~Try() {}
};
int main() {
	SealedClass2 obj;
    return 0;
}
