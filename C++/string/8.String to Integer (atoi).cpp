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
 https://leetcode-cn.com/problems/string-to-integer-atoi/
 Implement atoi which converts a string to an integer.
 
 The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 
 The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 
 If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 
 If no valid conversion could be performed, a zero value is returned.
 */
int myAtoi(string &str) {
    //1.忽略' '
    //2.起始可以为+/-
    //3.末尾的字符可以被忽略
    int i = 0;
    bool positive = true;//是否是正数
    bool hasFirstNum = false;
    int r = 0;
    
    string s;
    while (i < str.size()) {
        char c = str[i];
        if (c >= '0' && c<= '9') {
            hasFirstNum = true;
            //保存有效字符到s里
            s += c;
            i++;
        }else if (c == '+' || c == '-'){
            positive = c == '+' ? true : false;
            i++;
        }else if (c == ' '){
            if (!hasFirstNum) {
                i++;
                continue;
            }else{
                break;
            }
        }
        else{
            break;
        }
    }
    i = 0;
    while (i < s.size()) {
        char c = s[i];
        r += pow(10, s.size() - i - 1)*(c-'0');
        i++;
    };
    if (!positive) {
        r*=-1;
    }
    if (r > INT_MAX) {
        return INT_MAX;
    }
    if (r < INT_MIN) {
        return INT_MIN;
    }
    return r;
}
int main(int argc, const char * argv[]) {
    string s("   -123tq");
    cout << myAtoi(s) << endl;
    return 0;
}
