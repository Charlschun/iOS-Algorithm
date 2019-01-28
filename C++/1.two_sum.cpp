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
using namespace std;
namespace Solution {
    //https://leetcode-cn.com/problems/two-sum/
    vector<int> twoSum(vector<int>& nums, int target) {
        //dic[index] = target - index
        map<int , int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            //判断是否存在
            if (m.count(t)) {
                res.push_back(i);
                res.push_back(m[t]);
                break;
            }else{
                m[nums[i]] = i;
            }
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;
    auto result = Solution::twoSum(nums, target);
    return 0;
}
