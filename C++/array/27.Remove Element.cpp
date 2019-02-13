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
 https://leetcode-cn.com/problems/remove-element/
 Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 
 Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 
 Example 1:
 
 Given nums = [3,2,2,3], val = 3,
 
 Your function should return length = 2, with the first two elements of nums being 2.
 
 It doesn't matter what you leave beyond the returned length.
 
 双指针法
 */
int removeElement(vector<int>& nums, int val) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k++] = nums[i];
        }
    }
    return k;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,4,2,2,3};
    int len = removeElement(nums, 2);
    return 0;
}
