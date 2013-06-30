/*
 * =====================================================================================
 *
 *       Filename:  PathSumII.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/6/30 11:42:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret_vec;
        if (root == NULL)
            return ret_vec;
        list<list<int> > ret_list = pathSumCore(root, sum);
        while (!ret_list.empty()) {
            vector<int> tmp;
            list<int> item = ret_list.front();
            ret_list.pop_front();
            while (!item.empty()){
                tmp.push_back(item.front());
                item.pop_front();
            }
            ret_vec.push_back(tmp);
        }
        return ret_vec;
    }
    
    list<list<int> > pathSumCore(TreeNode* root, int sum) {
        list<list<int> > ret;
        sum -= (root -> val);
        if ((sum == 0) && (root -> left == NULL) && (root -> right == NULL)) {
            list<int> tmp;
            tmp.push_back(root -> val);
            ret.push_back(tmp);
            return ret;        
        }
        if (root -> left != NULL) {
            list<list<int> > t1 = pathSumCore(root -> left, sum);
            for (list<list<int> >::iterator it = t1.begin(); it != t1.end(); it++) {
                (*it).push_front(root -> val);
                ret.push_back(*it);
            }
        }
        if (root -> right != NULL) {
            list<list<int> > t2 = pathSumCore(root -> right, sum);
            for (list<list<int> >::iterator it = t2.begin(); it != t2.end(); it++) {
                (*it).push_front(root -> val);
                ret.push_back(*it);
            }
        }
        return ret;
    }
};

