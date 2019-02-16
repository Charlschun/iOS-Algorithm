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
 https://leetcode-cn.com/problems/roman-to-integer/
 Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 
 Symbol       Value
 I             1
 V             5
 X             10
 L             50
 C             100
 D             500
 M             1000
 For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
 
 Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 
 I can be placed before V (5) and X (10) to make 4 and 9.
 X can be placed before L (50) and C (100) to make 40 and 90.
 C can be placed before D (500) and M (1000) to make 400 and 900.
 Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 */
int romanToInt(const string &s) {
    //symbol可以重复,表示相加，比如III = 3;最多有三个字符
    //通常情况下罗马数字小的数字在大的数字的右边.但也有另外比如IV,IX
    map<char, int> c_i{
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    int i = 0;
    int sum = 0;
    char lastC = 0;//上一个字符
    while (i < s.size()) {
        char c = s[i];
        if (lastC == 0) {
            sum += c_i[c];
        }else if(c_i[lastC] >= c_i[c]){//如果第二个字符比第一个字符小,或者相等，直接相加 III VI
            sum += c_i[c];
        }else if ( c_i[c] > c_i[lastC]){//匹配IV,IX
            //c = i,先保存这个值
            sum += (c_i[c] - c_i[lastC]);
            sum -= c_i[lastC];//这是上一个条件多加出来的,需要减去
        }
        lastC = c;
        i++;
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    cout << romanToInt("III") << endl;
    cout << romanToInt("IV") << endl;
    cout << romanToInt("IX") << endl;
    cout << romanToInt("LVIII") << endl;
    cout << romanToInt("MCMXCIV") << endl;
    return 0;
}
