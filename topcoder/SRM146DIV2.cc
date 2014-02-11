/*
 * =====================================================================================
 *
 *       Filename:  SRM146DIV2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/28 15:49:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */




#include<vector>
using namespace std;
class YahtzeeScore {
 public:
 	int maxPoints(vector<int> toss) {
 		int faces[6] = {0};
 		for (vector<int>::iterator it = toss.begin(); it != toss.end(); it++) {
 			faces[*it-1]++;
 		}
 		int maxRet = 0;
 		for (int i = 0; i < 6; i++) {
 			int t = (i+1)*faces[i];
 			maxRet = (t > maxRet ? t : maxRet);
 		}
 		return maxRet;
 	}	
};


#include<vector>
using namespace std;
class RectangularGrid {
 public:
 	long long countRectangles(int width, int height){
 		vector<vector<long long> > dp(width+1, vector<long long>(height+1, 0));
 		for (int i = 1; i <= width; i++)
 			dp[i][1] = dp[i-1][1] + i - 1;
 		for (int i = 1; i <= width; i++) {
 			for (int j = 2; j <= height; j++)
 				dp[i][j] = 2*dp[i][j-1] - dp[i][j-2] + (i+1)*i/2 - (i>=j ? (i-(j-1)) : 0);
 		}
 		return dp[width][height];
 	}

};



#include<vector>
using namespace std;

class BridgeCrossing {
 public:
 	int minTime(vector<int> times) {
 		vector<int> left_times;
 		int minCost = 0x7FFFFFFF;
 		minTime(left_times, times, 0, minCost);
 		return minCost; 	
 	}
 	
 	void minTime(vector<int> &left_times, const vector<int> &right_times, int cur, int& minCost) {
 		int n = right_times.size();
 		if ((n==1) || (n==2)) {
 			cur += (n == 1 ? right_times[0] : max(right_times[0], right_times[1]));
 			minCost = (cur < minCost ? cur : minCost);
 			return;
 		}
 		for (int i = 0; i < (n-1); i++) {
 			for (int j = i+1; j < n; j++) {
 			 	vector<int> next_right;
 			 	copy_except(right_times, next_right, i, j);
 			 	left_times.push_back(right_times[i]);
 			 	left_times.push_back(right_times[j]);
 			 	for (int k = 0; k < left_times.size(); k++) {
 			 		vector<int> next_left;
 			 		copy_except(left_times, next_left, k, -1);
 			 		next_right.push_back(left_times[k]);
 			 		int t = max(right_times[i], right_times[j]) + left_times[k];
 			 		minTime(next_left, next_right, cur + t, minCost);
 			 		next_right.pop_back();
 			 	}
 			 	left_times.pop_back();
 			 	left_times.pop_back();			
 			}
 		}
 	}
 	
 	void copy_except(const vector<int> &v1, vector<int> &v2, const int i1, const int i2){
 		for (int i = 0; i < v1.size(); i++) {
 			if ((i != i1) && (i != i2))
 				v2.push_back(v1[i]);
 		}
 	}
};

