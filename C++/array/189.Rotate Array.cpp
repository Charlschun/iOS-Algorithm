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
 Given an array, rotate the array to the right by k steps, where k is non-negative.
 
 Example 1:
 
 Input: [1,2,3,4,5,6,7] and k = 3
 Output: [5,6,7,1,2,3,4]
 Explanation:
 rotate 1 steps to the right: [7,1,2,3,4,5,6]
 rotate 2 steps to the right: [6,7,1,2,3,4,5]
 rotate 3 steps to the right: [5,6,7,1,2,3,4]
 */
void rotate_v1(vector<int>& nums, int k) {
    int size = nums.size();
    k %=size;
    for (int i = 0; i < k; i++) {
        int temp = nums[size-1];
        nums.erase(nums.end()-1);
        nums.insert(nums.begin(), temp);
    }
}

void reverse(vector<int> &nums,int begin,int end){
    while (begin < end) {
        int temp = nums[begin];
        nums[begin++] = nums[end];
        nums[end--] = temp;
    }
}

void rotate_v2(vector<int>& nums, int k) {
    int size = nums.size();
    k %=size;
    reverse(nums, 0,size-1);//7654321
    reverse(nums, 0,k-1);//5674321
    reverse(nums, k,size-1);//5671234
}



int main(int argc, const char * argv[]) {
    vector<int> nums{1,2,3,4,5,6,7};
//    rotate_v1(nums,3);
    rotate_v2(nums, 3);
    return 0;
}
