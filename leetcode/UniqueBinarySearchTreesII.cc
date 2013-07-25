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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generateTreesCore(1, n);
    }
    vector<TreeNode *> generateTreesCore(int start, int end){
        vector<TreeNode* > ret;
        if (start > end) {
            ret.push_back(NULL);
            return ret;
        }
        for (int i = start; i <= end; i++){
            vector<TreeNode *> left_root = generateTreesCore(start, i -1);
            vector<TreeNode *> right_root = generateTreesCore(i+1, end);
            vector<TreeNode* >::iterator it_left = left_root.begin();
            for (; it_left != left_root.end(); it_left++) {
                vector<TreeNode* >::iterator it_right = right_root.begin();
                for (; it_right != right_root.end(); it_right++) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = (*it_left);
                    root -> right = (*it_right);
                    ret.push_back(root);
                }        
            }
        }
        return ret;
    }
};
