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
  DP的核心思想是记住已经解决过的子问题的解,然后通过子问题的解推导出问题的解
 */
int Fibonacci2(int n){
    int s[n+1];
    s[0]=1;
    s[1]=1;
    int i = 2;
    while (i<=n) {
        s[i]=s[i-1]+s[i-2];
        i++;
    }
    return s[n];
};
//             1 2 3 4 5  6  7  8  9  10
int PRICE[] = {1,5,8,9,10,17,17,20,24,30};
int cut(int n){
    int res=0;
    int dp[n+1];
    dp[0]=0;
    for (int i=1; i<n+1; i++) {
        int max = -1;
        //现在计算dp[i],i米的钢筋的切割法中最优解
        //分别求出切割成1米+dp[i-1],2米+dp[i-2],.......的最大值
        for (int j=1; j<=i; j++) {
            max = std::__1::max(max, PRICE[j-1]+dp[i-j]);
        }
        dp[i]=max;
    }
    return dp[n];
}

int cut_recursive(int n){
    if (n==0)return 0;
    int q = -1;
    for (int i=1; i<n+1; i++) {
        q=max(q, PRICE[i-1]+cut_recursive(n-i));
    }
    return q;
}
int main(int argc, const char * argv[]) {
    cout << Fibonacci2(5) << endl;
    cout << cut(20) << endl;
    cout << cut_recursive(20) << endl;
    return 0;
}
