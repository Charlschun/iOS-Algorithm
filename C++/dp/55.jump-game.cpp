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
 https://leetcode-cn.com/problems/jump-game/
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 
 Each element in the array represents your maximum jump length at that position.
 
 Determine if you are able to reach the last index.
 
 Example 1:
 
 Input: [2,3,1,1,4]
 Output: true
 Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 Example 2:
 
 Input: [3,2,1,0,4]
 Output: false
 Explanation: You will always arrive at index 3 no matter what. Its maximum
 jump length is 0, which makes it impossible to reach the last index.
 */
bool canJump(vector<int>& nums) {
    int dp[nums.size()];
    //dp[i]存储的是i位置能走的最大步数.从前一步的最大步数减一和当前下标对应步数中选择最大的一个，因为最大的数能保证我们走的更远
    for (int i=0; i<nums.size(); i++) {
        if (i==0 && nums[i]!=0) {
            dp[0]=nums[i];
            continue;
        }else if (i==0 && nums[i]==0){
            return false;
        }
        dp[i]=max(nums[i], dp[i-1]-1);
        if (dp[i] <=0 && i!=nums.size()-1) {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{3,2,1,0,4};
    cout << canJump(nums) << endl;
    return 0;
}
