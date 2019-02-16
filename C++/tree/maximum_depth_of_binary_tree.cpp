//
//  main.cpp
//  LeetCode
//
//  Created by junl on 2019/1/21.
//  Copyright © 2019 junl. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <set>
#include <algorithm>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val):val(val),left(NULL),right(NULL){};
};
/*
 Given a binary tree, find its maximum depth.
 
 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 
 Note: A leaf is a node with no children.
 
 Example:
 
 Given binary tree [3,9,20,null,null,15,7],
 
 3
 / \
 9  20
 /  \
 15   7
 */
//自低向上，从子节点推算出根节点的深度
int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int ll = maxDepth(root->left);
    int rl = maxDepth(root->right);
    return max(ll, rl) + 1;
}
//自顶向下
int maxDepth_v2(TreeNode* root,int len) {
    if (!root->left && !root->right) {
        return len;
    }
    int ll,rl;
    ll = rl = len;
    if (root->left) {
        ll = maxDepth_v2(root->left,len+1);
    }
    if (root->right) {
        rl = maxDepth_v2(root->right,len+1);
    }
    return max(ll, rl);
}
int main(int argc, const char * argv[]) {
    
    TreeNode *tree = new TreeNode(3);
    tree->left = new TreeNode(9);
    tree->right = new TreeNode(20);
    tree->right->left = new TreeNode(15);
    tree->right->right = new TreeNode(7);
    cout << maxDepth(tree) << endl;
    cout << maxDepth_v2(tree,1) << endl;
    return 0;
}
