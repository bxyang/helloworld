class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st;
        for (string::iterator it = s.begin(); it != s.end(); it++) {
            char c = *it;
            if ((c == '(') || (c == '[') || (c == '{')) {
                st.push(c);
                continue;
            }
            char t;
            bool flag = false;
            switch(c){
            case ')':
                t = '(';
                break;
            case ']':
                t = '[';
                break;
            case '}':
                t = '{';
                break;
            default:
                flag = true;
                break;
            }
            if (flag)
                continue;
            if (! st.empty()) {
                if(st.top() == t)
                    st.pop();
                else
                    return false;
            } else {
                return false;
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};
