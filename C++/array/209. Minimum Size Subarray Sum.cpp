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
 Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 
 Example:
 
 Input: s = 7, nums = [2,3,1,2,4,3]
 Output: 2
 Explanation: the subarray [4,3] has the minimal length under the problem constraint.
 Follow up:
 If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 双指针
 */
int minSubArrayLen(int s, vector<int>& nums) {
    int i=0,j=0;
    //要求j-i最小
    int len = 0;
    while (i < nums.size()) {
        int sum = nums[i];
        if (sum >= s) {
            return 1;
        }
        j=i;
        while (j < nums.size()) {
            if (sum >= s) {
                //find
                if (len == 0) {
                    len = j-i+1;
                }else{
                    len = min(j - i + 1, len);
                }
                break;
            }else if (sum < s){
                j++;
                sum += nums[j];
            }else{
                break;
            }
        }
        i++;
    }
    return len;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,2,3,4,5};
    cout << minSubArrayLen(11,nums);
    return 0;
}
