/*
 * =====================================================================================
 *
 *       Filename:  ga.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/10/12 9:11:24
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
#include<string.h>
#include<list>
#include<iterator>
#include<vector>
using namespace std;



int main() {
    int caseNum;
    FILE* fin = fopen("A-large.in", "r");
    FILE* fout = fopen("A-large.out", "w");
    fscanf(fin, "%d", &caseNum);
    for (int idx = 1; idx <= caseNum; idx++) {
        int n;
        fscanf(fin, "%d", &n);
        int ns = n*n;
        vector<vector<int> > board(ns, vector<int>(ns, 0));
        for (int r = 0; r < ns; r++) {
            for (int c = 0; c < ns; c++) {
                int t;
                fscanf(fin, "%d", &t);   
                board[r][c] = t;
            }
        }
        
        int ret = 1;

        for (int i = 0; i < ns; i++) {
            vector<bool> flags(ns+1, false);
            for (int j = 0; j < ns; j++) {
                int c = board[i][j];
                if ((c > 0) && (c <= ns)) {
                    if(flags[c]) {
                        ret = 0;
                        break;
                    } else
                        flags[c] = true;
                } else {
                    ret = 0;
                    break;
                }
            }
            if (ret == 0)
                break;       
        }
        
        if (ret == 1) {
            for (int i = 0; i < ns; i++) {
                vector<bool> flags(ns+1, false);
                for (int j = 0; j < ns; j++) {
                    int c = board[j][i];
                    if ((c > 0) && (c <= ns)) {
                        if(flags[c]) {
                            ret = 0;
                            break;
                        } else
                            flags[c] = true;
                    } else {
                        ret = 0;
                        break;
                    }
                }
                if (ret == 0)
                    break;       
            }
        }
        
        if (ret == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    vector<bool> flags(ns, false);
                    for (int k = n*i; k < n*(i+1); k++) {
                        for (int l = n*j; l < n*(j+1); l++) {
                            int c = board[k][l];
                            if ((c > 0) && (c <= ns)) {
                                if(flags[c]) {
                                    ret = 0;
                                    break;
                                } else
                                    flags[c] = true;
                            } else {
                                ret = 0;
                                break;
                            }
                        }
                        if (ret == 0)
                            break;       
                    }
                    if (ret == 0)
                        break;       
                }
                if (ret == 0)
                    break;       
            }
        }
        if (ret == 1) {
            fprintf(fout, "Case #%d: Yes\n", idx); 
        } else {
            fprintf(fout, "Case #%d: No\n", idx); 
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
