/*
 * =====================================================================================
 *
 *       Filename:  SRM144DIV2.cc
 *
 *    Description:  time, binary decode, power outage
 *
 *        Version:  1.0
 *        Created:  2013/10/1 9:36:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <string>
using namespace std;

class Time{
 public:
 	string whatTime(int t) {
 		int hs = 60*60;
 		int HMS[3];
 		HMS[0] = t/hs;
 		t = t%hs;
 		HMS[1] = t/60;
 		HMS[2] = t%60;
 		string ret;
 		for (int i = 0; i < 3; i++) {
 			char *tmp = new char[4];
 			sprintf(tmp, "%d:", HMS[i]);
 			ret += tmp;
 		}
 		ret.erase(ret.end()-1);
 		return ret;
 	}
};


#include<vector>
#include<string>
#include<iostream>
using namespace std;

class BinaryCode {
 public:
 	vector<string> decode(string message) {
 		vector<string> ret;
 		ret.push_back(decodeCore(message, 0));
 		ret.push_back(decodeCore(message, 1));
 		return ret;
 	}
 	
 	string decodeCore(string message, int first) {
 		string ret;
 		ret.push_back(first+'0');
 		int n = message.length();
 		int c = message[0] - '0' - first;
 		if ((c != 0) && (c != 1))
 			return "NONE";
 		else
 			ret.push_back(c+'0');
 		int i = 2;
 		for (; i < n-1; i++) {
 			c = message[i-1] + '0' - ret[i-1] - ret[i-2]; 
 			//cout << i << " "<< c << endl;
 			if ((c != 0) && (c != 1))
 				return "NONE";
 			else
 				ret.push_back(c+'0');
 		}
 		c = message[n-1] - ret[n-2];
 		if ((c != 0) && (c != 1))
 			return "NONE";
 		else
 			ret.push_back(c+'0');
 		return ret;
 	}
};

#include<vector>
#include<iostream>
using namespace std;

class PowerOutage {
 public:
 	int estimateTimeOut(vector<int> fromJunction, vector<int> toJunction, vector<int> ductLength) {
 		vector<vector<int> > mat(50, vector<int>(50, 0));
 		int n = fromJunction.size();
 		for (int i = 0; i < n; i++)
 			mat[fromJunction[i]][toJunction[i]] = ductLength[i];
 		vector<vector<int> > dp(50, vector<int>(2, -1));
 		estimateTimeOutCore(mat, dp, false, 0);
 		return dp[0][0];
 	}
 	int estimateTimeOutCore(vector<vector<int> > &mat, vector<vector<int> > &dp, bool isReturn, int next) {
 		if (dp[next][isReturn] != -1)
 			return dp[next][isReturn];
 		vector<int> child;
 		for (int i = 0; i < 50; i++) {
 			if (mat[next][i] != 0)
 				child.push_back(i);
 		}
 		if (child.size() == 0) {
 			dp[next] = vector<int>(2, 0);
 			return 0;
 		}
 		int child_size = child.size();
 		// cout << child_size << endl;
 		int returnSum = 0;
 		for (int i = 0; i < child_size; i++) {
 			dp[child[i]][0] = estimateTimeOutCore(mat, dp, false, child[i]);
 			dp[child[i]][1] = estimateTimeOutCore(mat, dp, true, child[i]);
 			returnSum += (dp[child[i]][1] + 2*mat[next][child[i]]); 
 		}
 		if (isReturn) {
 			dp[next][isReturn] = returnSum;
 		} else {
 			int m = 0x7FFFFFFF;
 			for (int i = 0; i < child_size; i++) {
 				int t = returnSum - dp[child[i]][1] - mat[next][child[i]] + dp[child[i]][0];
 				m = m < t ? m : t;
 			}
 			dp[next][isReturn] = m;
 		}
 		return dp[next][isReturn];
 	}
};

