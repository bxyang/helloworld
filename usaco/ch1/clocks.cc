/*
ID: yangbao1
PROG: clocks
LANG: C++
*/


#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>

using namespace std;

// 100 0000 0000 0000 0000
unsigned int states[0x40000];
unsigned short int actions[0x40000];

unsigned int move_mask[10] = {
// 11 1111 1111 1111 1111
0x3FFFF,
// 11 1100 1111 0000 0000
0x3CF00,
// 11 1111 0000 0000 0000
0x3F000,
// 00 1111 0011 1100 0000
0xF3C0, 
// 11 0000 1100 0011 0000
0x30C30,
// 00 1100 1111 1100 1100
0xCFCC,
// 00 0011 0000 1100 0011
0x30C3,
// 00 0000 1111 0011 1100
0xF3C,
// 00 0000 0000 0011 1111
0x3F,
// 00 0000 0011 1100 1111
0x3CF};

unsigned int move(unsigned int ns, unsigned int mask);

int main() {
    FILE *fin = fopen("clocks.in", "r");
    FILE *fout = fopen("clocks.out", "w+");   
    
    //memset(states, sizeof(states), 0);
    //memset(actions, sizeof(actions), 0);

    unsigned int init_state = 0;
    for (int i = 0; i < 9; ++i) {
        unsigned int t;
        fscanf(fin, "%d", &t);
        init_state <<= 2;
        init_state |= ((t-1)/3);
    }

    queue<unsigned int> q;
    int last = 1;
    int cur = 0;
    q.push(init_state);
    while (!q.empty()) {
        unsigned int ns = q.front();
        q.pop();
        last --;
        if (last < 0) {
            last = cur;
            cur = 0;
        }
        bool flag = false;
        for (int i = 1; i <= 9; i++) {
            unsigned int candidate = move(ns, move_mask[i]);
            if(!states[candidate]) {
                q.push(candidate);
                states[candidate] = ns;
                actions[candidate] = i;
                if (candidate == move_mask[0]) {flag = true; break;}
                cur++;
            } 
        }
        if (flag) break;
    }
    
    vector<int> rotate_action;
    unsigned int last_state = move_mask[0];
    while (last_state != init_state) {
        rotate_action.push_back(actions[last_state]);
        last_state = states[last_state];
    }
    fprintf(fout, "%d", rotate_action[rotate_action.size()-1]);
    for (int i = rotate_action.size()-2; i >= 0; --i) {
        fprintf(fout, " %d", rotate_action[i]);
    }
    fprintf(fout, "\n");
    fclose(fin);
    fclose(fout);
    return 0;
}

unsigned int move(unsigned int ns, unsigned int mask) {
    unsigned int ret = 0x0;
    for (int i = 0; i < 9; i++) {
        unsigned int t = ns & 0x3;
        if (0x3 & mask) 
            t = (t + 1) & 0x3;
        t <<= (2*i);
        ret |= t;
        ns >>= 2;
        mask >>= 2;
    }
    return ret;
}

/*
bool dfs(unsigned int ns, vector<int> &rotate_action, const int max_step) {
    if (rotate_action.size() >= max_step) return false;
    for (int i = 1; i <= 9; ++i) {
        unsigned int candidate = (ns + move_mask[i]) & move_mask[0];
        rotate_action.push_back(i);
        if (candidate == move_mask[0]) return true;
        if (dfs(candidate, rotate_action, max_step)) return true;
        rotate_action.pop_back();
    }
    return false;
}
*/
