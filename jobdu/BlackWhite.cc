/*
 * =====================================================================================
 *
 *       Filename:  BlackWhite.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/10 9:01:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdlib>
#include<cstdio>
#include<queue>

using namespace std;

// 0000 0000 0000 0000 0000

// 0000 0000 0000 0010 0011 0x23
// 0000 0000 0000 0100 0111 0x47
// 0000 0000 0000 1000 1110 0x8E
// 0000 0000 0001 0001 1100 0x11C
// 0000 0000 0010 0001 1000 0x218

// 0000 0000 0100 0110 0001 0x461
// 0000 0000 1000 1110 0010 0x8E2
// 0000 0001 0001 1100 0100 0x11C4
// 0000 0010 0011 1000 1000 0x2388
// 0000 0100 0011 0001 0000 0x4310


// 0000 1000 1100 0010 0000 0x8C20
// 0001 0001 1100 0100 0000 0x11C40
// 0010 0011 1000 1000 0000 0x23880
// 0100 0111 0001 0000 0000 0x47100
// 1000 0110 0010 0000 0000 0x86200


// 0001 1000 0100 0000 0000 0x18400
// 0011 1000 1000 0000 0000 0x38800
// 0111 0001 0000 0000 0000 0x71000
// 1110 0010 0000 0000 0000 0xE2000
// 1100 0100 0000 0000 0000 0xC4000
unsigned int flip_mask[20] = {0x23, 0x47, 0x8E, 0x11C, 0x218,
                              0x461, 0x8E2, 0x11C4, 0x2388, 0x4310,
                              0x8C20, 0x11C40, 0x23880, 0x47100, 0x86200,
                              0x18400, 0x38800, 0x71000, 0xE2000, 0xC4000};

int dp[2100000];

int main() {
    int n;
    scanf("%d\n", &n);
    for (int case_idx = 0; case_idx < n; case_idx++) {
        unsigned int states = 0x0;
        unsigned int p = 0;
        for (int ridx = 0; ridx < 4; ridx++) {
            char rc[10];
            scanf("%s", rc);
            for (int i = 0; i < 5; i++)
                states = states | ((rc[i] - '0') << (p++));
        }
        
        int* pp = dp;
        for (int i = 0; i < 2100000; i++)
           *(pp++) = -1; 
        queue<unsigned int> states_q;
        states_q.push(states);
        dp[states] = 0;
        int m = -1;
        while (true) {
            unsigned int s = states_q.front();
            states_q.pop();
            int l = dp[s];
            for (int i = 0; i < 20; i++) {
                unsigned int t = s ^ flip_mask[i];
                if (dp[t] != -1)
                    continue;
                if (t == 0xFFFFF) {
                    m = l + 1;
                    break;
                } else {
                    dp[t] = l + 1;
                    states_q.push(t);
                }
            }
            if (m != -1)
                break;
        }
        printf("%d\n", m);
    }
}
