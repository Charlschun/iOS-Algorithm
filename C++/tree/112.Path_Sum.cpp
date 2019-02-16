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
 https://leetcode-cn.com/problems/path-sum/
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 
 Note: A leaf is a node with no children.
 
 Example:
 
 Given the below binary tree and sum = 22,
 */
bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) {
        //这里直接返回false,因为根节点不满足，那么空的子节点肯定也不满足
        return false;
    }
    if (root->left == NULL && root->right == NULL) {
        return sum - root->val == 0;
    }
    return hasPathSum(root->left, sum-root->val) ||
    hasPathSum(root->right, sum-root->val);
}
int main(int argc, const char * argv[]) {
    
    TreeNode *tree = new TreeNode(3);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(2);
    tree->left->left = new TreeNode(15);
    tree->right->right = new TreeNode(15);
    cout << hasPathSum(tree, 20);
    return 0;
}
