//
//  main.cpp
//  LeetCode
//
//  Created by junl on 2019/1/21.
//  Copyright © 2019 junl. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <deque>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //nums1和nums2是有序数组,找中位数
    //1.合并这两个数组
    //2.找到中位数
    //1,2,3,4,5
    //6,7
    
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
    // insert code here...
    vector<int> nums1{1,2,3,4};
    vector<int> nums2{6,7,8};
    int num = findMedianSortedArrays(nums1, nums2);
    cout << num << endl;
    return 0;
}
