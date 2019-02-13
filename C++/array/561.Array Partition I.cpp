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
 https://leetcode-cn.com/problems/array-partition-i/
 Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
 
 Example 1:
 Input: [1,4,3,2]
 
 Output: 4
 Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
 */
int arrayPairSum( vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int i = 1;
    int sum = 0;
    while (i < nums.size()) {
        sum += nums[i-1];
        i+=2;
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,4,3,2};
    cout << arrayPairSum(nums);
    return 0;
}
