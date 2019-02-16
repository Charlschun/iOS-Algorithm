//
//  main.cpp
//  LeetCode
//
//  Created by junl on 2019/1/21.
//  Copyright © 2019 junl. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
/*
 https://leetcode-cn.com/problems/longest-palindromic-substring/
 Given a string s, find the longest palindromic substring in s.
 You may assume that the maximum length of s is 1000.
 Example 1:
 
 Input: "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.
 Example 2:
 
 Input: "cbbd"
 Output: "bb"
 
 
 回文字符串是以中心为对称的，因此我们可以通过这个角度来解答
 */
int palindromeLength(const string &s,int left,int right);
string longestPalindrome(const string &s) {
    
    size_t left = 0,right = 0;
    for (int i = 0; i < s.size(); i++) {
        //以s[i]为中心点
        int len1 = palindromeLength(s, i, i);
        //以s[i+1]为中心店
        int len2 = palindromeLength(s, i, i + 1);
        int max = len1 > len2 ? len1 : len2;
        //找到了比较长的回文
        if (max > right - left) {
            // abac  i = 1,max = 3
            // cabac i = 2, max = 3
            // abbc  i = 1 , max = 2
            right = max/2 + i;
            left =  i - (max-1)/2;
        }
        
    }
    return s.substr(left,right-left+1);
}
int palindromeLength(const string &s,int left,int right){
    // abac
    int i = left,j=right;
    while (i>=0 && j<s.size() && s[i] == s[j]) {
        i--;
        j++;
    }
    return j - i - 1;
}

int main(int argc, const char * argv[]) {
    
    cout << longestPalindrome("babad") << endl;
    cout << longestPalindrome("cbbd") << endl;
    return 0;
}
