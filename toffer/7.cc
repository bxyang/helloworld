/*
 * =====================================================================================
 *
 *       Filename:  7.cc
 *
 *    Description:  implementing Queue by two stacks
 *
 *        Version:  1.0
 *        Created:  05/30/2013 04:13:41 PM
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

class MQueue {
 public:
    MQueue() {}
    void EnQueue(int data) {
        m_stack1.push(data);
    }
    int DelQueue() {
        if (m_stack2.empty()) {
            if (m_stack1.empty())
                throw std::runtime_error("empty queue!");
            while (m_stack1.empty()) {
                m_stack2.push(m_stack1.top());
                m_stack1.pop();
            }
        }
        int ret = m_stack2.top();
        m_stack2.pop();
        return ret;
    }
    bool empty() {
        if (m_stack1.empty() && m_stack2.empty())
            return true;
        return false;
    }
 private:
    std::stack<int> m_stack1;
    std::stack<int> m_stack2;
};

int main() {
    return 0;
}
