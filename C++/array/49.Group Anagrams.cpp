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
using namespace std;
/*
 https://leetcode-cn.com/problems/group-anagrams/
 Given an array of strings, group anagrams together.
 
 Example:
 
 Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 Output:
 [
 ["ate","eat","tea"],
 ["nat","tan"],
 ["bat"]
 ]
 Note:
 
 All inputs will be in lowercase.
 The order of your output does not matter.

 */

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> vv;
    map<string,vector<string>> mm;
    for (auto str : strs) {
        string copy = str;
        sort(str.begin(), str.end());
        auto &s = mm[str];
        s.push_back(copy);
    }
    for (auto &m : mm) {
        vv.push_back(m.second);
    }
    return vv;
}


int main(int argc, const char * argv[]) {
    vector<string> vs{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto vv = groupAnagrams(vs);
    return 0;
}
