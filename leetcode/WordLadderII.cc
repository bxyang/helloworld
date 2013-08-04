/*
 * =====================================================================================
 *
 *       Filename:  WordLadderII.cc
 *
 *    Description:  
        Given two words (start and end), and a dictionary, 
        find all shortest transformation sequence(s) from start to end, such that:

        Only one letter can be changed at a time
        Each intermediate word must exist in the dictionary
        For example,

        Given:
        start = "hit"
        end = "cog"
        dict = ["hot","dot","dog","lot","log"]

        Return

          [
            ["hit","hot","dot","dog","cog"],
            ["hit","hot","lot","log","cog"]
          ]
        Note:

        All words have the same length.
        All words contain only lowercase alphabetic characters.
 *
 *
 *        Version:  1.0
 *        Created:  2013/8/3 15:59:47
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
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<string> > ret;
        if (start == end) {
            ret.push_back(vector<string>(1, start));
            return ret;
        }
                
        queue<string> prev;
        prev.push(start);
        unordered_set<string> uni_set;
        uni_set.insert(start);
        bool flag = true;
        while (flag && (! prev.empty())) {
            int prev_size = prev.size();
            vector<vector<string> > candinate;
            for (int i = 0; i < prev_size; i++) {
                string last = prev.front();
                prev.pop();
                string tmp = last;
                for (int i = 0; i < last.length(); i++) {
                    char c = last[i];
                    for (int j = 1; j < 26; j++) {
                        last[i] =  'a' + (c + j - 97) % 26;
                        if (last == end) {
                            flag = false;
                            candinate.push_back({tmp});
                            break;
                        } else {
                            if (! flag)
                                continue;
                            if (dict.find(last) == dict.end())
                                continue;
                            candinate.push_back({tmp, last});
                            if(uni_set.find(last) == uni_set.end()) {
                                uni_set.insert(last);
                                prev.push(last);                                
                            }
                        }
                    }
                    last[i] = c;
                }
            }
            if (candinate.size() == 0)
                return candinate;
            if (! flag) {
                vector<vector<string> > candinate2;
                for (vector<vector<string> >::iterator it = candinate.begin(); it != candinate.end(); it++) {
                    if (it -> size() != 1)
                        continue;
                    candinate2.push_back({(*it)[0], end});
                }
                candinate = candinate2;
            }
            if (ret.size() == 0) {
                ret = candinate;
                continue;
            }
            
            vector<vector<string> > merged;
            for (vector<vector<string> >::iterator it = candinate.begin();
                it != candinate.end(); it++) {
                string next = (*it)[0];
                for (vector<vector<string> >::iterator it_ret = ret.begin(); it_ret != ret.end(); it_ret++) {
                    if (next == (*(it_ret -> end() - 1))) {
                        vector<string> tmp = (*it_ret);
                        tmp.push_back((*it)[1]);
                        merged.push_back(tmp);
                    }
                }        
            }
            ret = merged;
        }
        return ret;

    }
};

class Solution {
public:
    typedef vector<vector<string> > vvstr;
    typedef vector<vector<string> >::iterator vvstr_iter;
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vvstr ret;
        if (start == end) {
            ret.push_back(vector<string>(1, start));
            return ret;
        }
                
        queue<string> prev;
        prev.push(start);
        unordered_set<string> uni_set;
        uni_set.insert(start);
        bool flag = true;
        map<string, vector<int> > tail;
        while (flag && (! prev.empty())) {
            int prev_size = prev.size();
            vvstr candinate;
            for (int i = 0; i < prev_size; i++) {
                string last = prev.front();
                prev.pop();
                string tmp = last;
                for (int i = 0; i < last.length(); i++) {
                    char c = last[i];
                    for (int j = 1; j < 26; j++) {
                        last[i] =  'a' + (c + j - 97) % 26;
                        if (last == end) {
                            flag = false;
                            candinate.push_back({tmp});
                            break;
                        } else {
                            if (! flag)
                                continue;
                            if (dict.find(last) == dict.end())
                                continue;
                            candinate.push_back({tmp, last});
                            if(uni_set.find(last) == uni_set.end()) {
                                uni_set.insert(last);
                                prev.push(last);                                
                            }
                        }
                    }
                    last[i] = c;
                }
            }
            if (candinate.size() == 0)
                return candinate;
            if (! flag) {
                vvstr candinate2;
                for (vvstr_iter it = candinate.begin(); it != candinate.end(); it++) {
                    if (it -> size() != 1)
                        continue;
                    candinate2.push_back({(*it)[0], end});
                }
                candinate = candinate2;
            }
            if (ret.size() == 0) {
                ret = candinate;
                int v = 0;
                for (vvstr_iter it_ret = ret.begin(); it_ret != ret.end(); it_ret++, v++) {
                    string key = *(it_ret -> end() - 1);
                    if (tail.find(key) != tail.end()) {
                        tail[key].push_back(v);
                    } else {
                        tail.insert(pair<string, vector<int> >(key, vector<int>(1, v)));
                    }
                }
                continue;
            }
            
            vvstr merged;
            map<string, vector<int> > tail_tmp;
            int v = 0;
            for (vvstr_iter it = candinate.begin(); it != candinate.end(); it++) {
                string next = (*it)[0];
                if (tail.find(next) != tail.end()) {
                    vector<int> index = tail[next];
                    string key = (*it)[1];
                    for (vector<int>::iterator it_idx = index.begin(); it_idx != index.end(); it_idx++) {
                        vector<string> tmp = ret[*it_idx];
                        tmp.push_back(key);
                        merged.push_back(tmp);
                        if (tail_tmp.find(key) != tail_tmp.end()) {
                            tail_tmp[key].push_back(v);
                        } else {
                            tail_tmp.insert(pair<string, vector<int> >(key, vector<int>(1, v)));
                        }
                        v++;
                    }
                }
            }
            ret = merged;
            tail = tail_tmp;
        }
        return ret;

    }
};

