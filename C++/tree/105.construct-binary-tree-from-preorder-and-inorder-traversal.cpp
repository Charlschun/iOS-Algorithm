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
 https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 Given preorder and inorder traversal of a tree, construct the binary tree.
 
 Note:
 You may assume that duplicates do not exist in the tree.
 
 For example, given
 
 preorder = [3,9,20,15,7]
 inorder = [9,3,15,20,7]

 */
TreeNode* creatTree(vector<int> &preorder,vector<int> &inorder,int start,int end,int &index){
    int parent = preorder[index];
    int ct = start;
    for (; ct < end; ct++) {
        if (inorder[ct] == parent) {
            break;
        }
    }
    //因为我们使用的先序遍历的preorder,所以这里先左在右
    TreeNode *node = new TreeNode(parent);
    if (start < ct) {
        node->left = creatTree(preorder, inorder, start, ct-1, ++index);
    }
    if (ct < end) {
        node->right = creatTree(preorder, inorder, ct+1, end, ++index);
    }
    return node;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty()) {
        return NULL;
    }
    int index = 0;
    return creatTree(preorder, inorder, 0, preorder.size()-1, index);
}
int main(int argc, const char * argv[]) {
    
    TreeNode *tree = new TreeNode(3);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(2);
    tree->left->left = new TreeNode(15);
    tree->right->right = new TreeNode(15);
    
    vector<int>in{1,2,3,4};
    vector<int>pre{3,1,2,4};
    TreeNode *node = buildTree(pre, in);
    return 0;
}
