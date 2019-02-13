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
 https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 
 Example 1:
 
 Input: [3,2,1,5,6,4] and k = 2
 Output: 5
 Example 2:
 
 Input: [3,2,3,1,2,4,5,5,6] and k = 4
 Output: 4
 
 */
void creatHeap(vector<int> &nums, int i, int size);
int findKthLargest(vector<int>& nums, int k) {
    //堆排序
    //构建一个大顶堆
    for (int i = nums.size() / 2  - 1; i >= 0; i--) {
        creatHeap(nums, i , nums.size());
    }
    //寻找第k个
    int j =  nums.size() - 1;
    for (; j > 0; j--) {
        if (nums.size() - j  == k) {
            break;
        }
        swap(nums[j], nums[0]);
        creatHeap(nums, 0, j);
    }
    return nums[0];
}
void creatHeap(vector<int> &nums, int i, int size){
    int left = 2 * i + 1;
    int temp = nums[i];
    for (; left+1 <= size; left = left * 2 +1) {
        if (left + 1 < size && nums[left] < nums[left+1]) {
            left++;
        }
        if (nums[left] > temp) {
            nums[i] = nums[left];
            i = left;
        }else{
            break;
        }
    }
    nums[i] = temp;
}
int main(int argc, const char * argv[]) {
    vector<int > nums{3,2,3,1,2,4,5,5,6};
    cout << findKthLargest(nums, 4) << endl;
    return 0;
}
