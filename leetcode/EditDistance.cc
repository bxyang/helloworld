/*
 * =====================================================================================
 *
 *       Filename:  EditDistance.cc
 *
 *    Description:  
 
        Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. 
        (each operation is counted as 1 step.)

        You have the following 3 operations permitted on a word:

        a) Insert a character
        b) Delete a character
        c) Replace a character

 *
 *        Version:  1.0
 *        Created:  2013/7/17 19:53:56
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
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int> > dp(n1+1, vector<int>(n2+1, 0));
        for (int i = 0; i <= n2; i++)
            dp[0][i] = i;
        for (int i = 0; i <= n1; i++)
            dp[i][0] = i;
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                int t = min(dp[i-1][j]+1, dp[i][j-1]+1);
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = min(t, dp[i-1][j-1]);
                else
                    dp[i][j] = min(t, dp[i-1][j-1] + 1);
            }
        }
        return dp[n1][n2];
    }
    
    int min(int i1, int i2) {
        return i1 < i2 ? i1 : i2;
    }
};



class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = word1.length();
        int len2 = word2.length();
        vector<vector<int> > min_dist(len1, vector<int>(len2, -1));
        return minDistanceCore(word1, 0, len1, word2, 0, len2, min_dist);
    }
    
    int minDistanceCore(string word1, int start1, int end1, 
        string word2, int start2, int end2, vector<vector<int> >& min_dist) {
        if ((start1 == end1) || (start2 == end2))
            return (end1 - start1) > (end2 - start2) ? (end1 - start1) : (end2 - start2);
        int ret = -1;
        if (min_dist[start1][start2] != -1)
            return min_dist[start1][start2];
        if (word1[start1] == word2[start2]) {
            ret = minDistanceCore(word1, start1 + 1, end1, word2, start2 + 1, end2, min_dist);
        } else {
            int ret1 = minDistanceCore(word1, start1, end1, word2, start2 + 1, end2, min_dist);
            int ret2 = minDistanceCore(word1, start1 + 1, end1, word2, start2, end2, min_dist);
            int ret3 = minDistanceCore(word1, start1 + 1, end1, word2, start2 + 1, end2, min_dist);
            ret = ret1 < ret2 ? ret1 : ret2;
            ret = ret < ret3 ? ret : ret3;
            ret += 1;
        }
        min_dist[start1][start2] = ret;
        return ret;
        
    }
};
