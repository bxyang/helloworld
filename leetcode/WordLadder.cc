/*
 * =====================================================================================
 *
 *       Filename:  WordLadder.cc
 *
 *    Description:  
        Given two words (start and end), and a dictionary, 
        find the length of shortest transformation sequence from start to end, such that:

        Only one letter can be changed at a time
        Each intermediate word must exist in the dictionary
        For example,

        Given:
        start = "hit"
        end = "cog"
        dict = ["hot","dot","dog","lot","log"]

        As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
        return its length 5.

        Note:

        Return 0 if there is no such transformation sequence.
        All words have the same length.
        All words contain only lowercase alphabetic characters.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/3 10:23:49
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
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (start == end)
            return 0;
        // -2 unknown, -1 -ing, 0 impossible, 
        map<int, int> ladder_dic;
        vector<string> v_dic; 
        int i = 0;
        unordered_set<string>::iterator p_start = dict.find(start);
        if (p_start != dict.end()) {
            dict.erase(p_start);
        }
        ladder_dic.insert(pair<int, int>(i, -2));
        v_dic.push_back(start);
        i++;
        for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++, i++) {
            ladder_dic.insert(pair<int, int>(i, -2));
            v_dic.push_back(*it);
        }
        
        vector<vector<int> > dist_dic = vector<vector<int> >(i, vector<int>(i, -1));
                   
        return ladderLength(0, end, v_dic, ladder_dic, dist_dic);
        
        
    }
    
    int ladderLength(int p, string end,
        vector<string> &v_dic, map<int, int> &ladder_dic, vector<vector<int> > dist_dic) {        
        int ret = 0x7fffffff;
        int state = ladder_dic[p];
        if (state != -2)
            return state;
        if (v_dic[p] == end) {
            ladder_dic[p] = 1;
            return 1;
        }
        ladder_dic[p] = -1;
        int i = 0;
        for (vector<string>::iterator it = v_dic.begin(); it != v_dic.end(); it++, i++) {
            int t = dist_dic[p][i];
            if (t == -1) {
                t = dist(v_dic[p], *it);
                dist_dic[p][i] = t;
                dist_dic[i][p] = t;
            }
            if (t == 0) {
                continue;
            } else if (t == 1) {
                int state = ladderLength(i, end, v_dic, ladder_dic, dist_dic);
                if (state > 0)
                    ret = ret < (state+1) ? ret : (state+1);
            }
        }
        if (ret == 0x7fffffff)
            ret = 0;
        ladder_dic[p] = ret;
        return ret;
    }
    
    
    
    
    // 0, ==; 1, 1; 2 others
    int dist(string s1, string s2) {
        string::iterator it1 = s1.begin();
        string::iterator it2 = s2.begin();
        int ret = 0;
        for (; it1 != s1.end(); it1++, it2++) {
            if (*it1 == *it2)
                continue;
            if (ret == 1) {
                ret = 2;
                break;
            }
            ret++;
        }
        return ret;
    }
};



class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (start == end)
            return 0;
        // -2 unknown, -1 -ing, 0 impossible, 
        vector<int> ladder_dic;
        vector<string> v_dic; 
        int i = 0;
        unordered_set<string>::iterator p_start = dict.find(start);
        if (p_start != dict.end()) {
            dict.erase(p_start);
        }
        ladder_dic.push_back(-2);
        v_dic.push_back(start);
        i++;
        for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++, i++) {
            ladder_dic.push_back(-2);
            v_dic.push_back(*it);
        }
        
        vector<vector<int> > dist_dic ;
        for (int j = 0; j < i; j++) {
            vector<int> tmp;
            for (int k = 0; k <= j; k++) {
                tmp.push_back(dist(v_dic[j], v_dic[k]));
            }
            dist_dic.push_back(tmp);
        };
                   
        return ladderLength(0, end, v_dic, ladder_dic, dist_dic);
        
        
    }
    
    int ladderLength(int p, string &end,
        vector<string> &v_dic, vector<int> &ladder_dic, vector<vector<int> >& dist_dic) {        
        int ret = 0x7fffffff;
        int state = ladder_dic[p];
        if (state != -2)
            return state;
        if (v_dic[p] == end) {
            ladder_dic[p] = 1;
            return 1;
        }
        ladder_dic[p] = -1;
        int i = 0;
        
        int t_dist = dist2(v_dic[p], end);
        
        for (vector<string>::iterator it = v_dic.begin(); it != v_dic.end(); it++, i++) {
            int t;
            if (p > i)
                t = dist_dic[p][i];
            else
                t = dist_dic[i][p];
            if (t == 0) {
                continue;
            } else if (t == 1) {
                int state = ladderLength(i, end, v_dic, ladder_dic, dist_dic);
                if (state > 0) {
                    ret = ret < (state+1) ? ret : (state+1);
                    if (ret == (t_dist + 1))
                        break;
                }
            }
        }
        if (ret == 0x7fffffff)
            ret = 0;
        ladder_dic[p] = ret;
        return ret;
    }
    
    
    
    
    // 0, ==; 1, 1; 2 others
    int dist(string &s1, string &s2) {
        string::iterator it1 = s1.begin();
        string::iterator it2 = s2.begin();
        int ret = 0;
        for (; it1 != s1.end(); it1++, it2++) {
            if (*it1 == *it2)
                continue;
            if (ret == 1) {
                ret = 2;
                break;
            }
            ret++;
        }
        return ret;
    }
    
    int dist2(string &s1, string &s2) {
        string::iterator it1 = s1.begin();
        string::iterator it2 = s2.begin();
        int ret = 0;
        for (; it1 != s1.end(); it1++, it2++) {
            if (*it1 == *it2)
                continue;
            ret++;
        }
        return ret;
    }
};


class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (start == end)
            return 0;
        // -2 unknown, -1 -ing, 0 impossible, 
        
        unordered_set<string>::iterator p_start = dict.find(start); 
        if (p_start != dict.end())
            dict.erase(p_start);
            
        queue<string> prev;
        prev.push(start);
        int ret = 1;
        while (! prev.empty()) {
            ret++;
            int prev_size = prev.size();
            int i = 0;
            while (i < prev_size) {
                unordered_set<string>::iterator it = dict.begin();
                string str = prev.front();
                prev.pop();
                while (it != dict.end()) {
                    if (dist(str, *it) == 1) {
                        if (*it == end)
                            return ret;
                        prev.push(*it);
                        unordered_set<string>::iterator p_del = it;
                        it++;
                        dict.erase(p_del);
                    } else {
                        it++;
                    }
                }
                i++;
            }
        }
        return 0;
    }
    
    
    // 0, ==; 1, 1; 2 others
    int dist(const string &s1, const string &s2) {
        string::const_iterator it1 = s1.begin();
        string::const_iterator it2 = s2.begin();
        int ret = 0;
        for (; it1 != s1.end(); it1++, it2++) {
            if (*it1 == *it2)
                continue;
            if (ret == 1) {
                ret = 2;
                break;
            }
            ret++;
        }
        return ret;
    }

};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (start == end)
            return 1;
        if (dict.find(start) != dict.end()) {
            dict.erase(dict.find(start));    
        }
                
        queue<string> prev;
        prev.push(start);
        int ret = 1;
        while (! prev.empty()) {
            int prev_size = prev.size();
            ret++;
            while (prev_size > 0) {
                string last = prev.front();
                prev.pop();
                for (int i = 0; i < last.length(); i++) {
                    char c = last[i];
                    for (int j = 1; j < 26; j++) {
                        last[i] = 'a' + (c + j -'a') % 26;
                        if (last == end)
                            return ret;
                        unordered_set<string>::iterator p_del = dict.find(last);
                        if (p_del != dict.end()) {
                            dict.erase(p_del);
                            prev.push(last);
                        }
                    }
                    last[i] = c;
                }
                prev_size --;
            }   
        }
        return 0;
    }
};

