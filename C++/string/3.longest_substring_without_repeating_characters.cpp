
//
//  main.cpp
//  LeetCode
//
//  Created by junl on 2019/1/21.
//  Copyright © 2019 junl. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <deque>
using namespace std;
//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
int lengthOfLongestSubstring(string s) {
    //abcabcbb return 3
    //pwwkew 3
    int left,right;//两个下标分别表示划线的左右两头
    left = right = 0;
    int max_length = 0;
    map<char,int> m;
    while (right < s.size()) {
        //首先得有一个集合来保存不一样的元素
        //发现相同元素以后，怎么移动下标
        char ch = s[right];
        auto item = m.find(ch);
        //如果找到末尾都没找到,或者找到了但是不在left,right之间.
        if (item == m.end() || m[ch] < left) {
            max_length = max(right - left + 1, max_length);
        }else{
            left = m[ch] + 1;
        }
        m[ch] = right;
        right++;
    }
    return max_length;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s("abcabcbb");
    lengthOfLongestSubstring(s);
    
    return 0;
}
