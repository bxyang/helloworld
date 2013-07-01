class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret = "";
        int a_index = a.size() - 1;
        int b_index = b.size() - 1;
        int c = 0;
        while ((a_index > -1) && (b_index > -1)) {
            int ac = (int)(a[a_index--]) - (int)'0';
            int bc = (int)(b[b_index--]) - (int)'0';
            int s = ac + bc + c;
            toBinary(s, ret, c);
        }
        if (a_index == b_index) {
            if (c == 1)
                ret = "1" + ret;
        } else {
            if (a_index > b_index){
                addCarry(a, ret, a_index, c);
            } else {
                addCarry(b, ret, b_index, c);
            }
        }
        return ret;
    }
    
    void toBinary(int s, string& ret, int& c){
        switch(s){
        case 0:
            c = 0;
            ret = "0" + ret; 
            break;
        case 1:
            c = 0;
            ret = "1" + ret; 
            break;
        case 2:
            c = 1;
            ret = "0" + ret;
            break;
        case 3:
            c = 1;
            ret = "1" + ret;
            break;
        }
    }
    
    void addCarry(string a, string& ret, int a_index, int c) {
        while ((a_index > -1) && (c != 0)){
            int ac = (int)(a[a_index--]) - (int)'0';
            int s = ac + c;
            toBinary(s, ret, c);
        }
        if (a_index != -1) {
            ret = a.substr(0, a_index + 1) + ret;
        } else {
            if (c == 1)
                ret = "1" + ret;
        }
    }
};
