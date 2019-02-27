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
 https://leetcode-cn.com/problems/plus-one/
 Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 
 The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
 
 You may assume the integer does not contain any leading zero, except the number 0 itself.
 
 Example 1:
 
 Input: [1,2,3]
 Output: [1,2,4]
 Explanation: The array represents the integer 123.
 Example 2:
 
 Input: [4,3,2,1]
 Output: [4,3,2,2]
 Explanation: The array represents the integer 4321.
 */
vector<int> plusOne(vector<int>& digits) {
    vector<int> res;
    int up=0;
    while (!digits.empty()) {
        int back;
        if (res.empty()) {
            back=digits.back()+1;
        }else{
            back=digits.back();
        }
        digits.pop_back();
        back=back+up;
        res.insert(res.begin(), back%10);
        up=back/10>0;
    }
    if (up>0) {
        res.insert(res.begin(), up);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> o{9,9,9};
    vector<int> plusone = plusOne(o);
    return 0;
}

