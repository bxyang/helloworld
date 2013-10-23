/*
 * =====================================================================================
 *
 *       Filename:  GasStation.cc
 *
 *    Description: 
        There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

        You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). 
        You begin the journey with an empty tank at one of the gas stations.

        Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

        Note:
        The solution is guaranteed to be unique.
 *
 *
 *        Version:  1.0
 *        Created:  2013/10/23 11:20:39
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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = gas.size();
        int head = 0;
        int tail = 0;
        int accu = 0;
        do {
            if (accu + gas[tail] - cost[tail] >= 0) {
                accu += (gas[tail] - cost[tail]);
                tail = (tail + 1) % n;
            } else {
                head = (head - 1 + n ) % n;
                accu +=(gas[head] - cost[head]);
            }
        } while (head != tail);
        
        if (accu >= 0)
            return head;
        return -1;
    }
};
