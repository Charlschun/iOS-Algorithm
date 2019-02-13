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
 https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 There are two sorted arrays nums1 and nums2 of size m and n respectively.
 
 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 
 You may assume nums1 and nums2 cannot be both empty.
 
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> vecs;
    int i,j;
    i = j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            vecs.push_back(nums1[i++]);
        }else{
            vecs.push_back(nums2[j++]);
        }
    }
    while (i < nums1.size()) {
        vecs.push_back(nums1[i++]);
    }
    while (j < nums2.size()) {
        vecs.push_back(nums2[j++]);
    }
    int mid = vecs.size() / 2;
    if (vecs.size() % 2) {
        //单数
        return vecs[mid];
    }
    return (vecs[mid-1] + vecs[mid])/2.0;
}
int main(int argc, const char * argv[]) {
    vector<int> a{1,2};
    vector<int> b{3,4};
    auto x = findMedianSortedArrays(a, b);
    return 0;
}
