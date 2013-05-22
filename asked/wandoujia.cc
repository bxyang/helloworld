/*
 * =====================================================================================
 *
 *       Filename:  wandoujia.cc
 *
 *    Description:  print matrix clockwise
 *
 *        Version:  1.0
 *        Created:  05/22/2013 07:32:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>

void recursive_matrix_print(int** data, int r_count, int c_count, int interval);
void matrix_print(int** data, int r_count, int c_count);
int main(){
    int data[5][5] = {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15},
    {16,17,18,19,20},
    {21,22,23,24,25},
    };
    /*
    int data[1][4] = {
    {1,2,3,4}
    };
    */
    /*
    int data[4][1] = {
    {1},{2},{3},{4}
    };
    */
    
    matrix_print((int**)data, 5, 5);
    printf("\n");
    recursive_matrix_print((int**)data, 5, 5, 5);
    printf("\n");
    return 0;
}
void recursive_matrix_print(int** data, int r_count, int c_count, int interval){
    if( (r_count == 0) || (c_count == 0) )
        return;
    for(int i = 0; i < c_count; i++){
        //printf("%d ", data[0][i]);
        printf("%d ", *((int*)data + i));
    }
    for(int i = 1; i < r_count; i++){
        //printf("%d ", data[i][c_count-1]);
        printf("%d ", *((int*)data + interval*i + c_count-1));
    }
    if(r_count > 1){
        for(int i = c_count - 2; i > -1; i--){
        //printf("%d ", data[r_count-1][i]);
        printf("%d ", *((int*)data + interval*(r_count-1) + i));
        }
    }
    if(c_count > 1){
        for(int i = r_count - 2; i > 0; i--){
        //printf("%d ", data[i][0]);
        printf("%d ", *((int*)data + interval*i));
        }
    }
    recursive_matrix_print((int**)((int*)data + interval + 1), 
    (r_count > 2) ? (r_count-2):0, 
    (c_count > 2) ? (c_count-2):0,
    interval);
}

void matrix_print(int** data, int r_count, int c_count){
    int interval = c_count;
    while((r_count != 0) && (c_count != 0)){
        for(int i = 0; i < c_count; i++){
            //printf("%d ", data[0][i]);
            printf("%d ", *((int*)data + i));
        }
        for(int i = 1; i < r_count; i++){
            //printf("%d ", data[i][c_count-1]);
            printf("%d ", *((int*)data + interval*i + c_count-1));
        }
        if(r_count > 1){
            for(int i = c_count - 2; i > -1; i--){
            //printf("%d ", data[r_count-1][i]);
            printf("%d ", *((int*)data + interval*(r_count-1) + i));
            }
        }
        if(c_count > 1){
            for(int i = r_count - 2; i > 0; i--){
            //printf("%d ", data[i][0]);
            printf("%d ", *((int*)data + interval*i));
            }
        }
        r_count = (r_count > 2) ? (r_count-2):0;
        c_count = (c_count > 2) ? (c_count-2):0;
        data = (int**)((int*)data + interval + 1);
    }
}

