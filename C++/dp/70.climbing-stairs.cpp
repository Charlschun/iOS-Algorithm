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
using namespace std;
/*
 https://leetcode-cn.com/problems/climbing-stairs/
 You are climbing a stair case. It takes n steps to reach to the top.
 
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 
 Note: Given n will be a positive integer.
 
 Example 1:
 
 Input: 2
 Output: 2
 Explanation: There are two ways to climb to the top.
 1. 1 step + 1 step
 2. 2 steps
 */
int climbStairs(int n) {
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    
    for (int i =3; i <n+1; i++) {
        //两种走法
        //1. 走一步,那么剩下的i-1有dp[i-1]种走法
        //2. 走二步,dp[i-2]
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(int argc, const char * argv[]) {
    cout << climbStairs(3) << endl;
    return 0;
}
