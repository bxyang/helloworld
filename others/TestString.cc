/*
 * =====================================================================================
 *
 *       Filename:  TestString.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/9 16:27:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


class TestString {
 public:
    TestString():_data(new char[1]) {
        *_data = '\0';
    }
    TestString(const char* str):_data(new char[strlen(str) + 1]) {
        strcpy(_data, str);
    }
    TestString(const TestString& orig):_data(new char[strlen(orig._data) + 1]) {
       strcpy(_data, orig._data);
    }
    TestString& operator=(TestString& rhs) {
       delete []_data;
       _data = new char[strlen(rhs._data)+1];
       strcpy(_data, rhs._data);
       return *this;
    }
    ~TestString() {
        delete []_data;
    }
    const char& operator[](const size_t index) {
        return _data[index];
    }
    char& operator[](const size_t index) {
        return _data[index];
    }
 private:
     char* _data;

};
