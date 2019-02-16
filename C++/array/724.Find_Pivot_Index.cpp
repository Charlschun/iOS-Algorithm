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
/*
 https://leetcode-cn.com/problems/find-pivot-index/
 Given an array of integers nums, write a method that returns the "pivot" index of this array.
 
 We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.
 
 If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.
 
 Example 1:
 Input:
 nums = [1, 7, 3, 6, 5, 6]
 Output: 3
 Explanation:
 The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
 Also, 3 is the first index where this occurs.
 Example 2:
 Input:
 nums = [1, 2, 3]
 Output: -1
 Explanation:
 There is no index that satisfies the conditions in the problem statement.
 
 思路一:先计算出sum，然后sum减去当前值，如果结果等于左边的总和，说明找到了
 */
int pivotIndex_v1(const vector<int>& nums) {
    if (nums.size() < 3) {
        return -1;
    }
    int sum = 0;
    for (auto num : nums) {
        sum+=num;
    }
    int leftsum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if ((sum-nums[i])/2.0 == leftsum) {
            return i;
        }
        leftsum+=nums[i];
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    cout << pivotIndex_v1({-1,-1,-1,-1,-1,-1}) << endl;
    return 0;
}
