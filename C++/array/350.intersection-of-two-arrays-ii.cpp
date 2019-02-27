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
 https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
 */
vector<int> intersect(const vector<int>& nums1,const  vector<int>& nums2) {
    vector<int> res;
    map<int,int> mm;
    for (int i=0; i<nums1.size(); i++) {
        if (mm.count(nums1[i])==0) {
            mm[nums1[i]]=1;
        }else{
            mm[nums1[i]]++;
        }
    }
    for (int i=0; i<nums2.size(); i++) {
        if (mm[nums2[i]] > 0) {
            res.push_back(nums2[i]);
            mm[nums2[i]]--;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> t= intersect({4,9,5}, {9,4,9,8,4}) ;
    return 0;
}

