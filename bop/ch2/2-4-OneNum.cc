/*
 * =====================================================================================
 *
 *       Filename:  2-4-OneNum.cc
 *
 *    Description:  get one number from 1 to n
 *
 *        Version:  1.0
 *        Created:  06/27/2013 11:14:04 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com 
 *   Organization:  ict
 *
 * =====================================================================================
 */


unsigned int get_one_num(unsigned int n) {
    unsigned int count = 0;
    unsigned int factor = 1;
    while (n / factor) {
        unsigned int high = n / (factor * 10) ;
        unsigned int low = n % (factor * 10); 
        unsigned int digit = low / factor;
        low = low % factor;
        switch(digit) {
        case 0:
            count += (high * factor);
            break;
        case 1:
            count += ((high * factor) + low + 1);
            break;
        default:
            count += ((high + 1)* factor);
        }
        factor = factor * 10;
    }
}

int main() {

    return 0;
}
