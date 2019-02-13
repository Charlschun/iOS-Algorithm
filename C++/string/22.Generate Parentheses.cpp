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
 https://leetcode-cn.com/problems/generate-parentheses/
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 
 For example, given n = 3, a solution set is:
 
 [
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
 ]
 对于这种列出所有结果的题首先还是考虑用递归Recursion来解，由于字符串只有左括号和右括号两种字符，而且最终结果必定是左括号3个，右括号3个，所以我们定义两个变量left和right分别表示剩余左右括号的个数，如果在某次递归时，左括号的个数大于右括号的个数，说明此时生成的字符串中右括号的个数大于左括号的个数，即会出现')('这样的非法串，所以这种情况直接返回，不继续处理。如果left和right都为0，则说明此时生成的字符串已有3个左括号和3个右括号，且字符串合法，则存入结果中后返回。如果以上两种情况都不满足，若此时left大于0，则调用递归函数，注意参数的更新，若right大于0，则调用递归函数，同样要更新参数。
 */
void generateParenthesis(int lp,int rp, string s ,vector<string> & svec);
void generateParenthesis2(int lp,int rp,int n, string s ,vector<string> &svec);
vector<string> generateParenthesis(int n) {
    //n=1  () 有一个左括号
    //n=2  ()()   (())  有两个左括号
    vector<string> s;
    string temp;
    generateParenthesis(n, n, temp, s);
    return s;
}

void generateParenthesis(int lp,int rp, string s ,vector<string> & svec){
    if (lp > rp || lp <0 || rp < 0) {
        return ;
    }
    if (lp == 0 && rp == 0) {
        svec.push_back(s);
    }
    generateParenthesis(lp-1, rp, s+'(', svec);
    generateParenthesis(lp, rp-1, s+')', svec);
    return ;
}

#pragma mark - 第二种方法
vector<string> generateParenthesis2(int n){
    vector<string> s;
    string temp;
    generateParenthesis2(0, 0, n , temp, s);
    return s;
};
void generateParenthesis2(int lp,int rp,int N, string s ,vector<string> &svec){
    if (s.size() == 2 * N) {
        svec.push_back(s);
        return;
    }
    if (lp < N) {
        generateParenthesis2(lp + 1 , rp, N, s + "(", svec);
    }
    if (rp < lp) {
        generateParenthesis2(lp, rp + 1, N, s + ")", svec);
    }
}


int main(int argc, const char * argv[]) {
    vector<string> s = generateParenthesis(3);
    for (auto  str : s) {
        cout << str << endl;
    }
    //v2
    s = generateParenthesis2(3);
    for (auto  str : s) {
        cout << str << endl;
    }
    return 0;
}
