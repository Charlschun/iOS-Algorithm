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
 
 (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 
 Find the minimum element.
 
 You may assume no duplicate exists in the array.
 
 Example 1:
 
 Input: [3,4,5,1,2]
 Output: 1
 Example 2:
 
 Input: [4,5,6,7,0,1,2]
 Output: 0
 
 最小的数有个特点,两边的数都比它大
 */
int findMin(vector<int>& nums) {
    //从左往右越来越大
    //[4,5,6,7,0,1,2]
    //[1,2,4,5,6,7,0]//最小值在最右边
    //[7,0,1,2,4,5,6]
    //[5,6,7,0,1,2,4]
    
    int i = 0 ,j = nums.size() - 1;
    int result = nums[0];
    while (i < j) {
        int mid = i + (j - i) / 2;
        //如果中间比最右边大的话，那么肯定在右边
        if (nums[mid] > nums[j]) {
            i = mid + 1;
        }else{
            //否则可能在左边或中间
            j = mid;
        }
    }
    
    return nums[i];
}

int findMin2(vector<int> &nums){
    int l = 0,r = static_cast<int>(nums.size()) - 1;
    int mid = 0;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (mid == nums.size() - 1) {
            return min(nums[mid], nums[l]);
        }
        if (mid == 0) {
            return min(nums[mid], nums[r]);
        }
        
        //如果是波谷的话,找到
        if (nums[mid] < nums[mid - 1]  && nums[mid] < nums[mid + 1]) {
            return nums[mid];
        }
        if (nums[mid] > nums[r]) {
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return nums[l];
}

int main(int argc, const char * argv[]) {
    vector<int> nums{4,5,6,7,0,1,2};
    cout << findMin2(nums) << endl;
    return 0;
}
