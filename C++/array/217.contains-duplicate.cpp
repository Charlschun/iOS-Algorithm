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
 https://leetcode-cn.com/problems/contains-duplicate/
 
 Given an array of integers, find if the array contains any duplicates.
 
 Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 
 Example 1:
 
 Input: [1,2,3,1]
 Output: true
 Example 2:
 
 Input: [1,2,3,4]
 Output: false
 Example 3:
 
 Input: [1,1,1,3,3,4,3,2,4,2]
 Output: true
 */
bool containsDuplicate(const vector<int>& nums) {
    map<int,int>mm;
    for (int i=0; i<nums.size(); i++) {
        if (mm.count(nums[i])!=0) {
            return true;
        }else{
            mm[nums[i]]=1;
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    cout << containsDuplicate({1,2,3,1});
    return 0;
}

