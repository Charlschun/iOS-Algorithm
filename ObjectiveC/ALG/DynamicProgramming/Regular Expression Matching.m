//
//  Regular Expression Matching.m
//  ALG
//
//  Created by junlongj on 2017/10/12.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Regular Expression Matching.h"

@implementation Regular_Expression_Matching
+ (BOOL)matchRegularWithStr1:(NSString *)str1 str2:(NSString *)str2
{
    return true;
    NSInteger i = str2.length - 1 ;//循环str2
    NSInteger j = str1.length - 1;//循环str1
    while (i >=0 && j>=0) {
        unichar str2_c = [str2 characterAtIndex:i];
        unichar str1_c = [str1 characterAtIndex:j];
        if (str2_c == '.' || str2_c == str1_c ) {
            //正确匹配了一个
            j--;
            i--;
        }else if (str2_c == '*'){
            i--;
            //j怎么移动？
//            j -=k;
//            k =
        }else{
            return false;
        }
    }
}


//bool isMatch(string s, string p)
//{
//    int m = s.length(),n = p.length();
//    bool dp[m+1][n+1];
//    dp[0][0] = true;
//    //初始化第0行,除了[0][0]全为false，毋庸置疑，因为空串p只能匹配空串，其他都无能匹配
//    for (int i = 1; i <= m; i++)
//        dp[i][0] = false;
//    //初始化第0列，只有X*能匹配空串，如果有*，它的真值一定和p[0][j-2]的相同（略过它之前的符号）
//    for (int j = 1; j <= n; j++)
//        dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];
//
//    for (int i = 1; i <= m; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            if (p[j - 1] == '*')
//            {
//                dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];
//
//            }
//            else   //只有当前字符完全匹配，才有资格传递dp[i-1][j-1] 真值
//            {
//                dp[i][j] = (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
//
//            }
//        }
//    }
//    return dp[m][n];
//}


@end
