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
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 
 Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 
 Example 1:
 
 Input: [7,1,5,3,6,4]
 Output: 7
 Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
 */
//暴力法,递归卖出求最大值
int maxProfit(const vector<int>& prices,int buy_start){
    if (buy_start >= prices.size()) {
        return 0;
    }
    int maxmoney = 0;
    for (int b_s=buy_start; b_s<prices.size(); b_s++) {
        int max_=0;
        for (int b_e=b_s+1; b_e < prices.size(); b_e++) {
            if (prices[b_e] > prices[b_s]) {
                //卖出
                max_=max(max_, prices[b_e]-prices[b_s] + maxProfit(prices, b_e+1));
            }
        }
        maxmoney = max(maxmoney, max_);
    }
    return maxmoney;
}
int maxProfit(const vector<int>& prices) {
    return maxProfit(prices, 0);
}
//贪心算法
/*
 炒股想挣钱当然是低价买入高价抛出，那么这里我们只需要从第二天开始，
 如果当前价格比之前价格高，则把差值加入利润中，因为我们可以昨天买入，今日卖出，若明日价更高的话，还可以今日买入，明日再抛出
 */
int maxProfit_v2(const vector<int>& prices){
    int maxprofit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1])
            maxprofit += prices[i] - prices[i - 1];
    }
    return maxprofit;
}
int main(int argc, const char * argv[]) {
    cout << maxProfit({7,1,5,3,6,4}) << endl;
    cout << maxProfit_v2({7,1,5,3,6,4}) << endl;
    return 0;
}
