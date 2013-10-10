/*
 * =====================================================================================
 *
 *       Filename:  SRM145DIV2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/2 16:33:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */


#include<string>
#include<vector>
using namespace std;

class ImageDithering {
 public:
 	int count(string dithered, vector<string> screen){
 		bool dithered_table[26] = {false};
 		for (string::iterator it = dithered.begin(); it != dithered.end(); it++)
 			dithered_table[*it-'A'] = true;
 		int cnt = 0;
 		for (vector<string>::iterator it = screen.begin(); it != screen.end(); it++) {
 			for (string::iterator c = it -> begin(); c != it -> end(); c++)
 				cnt += dithered_table[*c - 'A'];
 		}
 		return cnt;
 	}
};

#include<string>
#include <sstream>
using namespace std;
class ExerciseMachine {
 public:
 	int getPercentages(string time) {
 		int seconds = 0;
 		int t;
 		t = atoi(time.substr(0, 2).c_str());
 		seconds += (t*3600);
 		t = atoi(time.substr(3, 2).c_str());
 		seconds += (t*60);
 		t = atoi(time.substr(6, 2).c_str());
 		seconds += t;
 		return gcd(seconds, 100) - 1;
 	}
 	int gcd(int x, int y) {
 		if (x < y)
 			return gcd(y, x);
 		if (y == 0)
 			return x;
 		return gcd(x-y, y);
 	}
};


#include<vector>
#include<cmath>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;

class VendingMachine {
 public:
	int motorUse(vector<string> prices, vector<string> purchases) {
		vector<vector<int> > pri(prices.size());
		parsePrices(prices, pri);
		int runSeconds = 0;
		int lastCol = mostExpensiveCol(pri, 0);
		int lastTime = 0;
		runSeconds += rotateCost(0, lastCol, pri[0].size());
		for (vector<string>::iterator it = purchases.begin(); it != purchases.end(); it++) {
			int shelf, col, time;
			parseBuyRecord(*it, shelf, col, time);
			if (pri[shelf][col] == 0)
				return -1;
			if (time - lastTime >= 5) {
				int nextCol = mostExpensiveCol(pri, lastCol);
				runSeconds += rotateCost(lastCol, nextCol, pri[0].size());
				lastCol = nextCol;		
			}
			runSeconds += rotateCost(lastCol, col, pri[0].size());
			lastCol = col;
			pri[shelf][col] = 0;
			lastTime = time;
		}
		int nextCol = mostExpensiveCol(pri, lastCol);
		runSeconds += rotateCost(lastCol, nextCol, pri[0].size());
		return runSeconds;		
	}
	void parseBuyRecord(string str, int &shelf, int &col, int &time) {
		int commaPos = str.find_first_of(',');
		shelf = atoi((str.substr(0, commaPos)).c_str() );
		int  colonPos = str.find_first_of(':');
		col = atoi( (str.substr(commaPos+1, colonPos - commaPos - 1)).c_str() );
		time = atoi( (str.substr(colonPos+1)).c_str() );
	}
	void parsePrices(vector<string> &prices, vector<vector<int> > &pri) {
		int i = 0;
		for(vector<string>::iterator it = prices.begin(); it != prices.end(); it++, i++){
			istringstream ss(*it);
			while(!ss.eof()) {
				int p;
				ss >> p;
				pri[i].push_back(p);
			}
		}
	}
	
	int rotateCost(int i, int j, int col_num) {
		int cost[2];
		cost[0] = abs(i-j);
		cost[1] = col_num - cost[0];
		return cost[0] < cost[1] ? cost[0] : cost[1];
	}
	int mostExpensiveCol(vector<vector<int> > &pri, int last_col) {
		int colNum = pri[0].size();
		int maxPrice = 0;
		int rotateCost = pri[0].size();
		int retCol = 0;
		
		for (int i = 0 ; i < colNum; i++) {
			int sumPrice = 0;
			for (int s = 0; s < pri.size(); s++)
				sumPrice += pri[s][i];
			if (sumPrice > maxPrice) {
				maxPrice = sumPrice;
				retCol = i;
				int cost[2];
				cost[0] = abs(i-last_col);
				cost[1] = colNum - cost[0];
				rotateCost =  cost[0] < cost[1] ? cost[0] : cost[1];
			} 
			/*
			else if (sumPrice == maxPrice) {
				int cost[2];
				cost[0] = abs(i-last_col);
				cost[1] = colNum - cost[0];
				int tmp =  cost[0] < cost[1] ? cost[0] : cost[1];
				if (tmp < rotateCost) {
					rotateCost = tmp;
					retCol = i;
				}
			}
			*/
		}
		return retCol;
	}
};
