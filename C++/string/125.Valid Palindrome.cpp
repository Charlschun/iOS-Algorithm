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
using namespace std;

bool isPalindrome(const string &s) {
    int i = 0,j = s.size() - 1;
    if (s == "") {
        return true;
    }
    while (i <= j) {
        if (!isalpha(s[i])) {
            i++;
            continue;
        }
        if (!isalpha(s[j])){
            j--;
            continue;
        }
        if (toupper(s[i]) == toupper(s[j])) {
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    cout << isPalindrome("OP") << endl;
    return 0;
}
