/*
 * =====================================================================================
 *
 *       Filename:  1.cc
 *
 *    Description:  assignment operator
 *
 *        Version:  1.0
 *        Created:  05/28/2013 10:22:18 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstring>
#include<cstdio>
class CMyStr{
 public:
    CMyStr(char* p);
    ~CMyStr();
    CMyStr(const CMyStr& obj);
    CMyStr& operator=(const CMyStr& rhs);
    void print();
 private:
    char* data;
};

CMyStr::CMyStr(char* p) {
    data = new char[strlen(p) + 1];
    strcpy(data, p);
}
CMyStr::~CMyStr() {
    delete []data;
    data = NULL;
}
CMyStr::CMyStr(const CMyStr& obj) {
    data = new char[strlen(obj.data) + 1];
    strcpy(data, obj.data);
}
/*
CMyStr& CMyStr::operator=(const CMyStr& rhs) {
    if(this == &rhs)
        return *this;
    delete []data;
    data = new char[strlen(rhs.data) + 1];
    strcpy(data, rhs.data);
    return *this;
}
*/

CMyStr& CMyStr::operator=(const CMyStr& rhs) {
    if(this == &rhs)
        return *this;
    CMyStr strTemp(rhs);
    char* pTemp = strTemp.data;
    strTemp.data = data;
    data = pTemp;
    return *this;
}
void CMyStr::print() {
    printf("%s\n", data);
}

int main() {
    CMyStr str1("hello");
    CMyStr str2("world");
    CMyStr str3("helloworld");
    str2 = str1;
    str1 = str2 = str3;
    str1.print();
    str2.print();
    str3.print();
    return 0;
}
