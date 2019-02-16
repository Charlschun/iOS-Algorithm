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
 https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 Given inorder and postorder traversal of a tree, construct the binary tree.
 
 Note:
 You may assume that duplicates do not exist in the tree.
 
 For example, given
 
 inorder = [9,3,15,20,7]
 postorder = [9,15,7,20,3]
 */
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) {
        return NULL;
    }
    int parent = postorder.back();
    if (inorder.size() == 1) {
        return new TreeNode(parent);
    }
    int index = find(inorder.begin(), inorder.end(), parent) - inorder.begin();
    if (index >= inorder.size()) {
        return NULL;
    }
    auto in_begin = inorder.begin();
    auto post_begin = postorder.begin();
    vector<int> inorder_left(in_begin,in_begin+index);
    vector<int> inorder_right(in_begin+index+1,inorder.end());
    vector<int> postorder_left(post_begin,post_begin+inorder_left.size());
    vector<int> postorder_right(post_begin+inorder_left.size(),post_begin+inorder_left.size()+inorder_right.size());
    TreeNode *node = new TreeNode(parent);
    node->left = buildTree(inorder_left, postorder_left);
    node->right = buildTree(inorder_right, postorder_right);
    return node;
}

TreeNode* dfs(int start, int end, vector<int>& inorder, vector<int>& postorder, int& val){
    int post = postorder[val];
    cout << val << " is: " << post << " " <<endl ;
    //在中序遍历数组里面查找，如果存在，说明他有子节点，不存在，说明它是叶子节点
    int i=start;
    for(; i<end;i++){
        if(inorder[i]==post)
            break;
    }
    TreeNode* root=new TreeNode(post);
    if(end>=i+1)
        root->right=dfs(i+1, end, inorder, postorder, --val);
    if(i-1>=start)
        root->left = dfs(start, i-1, inorder, postorder, --val);
    
    return root;
}
TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.empty()||postorder.empty())
        return NULL;
    int index = inorder.size()-1;
    return dfs(0, index, inorder, postorder, index);
}
int main(int argc, const char * argv[]) {
    
    TreeNode *tree = new TreeNode(3);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(2);
    tree->left->left = new TreeNode(15);
    tree->right->right = new TreeNode(15);
    
    vector<int>in{9,3,15,20,7};
    vector<int>post{9,15,7,20,3};
    TreeNode *node = buildTree2(in, post);
    return 0;
}
