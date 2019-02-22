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
 https://leetcode-cn.com/problems/unique-paths/
 A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 
 The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 
 How many possible unique paths are there?
 */
//m列 n行
int uniquePaths(int m, int n) {
    
    int dp[n][m];
    dp[0][0]=1;
    for (int i=0; i<n; i++) {
        dp[i][0]=1;
    }
    for (int i=0; i<m; i++) {
        dp[0][i]=1;
    }
    //dp[n][m] = dp[n-1][m]+dp[n][m-1]
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            dp[i][j]=dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}
int main(int argc, const char * argv[]) {
    cout << uniquePaths(7, 3) << endl;
    return 0;
}
