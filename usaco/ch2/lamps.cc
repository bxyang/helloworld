/*
ID: yangbao1
PROG: lamps
LANG: C++
*/


// 由于初始索引没有处理好，代码很ugly
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <stdint.h>
#include <utility>
#include <vector>
#include <algorithm>


using namespace std;

pair<uint64_t, uint64_t> final_state_mask = make_pair(0x0, 0x0);
pair<uint64_t, uint64_t> final_state = make_pair(0x0, 0x0);
bool flag = true;
int N, C;

void press_once(int action, pair<uint64_t, uint64_t>& state);
void press(uint32_t press_bt, pair<uint64_t, uint64_t>& state);

bool is_valid(pair<uint64_t, uint64_t>& state);
void print(pair<uint64_t, uint64_t>& state);

int transform_c();
vector<uint32_t> press_bt_vec;
vector<pair<uint64_t, uint64_t> > sol;

void print(pair<uint64_t, uint64_t>& state, int n);
void produce_states();
pair<uint64_t, uint64_t> strip_mask = make_pair(0x0, 0x0);


int cmp(pair<uint64_t, uint64_t> p1, pair<uint64_t, uint64_t> p2) {
    if (p1.first != p2.first) {
        uint64_t m = 0x1;
        for (int i = 0; i < 63; i++) {
            m <<= 1;
            if ((p1.first & m) == (p2.first & m)) continue;
            else return (p1.first & m) < (p2.first & m);
        }
    } else {
        uint64_t m = 0x1;
        for (int i = 0; i < 64; i++) {
            if ((p1.second & m) == (p2.second & m)) { m <<= 1; continue;}
            else return (p1.second & m) < (p2.second & m);
        }
    }
    return 0;

}

void set_press_bt(int c) {
    switch(c) {
        case 0:
            press_bt_vec.push_back(0x0);
            break;
        case 1:
            press_bt_vec.push_back(0x1);
            press_bt_vec.push_back(0x2);
            press_bt_vec.push_back(0x4);
            press_bt_vec.push_back(0x8);
            break;
        case 2:
            press_bt_vec.push_back(0x0);
            press_bt_vec.push_back(0x3);
            press_bt_vec.push_back(0x5);
            press_bt_vec.push_back(0x9);
            press_bt_vec.push_back(0x6);
            press_bt_vec.push_back(0xA);
            press_bt_vec.push_back(0xC);
            break;
        case 3:
            press_bt_vec.push_back(0x1);
            press_bt_vec.push_back(0x2);
            press_bt_vec.push_back(0x4);
            press_bt_vec.push_back(0x8);
            press_bt_vec.push_back(0xE);
            press_bt_vec.push_back(0xD);
            press_bt_vec.push_back(0xB);
            press_bt_vec.push_back(0x7);
            break;
        case 4:
            press_bt_vec.push_back(0x0);
            press_bt_vec.push_back(0x3);
            press_bt_vec.push_back(0x5);
            press_bt_vec.push_back(0x9);
            press_bt_vec.push_back(0x6);
            press_bt_vec.push_back(0xA);
            press_bt_vec.push_back(0xC);
            press_bt_vec.push_back(0xF);
            break;
    }
}


bool is_valid(pair<uint64_t, uint64_t>& state) {

    return ((state.second & final_state_mask.second) == final_state.second) \
        && ((state.first & final_state_mask.first) == final_state.first) ;
}

void print(pair<uint64_t, uint64_t>& state, int n) {
    for (int i = 0; i < n; i++) {
        if (i < 63) {
            state.first >>= 1;
            cout << (0x1 & state.first);
        } else {
            cout << (0x1 & state.second);
            state.second >>= 1;
        }
    } 
    flag = false;
    cout << endl;  
}

void press(uint32_t press_bt, pair<uint64_t, uint64_t>& state) {
    if ((press_bt & 0x1) != 0)
        press_once(0, state); 
    if ((press_bt & 0x2) != 0)
        press_once(1, state); 
    if ((press_bt & 0x4) != 0)
        press_once(2, state); 
    if ((press_bt & 0x8) != 0)
        press_once(3, state); 
}

void press_once(int action, pair<uint64_t, uint64_t>& state) {
    cerr << hex << state.first << " " << state.second << endl;
    switch(action) {
        case 0:
            state.first ^= (~0x0);
            state.second ^= (~0x0);
            break;
        case 1:
            state.first ^= 0xAAAAAAAAAAAAAAAA;
            state.second ^= 0xAAAAAAAAAAAAAAAA;
            break;
        case 2:
            state.first ^= 0x5555555555555555;
            state.second ^= 0x5555555555555555;
            break;
        case 3:
            state.first ^= 0x2492492492492492;
            state.second ^= 0x9249249249249249;
            break;
    }
    return;
}

int transform_c(int c) {
    if (c <= 4) return c;
    else if ((c & 0x1) == 0x0) return 4;
    else return 3;
}

void produce_states() {
    for (vector<uint32_t>::iterator it = press_bt_vec.begin(); it != press_bt_vec.end(); it++) {
        pair<uint64_t, uint64_t> state = make_pair(~0x0, ~0x0);
        press(*it, state);
        if (!is_valid(state)) continue;
        state.first &= strip_mask.first;
        state.second &= strip_mask.second;
        sol.push_back(state);
    }
}

int main() {
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w+", stdout);
    cin >> N;
    cin >> C;
    int t;
    cin >> t;
    while(t != -1) {
        if (t < 64) {
            final_state_mask.first |= ((uint64_t)0x1 << t);
            final_state.first |= ((uint64_t)0x1 << t);
        } else {
            final_state_mask.second |= ((uint64_t)0x1 << (t - 64));
            final_state.second |= ((uint64_t)0x1 << (t - 64));
        }
        cin >> t;
    } 

    cin >> t;
    while(t != -1) {
        if (t < 64) {
            final_state_mask.first |= ((uint64_t)0x1 << t);
        } else {
            final_state_mask.second |= ((uint64_t)0x1 << (t - 64));
        }
        cin >> t;
    }

    C = transform_c(C);
    set_press_bt(C);
    if (N < 63) {
        uint64_t m = 0x1;
        for (int i = 0; i < N; i++) {
            m <<= 1;
            strip_mask.first |= m;
        }
    } else {
        strip_mask.first = (~0x0) - 1;
        uint64_t m = 0x1;
        for (int i = 0; i < N - 63; i++) {
            strip_mask.second |= m;
            m <<= 1;
        }
    }
    
    produce_states();
    
    if (sol.size() == 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        int len = sol.size();
        if (len == 1) print(sol[0], N);
        else {
            sort(sol.begin(), sol.end(), cmp);
            print(sol[0], N);
            for (int i = 1; i < len; i++) {
                if ((sol[i].first == sol[i-1].first) && (sol[i].second == sol[i-1].second)) continue;
                print(sol[i], N);
            }
        }
    }
}

