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
using namespace std;
/*
 https://leetcode-cn.com/problems/subsets/
 Given a set of distinct integers, nums, return all possible subsets (the power set).
 
 Note: The solution set must not contain duplicate subsets.
 Input: nums = [1,2,3]
 Output:
 [
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]
 */
vector<vector<int>> subsets(vector<int>& nums) {
    //dp[i]表示，第i位的数组可能出现的集合
    /*第i位的数字，相对于之前的dp[i-1],只有下面三种情况：
     1.nums[i]单独成一个结果
     2.dp[i-1]里面的每一项结果来说,nums[i-1]可以存在，也可以不存在
     3.空集合，任何元素都没
     */
    vector<vector<int>> dp[nums.size()];
    dp[0]=vector<vector<int>>{{nums[0]},{}};
    for (int i=1; i<nums.size(); i++) {
        vector<vector<int>> r;
        r.push_back({});
        //单独成一个结果
        r.push_back({nums[i]});
        for (auto &lastv : dp[i-1]) {
            if (lastv.empty()) {
                continue;
            }
            //nums[i]不存在于之前的结果中
            r.push_back(lastv);
            //存在于之前的结果中
            vector<int> newv(lastv);
            newv.push_back(nums[i]);
            r.push_back(newv);
        }
        dp[i]=r;
    }
    return dp[nums.size()-1];
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,2,3};
    auto x = subsets(nums);
    return 0;
}
