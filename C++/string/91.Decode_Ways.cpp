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
using namespace std;
/*
 https://leetcode-cn.com/problems/decode-ways/
 A message containing letters from A-Z is being encoded to numbers using the following mapping:
 
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given a non-empty string containing only digits, determine the total number of ways to decode it.
 
 Example 1:
 
 Input: "12"
 Output: 2
 Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 Example 2:
 
 Input: "226"
 Output: 3
 Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 */
int numDecodings(const string &s) {
    //1212
    if (s.empty() || s == "0") {
        return 0;
    }
    vector<int> dp(s.size() + 1,0);
    dp[0] = dp[1] = 1;
    //就像Fibonacci数列一样，我们从第三个数开始计算.
    for (int i = 2; i <= s.size(); i++) {
        int ct = s[i - 1] - '0';
        int pre = s[i - 2]  - '0';
        //如果当前的字符在1-9之间，decodings(0...i) = decoding(0...i-1)
        if (ct  >= 1 && ct <=9) {
            dp[i] = dp[i - 1];
        }
        //如果现在出现类似1212这样的字符,dp[i] = dp[i-2]的数量 + L(12)或者dp[i] = dp[i-1] + B(2)
        if ((pre == 1 || pre == 2) && ct>=0 && ct <= 6) {
            dp[i] += dp[i-2];
        }
    }
    return dp.back();
    
}
int main(int argc, const char * argv[]) {
    cout << numDecodings("110") << endl;
    return 0;
}
