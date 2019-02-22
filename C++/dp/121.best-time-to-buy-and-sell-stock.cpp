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
 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 
 Note that you cannot sell a stock before you buy one.
 
 Input: [7,1,5,3,6,4]
 Output: 5
 Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 Not 7-1 = 6, as selling price needs to be larger than buying price.
 */
int maxProfit(const vector<int>& prices) {
    if (prices.size() < 2) {
        return 0;
    }
    int dp[prices.size()];
    dp[0]=-prices[0];
    int res = dp[0];
    for (int i=1; i<prices.size(); i++) {
        //dp[i-1]表示买进股票的钱
        //prices[i]表示卖掉股票的钱
        dp[i]= (dp[i-1]+prices[i])<0?-prices[i]:dp[i-1];
        res = max(prices[i]+dp[i], res);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout << maxProfit({7,1,5,3,6,4}) << endl;
    return 0;
}
