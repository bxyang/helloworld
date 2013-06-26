/*
 * =====================================================================================
 *
 *       Filename:  50.cc
 *
 *    Description:  lowest common ancestor
 *
 *        Version:  1.0
 *        Created:  06/26/2013 02:28:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdio>
#include<cstdlib>
#include<list>

struct BiTreeNode {
    int data;
    BiTreeNode* left;
    BiTreeNode* right;
};


BiTreeNode* get_common_ancestor(BiTreeNode* root, BiTreeNode* node1, BiTreeNode* node2) {
    if (root == NULL)
        return NULL;
    if ((node1 == NULL) || (node2 == NULL))
        return NULL;
    int n_small = ((node1 -> data) > (node2 -> data)) ? (node2 -> data) : (node1 -> data);
    int n_big = ((node1 -> data) > (node2 -> data)) ? (node1 -> data) : (node2 -> data);
    while (root != NULL) {
        int p = root -> data;
        if (n_big < p) {
            root = root -> left;
            continue;
        }
        if (n_small > p) { 
            root = root -> right;
            continue;
        }
        return root;
    }
    return NULL;
}

struct TreeNode {
    int data;
    std::list<TreeNode*> child;
};

bool get_node_path(TreeNode* root, TreeNode* key, std::list<TreeNode*>& path) {
    if ((root == NULL) || (key == NULL))
        return false;
    if (root == key) {
        return true;
    }
    std::list<TreeNode*>::iterator it = (root -> child).begin();
    bool is_found = false;
    path.push_back(root);
    for(; it != (root -> child).end(); it++) {
        if(get_node_path(*it, key, path)) {
            is_found = true;
            break;
        }
    }
    if (!is_found){
        path.pop_back();
    }
    return is_found;
}

TreeNode* get_last_common_node(std::list<TreeNode*>& path1, std::list<TreeNode*>& path2) {
    std::list<TreeNode*>::iterator it1 = path1.begin();
    std::list<TreeNode*>::iterator it2 = path2.begin();
    TreeNode* p_last = NULL;
    while ((it1 != path1.end()) && (it2 != path2.end())) {
        if (*it1 == *it2) {
            p_last = *it1;
        }
        else {
            break;
        }
        it1++;
        it2++;
    }
    return p_last;
}
    
TreeNode* get_common_ancestor(TreeNode* root, TreeNode* node1, TreeNode* node2) {
    std::list<TreeNode*> path1;
    if(!get_node_path(root, node1, path1))
        return NULL;
    std::list<TreeNode*> path2;
    if(!get_node_path(root, node2, path2))
        return NULL;
    return get_last_common_node(path1, path2);
}

int main() {

    return 0;
}
