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
/*
 https://leetcode-cn.com/problems/implement-strstr/
 Implement strStr().
 
 Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 
 Example 1:
 
 Input: haystack = "hello", needle = "ll"
 Output: 2
 Example 2:
 
 Input: haystack = "aaaaa", needle = "bba"
 Output: -1
 Clarification:
 
 What should we return when needle is an empty string? This is a great question to ask during an interview.
 
 For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 */
using namespace std;
int strStr(const string &haystack, const string &needle) {
    if (needle.empty()) {
        return 0;
    }
    int i = 0 , j = 0;
    while (i < haystack.size()) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
            if (j == needle.size()) {
                //
                return i - needle.size();
            }
        }else{
            i = i - j + 1;
            j = 0;
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    cout << strStr("hello", "ll") << endl;
    return 0;
}
