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
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 
 (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 
 You may assume no duplicate exists in the array.
 
 Your algorithm's runtime complexity must be in the order of O(log n).
 
 Example 1:
 
 Input: nums = [4,5,6,7,0,1,2], target = 0
 Output: 4
 Example 2:
 
 Input: nums = [4,5,6,7,0,1,2], target = 3
 Output: -1
 */

int search(vector<int>& nums, int target) {
    //5,6,7,0,1,2,4
    int l = 0,r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) /2;
        if (nums[mid] == target) {
            return mid;
        }
        
        //说明右边是无序的
        if (nums[r]  < nums[mid]) {
            //因为左边是有序的，所以拿左边的第一个h值和target比较
            if (nums[l] <= target && nums[mid] > target) {
                r = mid - 1;
            }else{
                l = mid  + 1;
            }
            
        }else{
            //右边是有序的
            if (nums[r] >= target && nums[mid] < target) {
                l = mid + 1;
            }else{
                r = mid - 1;
            }
            
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{4,5,6,7,0,1,2};
    int target = 0;
    cout << search(nums,target) << endl;
    return 0;
}
