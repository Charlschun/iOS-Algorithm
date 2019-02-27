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
#include <array>
/*
 https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/submissions/
 Given a non-empty binary tree, find the maximum path sum.
 
 For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
 */
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int res=INT_MIN;
    int getMax(TreeNode *node){
        if (!node) {
            return 0;
        }
        int lv = max(getMax(node->left), 0);
        int rv = max(getMax(node->right), 0);
        res=max(res, lv+rv+node->val);
        return node->val + max(lv, rv);
    }
    int maxPathSum(TreeNode* root) {
        getMax(root);
        return res;
    }
};
int main(int argc, const char * argv[]) {
    Solution sl;
    return 0;
}

