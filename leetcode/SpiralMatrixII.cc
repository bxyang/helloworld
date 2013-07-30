class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret = vector<vector<int> >(n, vector<int>(n, 1));
        if (n==1)
            return ret;
        generateMatrix(ret, 0, n-1, 0, n-1, 1);
        return ret;
    }
    
    void generateMatrix(vector<vector<int> > &matrix, int start_r, int end_r,
        int start_c, int end_c, int num){
        for (int i = start_c; i <= end_c; i++)
            matrix[start_r][i] = (num++);
        if ((start_r + 1) < end_r){
            for (int i = start_r + 1; i < end_r; i++)
                matrix[i][end_c] = (num++);
        }
        if (start_r < end_r) {
            for (int i = end_c; i >= start_c; i--)
                matrix[end_r][i] = (num++);
        }
        
        if ( ((start_r + 1) < end_r) && ((start_c + 1) < end_r)) {
            for (int i = end_r - 1; i > start_r; i--)
                matrix[i][start_c] = (num++);
            generateMatrix(matrix, start_r + 1, end_r - 1, start_c + 1, end_c - 1, num);
        }
    }
};
