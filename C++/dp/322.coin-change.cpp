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
 https://leetcode-cn.com/problems/coin-change/
 You are given coins of different denominations and a total amount of money amount.
 Write a function to compute the fewest number of coins that you need to make up that amount.
 If that amount of money cannot be made up by any combination of the coins, return -1.
 
 Example 1:
 
 Input: coins = [1, 2, 5], amount = 11
 Output: 3
 Explanation: 11 = 5 + 5 + 1
 Example 2:
 
 Input: coins = [2], amount = 3
 Output: -1
 */
//version1递归
int func(vector<int>& coins, int amount) {
    if (coins.empty() && amount != 0) {
        return -1;
    }
    int maxcoin = coins.back();
    if (amount > maxcoin) {
        int res = func(coins, amount-maxcoin);
        return  res == -1 ? -1 : res+1;
    }else if (amount == maxcoin){
        return  1;
    }else{
        coins.pop_back();
        return  func(coins, amount);
    }
}
//version2:dp
int coinChange(vector<int>& coins, int amount) {
    int dp[amount+1];
    //默认值
    for (int i=0; i<amount+1; i++) {
        dp[i]=amount+1;
    }
    //dp[i]储存的是金额为i需要的最小硬币数
    dp[0]=0;
    for (int i=0; i<amount+1; i++) {
        //计算金币为amout需要多少个硬币
        for (auto coin: coins) {
            if (i>=coin) {
                //获取之前的硬币数和现在的组合(i-coin,coin)的最小值
                dp[i]=min(dp[i-coin]+1, dp[i]);
            }
        }
    }
    return dp[amount]==amount+1 ? -1: dp[amount];
}
int main(int argc, const char * argv[]) {
    vector<int> nums{2};
    cout << coinChange(nums,3) << endl;
    return 0;
}
