/*
 * =====================================================================================
 *
 *       Filename:  SRM144DIV1.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/2 19:59:43
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
#include<utility>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
class Lottery {
 public:
 	vector<string> sortByOdds(vector<string> rules) {
 		vector<pair<string, unsigned long long>> pp;
 		for (vector<string>::iterator it = rules.begin(); it != rules.end(); it++) {
 			pair<string, unsigned long long> item;
 			getPossibility(*it, item.first, item.second);
 			cout << item.second << endl;
 			pp.push_back(item);
 		}
 		sort(pp.begin(), pp.end(), cmp);
 		vector<string> ret;
 		for (vector<pair<string, unsigned long long>>::iterator it = pp.begin(); it != pp.end(); it++)
 			ret.push_back(it -> first);
 		return ret;
 	}
 	
 	static bool cmp(pair<string, unsigned long long> p1, pair<string, unsigned long long> p2) {
 		if (p1.second < p2.second)
 			return true;
 		else if (p1.second > p2.second)
 			return false;
 		else
 			return p1.first.compare(p2.first) < 0;
 	}
 	void getPossibility(string rule, string &name, unsigned long long &p) {
 			int choice, blank;
 			bool sorted, unique;
 			parseRules(rule, name, choice, blank, sorted, unique);
 			// cout << "p" << choice << " " << blank << endl;
 			if (sorted && unique)
 				p = perm(blank, choice)/factorial(blank);
 			else if (sorted && (!unique)) {
 				vector<vector<unsigned long long> > dp(blank+1, vector<unsigned long long>(choice+1, -1));
 				p = nonDescendingNum(1, 1, blank, choice, dp);
 			} else if ((!sorted) && unique)
 				p = perm(blank, choice);
 			else {
 				//cout << "mpow" << choice << " " << blank << endl;
 				p = mpow(choice, blank);
 			}
 	}
 	
 	unsigned long long mpow(int base, int expo) {
 		if (expo == 1)
 			return base;
 		return mpow(base, expo-1)*base;
 	}
 	unsigned long long nonDescendingNum(int max, int next, int blank, int choice, vector<vector<unsigned long long> > &dp) {
 		if (next > blank)
 			return 1;
 		if (dp[next][max] != -1)
 			return dp[next][max];
 		unsigned long long ret = 0;
 		for (int i = max; i <= choice; i++) {
 			ret += nonDescendingNum(i, next+1, blank, choice, dp);
 		}
 		dp[next][max] = ret;
 		return ret;
 	}
 	unsigned long long perm(int i, int n) {
 		unsigned long long ret = 1;
 		for (int k = n-i+1; k <= n; k++)
 			ret = ret*k;
 		return ret;
 	}
 	unsigned long long factorial(int n) {
 		if (n == 1)
 			return 1;
 		return factorial(n-1)*n;
 	}
 	void parseRules(string rule, string &name, int &choice, int &blank, bool &sorted, bool &unique) {
 		int colonPos = rule.find_first_of(':');
 		name = rule.substr(0, colonPos);
 		istringstream ist( rule.substr(colonPos+1) );
 		ist >> choice;
 		ist >> blank;
 		char c;
 		ist >> c;
 		sorted = (c == 'T'? true:false);
 		ist >> c;
 		unique = (c == 'T'? true:false);
 	}
};
