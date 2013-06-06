/*
 * =====================================================================================
 *
 *       Filename:  21.cc
 *
 *    Description:  a kind of stack which has min function
 *
 *        Version:  1.0
 *        Created:  06/05/2013 02:56:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<stack>
#include<stdexcept>
#include<cassert>

class CMinStack{
 public:
    CMinStack(){}
    void push(int i) {
        if (m_data.empty()){
            m_data.push(i);
            m_min.push(i);
            return;
        }
        if (i <= m_min.top())
            m_min.push(i);
        m_data.push(i);
    }
    int pop() {
        if (m_data.empty())
            throw std::runtime_error("empty stack");
        int t = m_data.top();
        m_data.pop();
        if (t == m_min.top())
            m_min.pop();
        return t;
    }
    bool empty() {
        return m_data.empty();
    }
    int min() {
        return m_min.top();
    }
 private:
    std::stack<int> m_data;
    std::stack<int> m_min;
};

int main() {
    CMinStack obj;
    assert(obj.empty());
    obj.push(1);
    assert(obj.min() == 1);
    obj.push(2);
    assert(obj.min() == 1);
    obj.push(3);
    assert(obj.min() == 1);
    obj.push(1);
    assert(obj.min() == 1);
    obj.pop();
    assert(obj.min() == 1);
    obj.pop();
    assert(obj.min() == 1);
    obj.push(-1);
    assert(obj.min() == -1);
    return 0;
}
