class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() == 0)
            return 0;
        vector<int> f(s.length(), -1);
        return numDecodingsCore(s, 0, s.length() - 1, f);
    }
    
    int numDecodingsCore(string &s, int start, int end, vector<int>& f){
        if (start > end)
            return 1;
        if (f[start] != -1)
            return f[start];
        if (s[start] == '0')
            return 0;
        if (start == end) {
            return 1;
        }
        int ret = 0;
        ret += numDecodingsCore(s, start + 1, end, f);
        int tmp = atoi(s.substr(start, 2).c_str());
        if (tmp <= 26)
            ret += numDecodingsCore(s, start + 2, end, f);
        f[start] = ret;
        return ret;
    }
};
