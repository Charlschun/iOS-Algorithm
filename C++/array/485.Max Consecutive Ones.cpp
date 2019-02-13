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
 Given a binary array, find the maximum number of consecutive 1s in this array.
 
 Example 1:
 Input: [1,1,0,1,1,1]
 Output: 3
 Explanation: The first two digits or the last three digits are consecutive 1s.
 The maximum number of consecutive 1s is 3.
 
 双指针
 */
int findMaxConsecutiveOnes(vector<int>& nums) {
    auto it1= nums.begin();
    auto it2= nums.begin();
    int count=0;
    while (it2 != nums.end()) {
        if (*it2 == 1) {
            it2++;
        }else{
            count = it2 - it1 > count ? it2 - it1 : count;
            it2++;
            it1= it2;
        }
    }
    if (it1 + 1 <=it2) {
        count = it2 - it1 > count ? it2 - it1 : count;
    }
    return count;
    
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,1,0,1,1,1};
    cout << findMaxConsecutiveOnes(nums);
    return 0;
}
