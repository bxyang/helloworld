/*
 * =====================================================================================
 *
 *       Filename:  AmazonOnline.cc
 *
 *    Description:  Amazon online test 9.24
 *
 *
 *        Version:  1.0
 *        Created:  2013/9/24 12:28:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

string clockwise(int size) {
    vector<vector<int> > data(size, vector<int>(size, 1));
    int num = size * size;
    int r = 0;
    int c = size - 1;
    char direction = 'l';
    // left , right, up, down
    int bound[4] = {0, size-1, 1, size-1};
    while (num > 1) {
        data[r][c] = num;
        num--;    
        switch(direction) {
        case 'l':
            if (c == bound[0]) {
                r = r + 1;
                direction = 'd';
            } else
                c--;
            break;
        case 'r':
            if (c == bound[1]){
                r = r - 1;
                direction = 'u';
            } else
                c++;
            break;
        case 'd':
            if (r == bound[3]) {
                c = c + 1;
                direction = 'r';
            } else
                r = r + 1;
            break;
        case 'u':
            if (r == bound[2]) {
                bound[0] ++;
                bound[1] --;
                bound[2] ++;
                bound[3] --;
                c = c -1;
                direction = 'l';
            } else
                r = r -1;
            break;
        }
    }
    string ret;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            char tmp[50];
            sprintf(tmp, "%d*", data[i][j]);
            ret += tmp; 
        }
        char tmp[50];
        sprintf(tmp, "%d\n", data[i][size-1]);
        ret += tmp;
    }
    return ret;
}

void split(string &s1, vector<string> &sub1);
int differ(string string1, string string2) {
    vector<string> sub1;
    vector<string> sub2;
    
    split(string1, sub1);
    split(string2, sub2);
    
    int m = sub1.size();
    int n = sub2.size();
    vector<vector<int> > dp = vector<vector<int> >(m+1, vector<int>(n+1, 0));
    
    for (int i = 1; i <= n; i++)
        dp[0][i] = i;
    for (int i = 1; i <= m; i++)
        dp[i][0] = i;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (sub1[i-1] == sub2[j-1]) {
                int t = dp[i-1][j-1];
                t = (t < (dp[i-1][j] + 1) ? t : (dp[i-1][j]+1));
                t = (t < (dp[i][j-1] + 1) ? t : (dp[i][j-1] + 1));
                dp[i][j] = t;
            } else {
                int t = (dp[i][j-1] + 1);
                t = (t < (dp[i-1][j] + 1) ? t : (dp[i-1][j]+1));
                t = (t < (dp[i-1][j-1] + 1) ? t : (dp[i-1][j-1]+1) );
                dp[i][j] = t;
            }
        }
    }
    return dp[m][n];
}

void split(string &s1, vector<string> &sub1) {
    istringstream istr(s1);
    while (istr) {
        string t;
        istr >> t;
        sub1.push_back(t);
    }
}
