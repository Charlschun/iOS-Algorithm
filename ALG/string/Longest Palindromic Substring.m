//
//  Longest Palindromic Substring.m
//  ALG
//
//  Created by junlongj on 2017/10/11.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Longest Palindromic Substring.h"

@implementation Longest_Palindromic_Substring

+ (BOOL)isPalidromic:(NSString *)str{
    NSInteger mid = str.length / 2;
    NSString *str1 = [str substringToIndex:mid];
    NSString *str2 = [str substringFromIndex:mid];
    //说明str的length为单数，中间一位我们可以忽略
    if (str2.length != str1.length) {
        str2 = [str2 substringFromIndex:1];
    }
    NSInteger i ,j ;
    i = 0;
    j = str2.length-1;
    while (i < str1.length) {
        if (![[str1 substringWithRange:NSMakeRange(i, 1)] isEqualToString:[str2 substringWithRange:NSMakeRange(j , 1)]]) {
            return false;
        }
        i++;
        j--;
    }
    
    return  true;
}

/**
 思路：通过中心点发散出去，观察他们是否相等.
 We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2n - 1such centers.
 
 You might be asking why there are 2n - 12n−1 but not nn centers? The reason is the center of a palindrome can be in between two letters. Such palindromes have even number of letters (such as \textrm{''abba''}”abba”) and its center are between the two \textrm{'b'}’b’s.

 @param s <#s description#>
 @return <#return value description#>
 */
+ (NSString *)longestPalindrome:(NSString *)s{
    int start = 0, end = 0;
    for (int i = 0; i < s.length; i++) {
        //以s[i]自身为中心点
        int len1 = expandAroundCenter(s, i, i);
        //以s[i]与s[i+1]为中心点
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = MAX(len1, len2);
        //定位位置
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return [s substringWithRange:NSMakeRange(start, end + 1 - start)];
}

static int expandAroundCenter(NSString* s, int left, int right) {
    /*
         a b c b a
     */
    int L = left, R = right;
    while (L >= 0 && R < s.length && [s characterAtIndex:L] == [s characterAtIndex:R]) {
        L--;
        R++;
    }
    return R - L - 1;
}



@end
