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
 https://leetcode-cn.com/problems/maximum-subarray/
 Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 
 Example:
 
 Input: [-2,1,-3,4,-1,2,1,-5,4],
 Output: 6
 Explanation: [4,-1,2,1] has the largest sum = 6.
 */

int maxSubArray(const vector<int>& nums) {
    /*
     要记录前面的和与当前值之和当前值比较.谁大.
     将大的赋给 cursum
     然后就要将 res和cursum比较做更新.
     */
    if (nums.empty()) {
        return 0;
    }
    int maxsum = nums[0];
    int cursum=0;
    for (auto num : nums) {
        cursum = max(cursum+num, num);
        maxsum = max(maxsum, cursum);
    }
    return maxsum;
}

int dp_maxSubArray(const vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int dp[nums.size()];
    dp[0] = nums[0];
    int maxsum = dp[0];
    for (int i =1; i < nums.size(); i++) {
        dp[i]= max(dp[i-1] + nums[i], nums[i]);
        if (maxsum < dp[i]) {
            maxsum = dp[i];
        }
    }
    return maxsum;
}
int main(int argc, const char * argv[]) {
    cout << maxSubArray({-2,-1}) << endl;
    cout << dp_maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) << endl;
    return 0;
}
