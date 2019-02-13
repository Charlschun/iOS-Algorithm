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
 https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others/
 In a given integer array nums, there is always exactly one largest element.
 
 Find whether the largest element in the array is at least twice as much as every other number in the array.
 
 If it is, return the index of the largest element, otherwise return -1.
 
 Example 1:
 
 Input: nums = [3, 6, 1, 0]
 Output: 1
 Explanation: 6 is the largest integer, and for every other number in the array x,
 6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 
 
 Example 2:
 
 Input: nums = [1, 2, 3, 4]
 Output: -1
 Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
 */
int dominantIndex_v1(const vector<int>& nums) {
    int max_index = 0;
    for (int i =1; i < nums.size(); i++) {
        if (nums[max_index] < nums[i]) {
            max_index = i;
        }
    }
    for (int i =0; i < nums.size(); i++) {
        if (i != max_index ) {
            if (nums[max_index] < nums[i] * 2) {
                return -1;
            }
        }
    }
    return max_index;
}
int dominantIndex_v2(const vector<int>& nums) {
    int max_index = 0;
    int secondMax_index = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[max_index]) {
            secondMax_index = max_index;
            max_index = i;
        }else if (nums[i] > nums[secondMax_index]){
            secondMax_index = i;
        }
    }
    return nums[max_index] >= nums[secondMax_index] * 2 ? max_index : -1;
}
int main(int argc, const char * argv[]) {
    cout << dominantIndex_v2({3,6,1,0});
    return 0;
}
