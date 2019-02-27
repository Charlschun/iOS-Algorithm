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
 https://leetcode-cn.com/problems/single-number/
 Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 
 Note:
 
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 
 Example 1:
 
 Input: [2,2,1]
 Output: 1
 */
//异或：相同为0，不同为1. 异或同一个数两次，原数不变。

int singleNumber(const vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int res=0;
    for (auto c : nums) {
        res = res ^ c;
        cout << res << " ";
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout << singleNumber({2,1,2,3,3}) ;
    return 0;
}

