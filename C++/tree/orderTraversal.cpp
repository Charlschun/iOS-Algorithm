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
#pragma mark -   二叉树的先序遍历
/*
 https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 Given a binary tree, return the preorder traversal of its nodes' values.
 */
void preorderTraversal(TreeNode* root,vector<int> &results);
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> r;
    //跟左右
    preorderTraversal(root, r);
    return r;
}
void preorderTraversal(TreeNode* node,vector<int> &results) {
    if (!node) {
        return;
    }
    results.push_back(node->val);
    preorderTraversal(node->left, results);
    preorderTraversal(node->right, results);
}
#pragma mark -   二叉树的中序遍历
/*
 https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 */
void inorderTraversal(TreeNode* node,vector<int> &results){
    if (!node) {
        return;
    }
    inorderTraversal(node->left, results);
    results.push_back(node->val);
    inorderTraversal(node->right, results);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> r;
    //左跟右
    inorderTraversal(root, r);
    return r;
}
#pragma mark -   二叉树的后序遍历
/*
 https://leetcode-cn.com/problems/binary-tree-postorder-traversal/submissions/
 */
void postorderTraversal(TreeNode* node,vector<int> &results){
    if (!node) {
        return;
    }
    postorderTraversal(node->left, results);
    postorderTraversal(node->right, results);
    results.push_back(node->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> r;
    //左跟右
    postorderTraversal(root, r);
    return r;
}
#pragma mark -  二叉树的层次遍历
/*
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 */
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> r;
    vector<TreeNode*> stack;
    stack.push_back(root);
    TreeNode *node;
    while (!stack.empty()) {
        vector<int> s;
        int size = stack.size();
        for (int i = 0; i < size; i++) {
            node = stack[i];
            s.push_back(node->val);
            if (node->left) {
                stack.push_back(node->left);
            }
            if (node->right) {
                stack.push_back(node->right);
            }
        }
        stack.erase(stack.begin(), stack.begin()+size);
        r.push_back(s);
    }
    return r;
}

int main(int argc, const char * argv[]) {
    
    TreeNode *tree = new TreeNode(3);
    tree->left = new TreeNode(9);
    tree->right = new TreeNode(20);
    tree->right->left = new TreeNode(15);
    tree->right->right = new TreeNode(7);
    auto x=  preorderTraversal(tree);
    auto y= inorderTraversal(tree);
    auto z= postorderTraversal(tree);
    auto a= levelOrder(tree);
    return 0;
}
