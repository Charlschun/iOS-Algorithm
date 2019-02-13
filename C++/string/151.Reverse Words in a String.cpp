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
using namespace std;
/*
 https://leetcode-cn.com/problems/reverse-words-in-a-string/
 Given an input string, reverse the string word by word.
 
 Example:
 
 Input: "the sky is blue",
 Output: "blue is sky the".
 Note:
 
 A word is defined as a sequence of non-space characters.
 Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
 You need to reduce multiple spaces between two words to a single space in the reversed string.
 Follow up: For C programmers, try to solve it in-place in O(1) space.
 
 
 思路：以空格为分隔符，先将字符串划分成几个小字符串，然后依次进栈，最后逆序输出
 */
void reverseWords(string &s) {
    //1.每个单词里面没有空格
    //2.字符串前后可能有多余空格，要去掉
    //3.分隔符中间的空格保留一个
    int i = 0;
    bool hasChar = false;
    string temp;//保存着每次的字符串
    vector<string>  svec;
    //手动拼接一个空白符，用于后续的条件触发
    s += ' ';
    while (i < s.size()) {
        char c = s[i];
        if (c == ' ') {
            if (!hasChar) {
                i++;
                continue;
            }else{
                //找到了单词的末尾
                svec.push_back(temp);
                temp = "";
                hasChar = false;
                i++;
            }
        }else{
            hasChar = true;
            temp += c;
            i++;
        }
    }
    temp = "";
    for (int i = static_cast<int>(svec.size()) - 1; i >= 0  ; i--) {
        temp += svec[i];
        if (i != 0) {
            temp += ' ';
        }
    }
    s = temp;
}
int main(int argc, const char * argv[]) {
    string s = "   the sky is blue    ";
    reverseWords(s);
    cout << s << endl;
    return 0;
}
