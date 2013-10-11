/*
 * =====================================================================================
 *
 *       Filename:  1-8-Elevator.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/1 15:03:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */



int minStepFloor(int* data, int n) {
    int n1;
    int n2;
    int n3;
    n1 = 0;
    n2 = data[0];
    for (int i = 1; i < n; i++)
        n3 += data[i];
    for (int i = 1; i < n; i++) {
        if (n1 + n2 > n3)
            return i;
        n1 += n2;
        n2 = data[i];
        n3 -= n2;
    }
    return 0;
}


int main() {

    return 0;
}
