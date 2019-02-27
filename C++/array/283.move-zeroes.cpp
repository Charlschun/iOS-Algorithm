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
#include <vector>
using namespace std;
/*
 https://leetcode-cn.com/problems/move-zeroes/
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 
 Example:
 
 Input: [0,1,0,3,12]
 Output: [1,3,12,0,0]
 Note:
 
 You must do this in-place without making a copy of the array.
 Minimize the total number of operations.
 */
//双指针移动法
void moveZeroes(vector<int>& nums) {
    int j=0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i]!=0) {
            nums[j++]=nums[i];
        }
    }
    while (j<nums.size()) {
        nums[j++]=0;
    }
}
void moveZeroes_v2(vector<int>& nums) {
    int i=0;
    int right=nums.size();
    while (i < right) {
        if (nums[i]==0) {
            for (int j=i+1; j<nums.size(); j++) {
                nums[j-1]=nums[j];
            }
            right=nums.size()-i-1;
            nums[right]=0;
        }else{
            i++;
        }
    }
}
int main(int argc, const char * argv[]) {
    vector<int> o{0,0};
    moveZeroes(o);
    return 0;
}

