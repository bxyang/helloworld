/*
 * =====================================================================================
 *
 *       Filename:  SimplifyPath.cc
 *
 *    Description:  
        Given an absolute path for a file (Unix-style), simplify it.

        For example,
        path = "/home/", => "/home"
        path = "/a/./b/../../c/", => "/c"

        Corner Cases:
        Did you consider the case where path = "/../"?
        In this case, you should return "/".
        Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
        In this case, you should ignore redundant slashes and return "/home/foo".
  
 *
 *        Version:  1.0
 *        Created:  2013/7/23 22:06:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<string> st;
        int end = 0;
        int p1 = 0;
        int p2 = 1;
        int n = path.length();
        if (n < 2)
            return "/";
        char c;
        while (p2 < n) {
            c = path[p2];
            if (c != '/') {
                p2++;
            } else {
                if ((p1 + 1) == p2) {
                    ;
                } else {
                    string tmp = path.substr(p1+1, p2 - p1 - 1);
                    if (tmp == ".") {
                       
                    } else if (tmp == "..") {
                        if (! st.empty())
                            st.pop();
                    } else {
                        // in fact, there may exist invalid string here
                        st.push(tmp);
                    }
                }
                p1 = p2;
                p2++;
            }
        }
        
        if (c != '/'){
            string tmp = path.substr(p1+1);
            if (tmp == ".") {
                
            } else if (tmp == "..") {
                if (! st.empty())
                    st.pop();
            } else {
                // in fact, there may exist invalid string here
                st.push(tmp);
            }
        }
        
        string ret ;
        while (! st.empty()){
            ret = "/" + st.top() + ret;
            st.pop();
        }
        if (ret.length() == 0)
            ret = "/";
        return ret;
    }
};

