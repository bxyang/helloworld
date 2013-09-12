class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (nRows < 2) {
            return s;
        }
        
        vector<vector<char> > zigzags(nRows, vector<char>());
        int idx = 0;
        bool direction_flag = true;
        for (string::iterator it = s.begin(); it != s.end(); it ++) {
            zigzags[idx].push_back(*it);
            if (direction_flag)
                idx++;
            else
                idx--;
            if (idx == nRows) {
                idx = nRows - 2;
                direction_flag = false;
            }
            
            if (idx == -1) {
                idx = 1;
                direction_flag = true;
            }
        }
        string ret;
        for (int i = 0; i < nRows; i++) {
            for (vector<char>::iterator it = zigzags[i].begin(); 
                it != zigzags[i].end(); it++) {
                ret.push_back(*it);    
            }
        }
        return ret;
    }
};

class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len = s.length();
        string ret(len, '0');
        int p = 0;
        if (nRows == 1)
            return s;
        const int inc = 2*(nRows-1);
        for (int j = 0; j < len; j += inc)
            ret[p++] = s[j];
        for (int i = 1; i < nRows - 1; i++) {
            int offset = 2*(nRows - i - 1);
            int k = i;
            for (; k + offset < len; k += inc) {
                ret[p++] = s[k];
                ret[p++] = s[k+offset];
            }
            if (k < len)
                ret[p++] = s[k];
        }
        for (int j = nRows - 1; j < len; j += inc)
            ret[p++] = s[j];
        return ret;
    }
};
