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
 https://leetcode-cn.com/problems/symmetric-tree/
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 
 For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 */
bool isSymmetric(TreeNode* l,TreeNode *r);
bool isSymmetric(TreeNode* root) {
    //如果左子树和右子树对称的话，那么这个数就是对称的.
    return isSymmetric(root, root);
}
bool isSymmetric(TreeNode* l,TreeNode *r) {
    //如果左子树和右子树对称的话，那么这个数就是对称的.
    if (l == NULL && r == NULL) {
        return true;
    }
    if (l == NULL || r == NULL) {
        return false;
    }
    return (l->val == r->val) &&
    isSymmetric(l->left, r->right) &&
    isSymmetric(l->right, r->left);
}

bool isSymmetric2(TreeNode* root){
    vector<TreeNode *>v;
    v.push_back(root);
    v.push_back(root);
    while (!v.empty()) {
        TreeNode *l = v.back();
        v.pop_back();
        TreeNode *r = v.back();
        v.pop_back();
        if (l == NULL && r == NULL) {
            continue;
        }
        if (l == NULL || r == NULL) {
            return false;
        }
        if (l->val != r->val) {
            return false;
        }
        v.push_back(l->left);
        v.push_back(r->right);
        v.push_back(l->right);
        v.push_back(r->left);
    }
    return true;
}
int main(int argc, const char * argv[]) {
    
    TreeNode *tree = new TreeNode(3);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(2);
    tree->left->left = new TreeNode(15);
    tree->right->right = new TreeNode(15);
    cout << isSymmetric2(tree);
    return 0;
}
