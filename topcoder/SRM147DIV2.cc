/*
 * =====================================================================================
 *
 *       Filename:  SRM147DIV2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/11/1 14:13:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<string>
using namespace std;

/*
 * f(n, 0, j) = j;
 * f(n, i+1, j) = (f(n, i, j) + k - 1) % (n - i) + 1;
 */

class PeopleCircle {
 public:
 	string order(int numMales, int numFemales, int K) {
 		int n = numMales + numFemales;
 		string ret(n, 'M');
 		int last = K;
 		for (int i = 1; i < numFemales; i++) {
 			ret[last-1] = 'F';
 			last = (last + K - 1)%(n-i) + 1;
 		}
 		ret[last-1] = 'F';
 		return ret;
 	}
};

