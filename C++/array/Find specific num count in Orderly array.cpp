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
 在给定的一个已经排好序的数组中，找出指定数字出现的次数。例如数组[1,2,3,4,4,4,4,6,8,9]中4出现的次数为4次。
 */
int findSpecificCountInOrderlyArray(vector<int> &nums, int target){
    int count = 0;
    //首先通过二分查找找到对应的数
    int i = 0, j= nums.size() - 1, mid = i;
    while (i < j) {
        mid = i + (j - i) / 2;
        if (nums[mid] == target) {
            count++;
            int k = mid,m=mid;
            while (nums[--k] == target) {
                count++;
            }
            while (nums[++m] == target) {
                count++;
            }
            return count;
        }
        if (nums[mid] > target) {
            j = mid - 1;
        }else{
            i = mid + 1;
        }
    }
    return count;
};
int main(int argc, const char * argv[]) {
    vector<int> nums{1,2,3,4,4,4,4,6,8,9};
    cout << findSpecificCountInOrderlyArray(nums, 4) << endl;
    return 0;
}
