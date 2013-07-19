/*
 * =====================================================================================
 *
 *       Filename:  3-5-ShortestAbstract.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/18/2013 10:24:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<vector>
#include<string.h>
int min_abstract(vector<string>& query, vector<string>& passage) {
    int i = 0;
    vector<pair<int, int> > pos;
    for (vector<string>::iterator it = passage.begin(); it != passage.end(); it++, i++) {
        int ret = search_word(query, *it);
        if (ret != -1)
            pos.push_back(pair<int, int>(i, ret));
    }
    int query_len = query.length();
    bool *flag = new bool[query_len];
    int pos_len = pos.length();
    int tmp = pos_len - query_len - 1;
    int ret = passage.length();
    /*
    for (int i = 0; i < tmp; i++) {
        int count = query_len;
        for (int i = 0; i < query_len; i++) {
            flag[i] = false;
        }
        for (int j = i; j < pos_len; j++) {
            if (!flag[pos[j].second]) {
                flag[pos[j].second] = true;
                count --;
                if (count == 0) {
                    int len = pos[j].first - pos[i].first;
                    ret = (ret < len) ? ret : len;
                    break;
                }
            }
        }
    }*/
    int i = 0;
    int j = 0;
    int count = 0;
    int* state = new int[query_len];
    
    while ( (i < pos_len) || (j < pos_len) ) {
        if (count == query_len) {
            int len = pos[j].first - pos[i].first;
            ret = (ret < len) ? ret : len;
            if(state[pos[i].second] == 1)
                count--;
            state[pos[i].second] --;
            i++;
            continue;
        }
        int n = state[pos[j].second];
        if (n == 0)
            count++;
        state[pos[j].second] ++;
        j++;
    }
    return ret;
}


int search_word(vector<string>& query, string word) {
    int i = 0;   
    for (vector<string>::iterator it = query.begin(); it != query.end(); it++, i++) {
        if (word == (*it))
            return i;
    }
    return -1;
}

int main () {
    return 0;
}
