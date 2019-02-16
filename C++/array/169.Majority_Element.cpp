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
 https://leetcode-cn.com/problems/majority-element/
 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 
 You may assume that the array is non-empty and the majority element always exist in the array.
 
 Example 1:
 
 Input: [3,2,3]
 Output: 3
 Example 2:
 
 Input: [2,2,1,1,1,2,2]
 Output: 2
 
 思路：去掉两个相邻数中不相等的数
 */
int majorityElement(vector<int>& nums) {
    
    int i = 0;
    vector<int> stack;
    while (i < nums.size()) {
        if (!stack.empty() && nums[i] != stack.back()) {
            stack.pop_back();
        }else{
            stack.push_back(nums[i]);
        }
        i++;
    }
    return stack.back();
}

/*
 Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 
 Note: The algorithm should run in linear time and in O(1) space.
 
 Example 1:
 
 Input: [3,2,3]
 Output: [3]
 Example 2:
 
 Input: [1,1,1,3,3,2,2,2]
 Output: [1,2]
 
 摩尔投票:超过n/3的最多只有两个
 1.选择两个投票数，如果选择他们的话，则计数器+1
 2.如果不选择他们的话，计数器--,并且处理候选者更新.
 3.判断候选者是否超过了n/3
 */
vector<int> majorityElement_1_3(vector<int>& nums) {
    vector<int> result;
    if (nums.empty()) {
        return {};
    }
    int count1,count2,candidate1,candidate2;
    count1 = count2 = 0;
    candidate1 = candidate2 = nums[0];
    
    for (auto num  : nums) {
        if (num == candidate1) {
            count1++;
            continue;
        }
        if (num == candidate2) {
            count2++;
            continue;
        }
        //如果不选择的话，那么计算器--
        if (count1 == 0) {
            candidate1 = num;
            count1++;
            continue;
        }
        if (count2 == 0) {
            candidate2 = num;
            count2++;
            continue;
        }
        count1--;
        count2--;
    }
    count1 = count2 = 0;
    for (auto num  : nums) {
        if (num == candidate1) {
            count1++;
        }else if (num == candidate2){
            count2++;
        }
    }
    if (count1 > nums.size() / 3) {
        result.push_back(candidate1);
    }
    if (count2 > nums.size() / 3) {
        result.push_back(candidate2);
    }
    //找到了两个候选者
    return result;
}

ostream& operator<<(ostream &out,vector<int>v){
    for (auto  x: v) {
        out << x << " ";
    }
    return out;
}

int main(int argc, const char * argv[]) {
    
    vector<int> nos{2,2,1,1,1,2,2};
    cout << majorityElement(nos) << endl;
    
    nos = {2,2,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9};
    ;
    cout << majorityElement_1_3(nos) << endl;
    return 0;
}
