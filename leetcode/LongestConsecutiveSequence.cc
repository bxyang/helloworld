/*
 * =====================================================================================
 *
 *       Filename:  LongestConsecutiveSequence.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/7/2 20:55:22
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
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, pair<int, int>> con_sets; 
        for (vector<int>::iterator it = num.begin(); it != num.end(); it++) {
            map<int, pair<int, int>>::iterator it_pre = con_sets.find(*it - 1);
            map<int, pair<int, int>>::iterator it_post = con_sets.find(*it + 1);
            if ((it_pre != con_sets.end()) && (it_post != con_sets.end())) {
                pair<int, int> v_pre = it_pre -> second;
                pair<int, int> v_post = it_post -> second;
                int left = (v_pre.first < v_post.first) ? v_pre.first : v_post.first;
                int right = (v_pre.second > v_post.second) ? v_pre.second : v_post.second;
                con_sets.erase(v_pre.first);
                con_sets.erase(v_pre.second);
                con_sets.erase(v_post.first);
                con_sets.erase(v_post.second);
                con_sets[left] = pair<int, int>(left, right);
                con_sets[right] = pair<int, int>(left, right);
            } else if ((it_pre == con_sets.end()) && (it_post == con_sets.end())) {
                if (con_sets.find(*it) == con_sets.end())
                    con_sets[*it] = pair<int, int>(*it, *it);
            } else if (it_pre == con_sets.end()) {
                pair<int, int> v_post = it_post -> second;
                if (v_post.first <= *it)
                    continue;
                con_sets.erase(it_post);
                con_sets[*it] = pair<int, int>(*it, v_post.second);
                con_sets[v_post.second] = pair<int, int>(*it, v_post.second);
            } else {
                pair<int, int> v_pre = it_pre -> second;
                if (v_pre.second >= *it)
                    continue;
                con_sets.erase(it_pre);
                con_sets[*it] = pair<int, int>(v_pre.first, *it);
                con_sets[v_pre.first] =pair<int, int>(v_pre.first, *it);
            }
        }
        int ret = 0;
        for (map<int, pair<int, int>>::iterator it = con_sets.begin(); 
            it != con_sets.end(); it++) {
            pair<int, int> v_it = it -> second;
            int tmp = v_it.second - v_it.first + 1;
            ret = ((ret > tmp) ? ret : tmp);
        }
        return ret;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> seq_hash;
        int ret = 1;
        for (vector<int>::iterator it = num.begin(); it != num.end(); it++) {
            if (seq_hash.find(*it) == seq_hash.end())
                seq_hash.insert(pair<int, int>(*it, 0));
            else
                continue;
            if (seq_hash.find(*it-1) != seq_hash.end()) {
                int a = (*it - 1 + seq_hash[*it-1]);
                int b = (*it + seq_hash[*it]);
                int left = min(a, min(b, *it-1));
                int right = max(a, max(b, *it));
                if (seq_hash.find(left) != seq_hash.end())
                    seq_hash[left] = right - left;    
                else
                    seq_hash.insert(pair<int, int>(left, right - left) );
                if (seq_hash.find(right) != seq_hash.end())
                    seq_hash[right] = left - right;
                else
                    seq_hash.insert(pair<int, int>(right, left - right) );
                ret = (ret > (right - left + 1) ? ret : (right - left + 1));
            }
            if (seq_hash.find(*it+1) != seq_hash.end()) {
                int a = (*it + 1 + seq_hash[*it+1]);
                int b = (*it + seq_hash[*it]);
                int left = min(a, min(b, *it));
                int right = max(a, max(b, *it+1));
                if (seq_hash.find(left) != seq_hash.end())
                    seq_hash[left] = right - left;    
                else
                    seq_hash.insert(pair<int, int>(left, right - left) );
                if (seq_hash.find(right) != seq_hash.end())
                    seq_hash[right] = left - right;
                else
                    seq_hash.insert(pair<int, int>(right, left - right) );
                ret = (ret > (right - left + 1) ? ret : (right - left + 1));                
            }
        }
        return ret;
    }
    
    int min(int i, int j) {
        return i < j ? i : j;
    }
};