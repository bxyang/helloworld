class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
            char c = (*it)[0];
            stringstream ss(*it);
            int t;
            if (it -> size() > 1) {
                ss >> t;
                st.push(t);
            } else {
                if ((c == '+') || (c == '-') || (c == '*') || (c == '/')) {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    if (c == '+')
                        st.push(a+b);
                    else if (c == '-')
                        st.push(b-a);
                    else if (c == '*')
                        st.push(a*b);
                    else
                        st.push(b/a);
                } else {
                    ss >> t;
                    st.push(t);
                }
            }
        }
        return st.top();
    }
};
