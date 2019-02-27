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
 https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
 Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
 
 Example 1:
 Input: [1,3,5,4,7]
 Output: 3
 Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
 Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.

 */
int findLengthOfLCIS(const vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int res;
    int dp[nums.size()];
    dp[0]=1;
    for (int i=1; i<nums.size(); i++) {
        if (nums[i] > nums[i-1]) {
            dp[i]=dp[i-1]+1;
        }else{
            dp[i]=1;
        }
        res = max(res, dp[i]);
    }
    return res;
}

/*
 https://leetcode-cn.com/problems/longest-increasing-subsequence/
 Given an unsorted array of integers, find the length of longest increasing subsequence.
 
 Example:
 
 Input: [10,9,2,5,3,7,101,18]
 Output: 4
 Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 */
int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int dp[nums.size()];
    for (int i=0; i<nums.size(); i++) {
        dp[i]=1;
    }
    int res=1;
    for (int i=1; i<nums.size(); i++) {
        for (int j=0; j<i; j++) {
            if (nums[i]>nums[j]) {
                dp[i]=max(dp[j]+1, dp[i]);
            }
        }
        res=max(res, dp[i]);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{10,9,2,5,3,7,101,18};
    cout << findLengthOfLCIS(nums) << endl;
    cout << lengthOfLIS(nums) << endl;
    return 0;
}

