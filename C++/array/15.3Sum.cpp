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
using namespace std;

/*
 https://leetcode-cn.com/problems/3sum/
 Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 
 Note:
 
 The solution set must not contain duplicate triplets.
 
 Example:
 
 Given array nums = [-1, 0, 1, 2, -1, -4],
 
 A solution set is:
 [
 [-1, 0, 1],
 [-1, -1, 2]
 ]
 
 1.先将数组按照升序拍好顺序，然后固定第一个数nums[i]
 2.问题就转换为，在一个有序数组中找两个数字和为-nums[i].
 3.可以想到使用左右指针移动法，start，end，如果结果小于0，start向前移动，如果>0，end向后移动
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> vvec;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        int a1 = nums[i];
        //如果第一个都大于0，直接退出
        if (a1 > 0) {
            break;
        }
        if (nums[i] == nums[i-1]) {
            continue;
        }
        int start = i + 1,end = nums.size() - 1;
        while (start < end) {
            int sum = a1 + nums[start] + nums[end];
            if (sum == 0) {
                //find
                vvec.push_back({a1,nums[start++],nums[end--]});
                //跳过重复的
                while (start < nums.size() && nums[start] == nums[start-1]) {
                    start++;
                }
                while (end >= 0 && nums[end] == nums[end+1] ) {
                    end--;
                }
            }else if (sum < 0){
                start++;
            }else{
                end--;
            }
        }
        
    }
    return vvec;
}
int main(int argc, const char * argv[]) {
    vector<int> ns{-1, 0, 1, 2, -1, -4};
    threeSum(ns);
    return 0;
}
