class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > f(n, vector<string>());
        return generateParenthesis(n, f);
    }
    
    vector<string> generateParenthesis(int n, vector<vector<string> > &f) {
        vector<string> ret;
        if (n==0)
            return ret;
        if (n==1){
            ret.push_back("()");
            return ret;
        }
        if (f[n-1].size() != 0){
            return f[n-1];
        }
        vector<string> tmp1 = generateParenthesis(n-1);
        for(vector<string>::iterator it1 = tmp1.begin(); 
                it1 != tmp1.end(); it1++) {
            ret.push_back("()" + (*it1));
        }
        for (int i = 1; i <= (n-1); i++){
            vector<string> tmp1 = generateParenthesis(i);
            for(vector<string>::iterator it1 = tmp1.begin(); 
                it1 != tmp1.end(); it1++) {
                (*it1) = "(" + (*it1) + ")";
            }
            vector<string> tmp2 = generateParenthesis(n-i-1);
            if (tmp2.size() == 0) {
                for(vector<string>::iterator it1 = tmp1.begin(); 
                    it1 != tmp1.end(); it1++) {
                    ret.push_back(*it1);
                }
                continue;
            }
            for(vector<string>::iterator it2 = tmp2.begin(); 
                it2 != tmp2.end(); it2++) {
                for(vector<string>::iterator it1 = tmp1.begin(); 
                    it1 != tmp1.end(); it1++) {
                    ret.push_back((*it1) + (*it2) );
                }
            }
        }
        f[n-1] = ret;
        return ret;
    
    }
    
    
};
