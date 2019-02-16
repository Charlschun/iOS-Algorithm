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
 https://leetcode-cn.com/problems/valid-parentheses/
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 An input string is valid if:
 
 Open brackets must be closed by the same type of brackets.
 Open brackets must be closed in the correct order.
 Note that an empty string is also considered valid.
 */
bool isValid(const string &s) {
    //()
    //()[]{}
    //{[]}
    //(] ([)]
    if (s.empty()) {
        return true;
    }
    int i = 0;
    vector<char> stack;//依次压入栈
    map<char ,char>c_c = {{'(',')'},{'{','}'},{'[',']'}};
    while (i < s.size()) {
        char c = s[i++];
        //顶层元素存在，并且匹配成功
        if (!stack.empty() && c_c[stack.back()] == c) {
            stack.pop_back();
        }else{
            stack.push_back(c);
        }
    }
    return stack.empty();
}
int main(int argc, const char * argv[]) {
    cout << isValid("()") << endl;
    cout << isValid("()[]{}") << endl;
    cout << isValid("{[]}") << endl;
    cout << isValid("([)]") << endl;
    return 0;
}
