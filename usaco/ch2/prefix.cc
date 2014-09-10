/*
ID: yangbao1
PROG: prefix
LANG: C++
*/

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char _c;
    vector<Node* > _sub_node;
    bool _flag;
};

void build_tree(Node* root, const char* str) {
    if (*str == '\0') return;
    char c = str[0];
    for (vector<Node* >::iterator it = (root->_sub_node).begin();
            it != (root->_sub_node).end(); it++) {
        if ((*it)->_c == c) {
            if (str[1] == '\0') {
                (*it)->_flag = true;
            } else {
                build_tree(*it, str+1);
            }
            return;
        }
    }

    Node* node = new Node();
    (root->_sub_node).push_back(node);
    node->_c = c;
    if (str[1] == '\0') {
        node->_flag = true;
    } else {
        node->_flag = false;
        build_tree(node, str+1);
    }
}
void traverse_tree(string& seq, int idx, Node* root, vector<int>& sub_seq) {
    if (idx == seq.size()) return;
    for (vector<Node* >::iterator it = (root->_sub_node).begin();
            it != (root->_sub_node).end(); it++) {
        if ((*it)->_c != seq[idx]) continue;
        if ((*it)->_flag) sub_seq.push_back(idx+1);
        traverse_tree(seq, idx+1, *it, sub_seq);
    }
}


int get_longest_prefix(string& seq, int idx, int* cnt, Node* root) {
    if (idx == seq.size()) return 0;
    if (cnt[idx] != -1) return cnt[idx];
    vector<int> sub_seq;
    traverse_tree(seq, idx, root, sub_seq);
    int longest_prefix = 0;
    for (vector<int>::iterator it = sub_seq.begin(); it != sub_seq.end();
            it++) {
        int tmp = get_longest_prefix(seq, *it, cnt, root) + (*it) - idx;
        longest_prefix = (longest_prefix > tmp) ? longest_prefix : tmp;
    }
    cnt[idx] = longest_prefix;
    return longest_prefix;   
}

int main() {
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w+", stdout);
    Node* root = new Node();
    root -> _c = '\0';
    root -> _flag = false;
    
    string str;
    while (1) {
        getline(cin, str);
        if (str.compare(".") == 0) break;
        int p1 = 0;
        int p2 = 0;
        while (p2 < str.size()) {
            if(str[p2] == ' ') {
                build_tree(root, str.substr(p1, p2-p1).c_str());
                p1 = p2 + 1;
                p2 = p1;
            } else {
                p2++;
            } 
        }
        build_tree(root, str.substr(p1, p2-p1).c_str());
    }
    string seq;
    string tmp;
    while(getline(cin, tmp)) {
        seq += tmp;
        tmp.clear();
    }
    seq += tmp;
    int* cnt = new int[seq.size()];
    for (int i = 0; i < seq.size(); i++) {
        cnt[i] = -1;
    }
    cout << get_longest_prefix(seq, 0, cnt, root) << endl;
}
