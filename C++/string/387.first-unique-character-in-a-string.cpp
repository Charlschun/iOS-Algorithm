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
#include <vector>
using namespace std;
/*
 Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
 
 Examples:
 
 s = "leetcode"
 return 0.
 
 s = "loveleetcode",
 return 2.
 Note: You may assume the string contain only lowercase letters.
 */
int firstUniqChar(const string &s) {
    //因为都是小写字母，所以可以把计数保存在a[26]里面，然后判断个数
    array<int, 26> mm{};
    for (int i=0; i<s.size(); i++) {
        char c = s[i];
        mm[c-'a']++;
    }
    
    for (int i=0; i<s.size(); i++) {
        if (mm[s[i]-'a']==1) {
            return i;
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    vector<int> o{0,0};
    cout <<firstUniqChar("leetcode");
    return 0;
}

