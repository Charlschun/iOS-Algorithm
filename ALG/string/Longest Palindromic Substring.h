//
//  Longest Palindromic Substring.h
//  ALG
//
//  Created by junlongj on 2017/10/11.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 
 Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 
 Example:
 
 Input: "babad"
 
 Output: "bab"
 
 Note: "aba" is also a valid answer.
 
 */

@interface Longest_Palindromic_Substring : NSObject
+ (BOOL)isPalidromic:(NSString *)str;
/*
 
 思路：通过中心点发散出去，观察他们是否相等.
 We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2n - 1such centers.
 
 You might be asking why there are 2n - 12n−1 but not nn centers? The reason is the center of a palindrome can be in between two letters. Such palindromes have even number of letters (such as \textrm{''abba''}”abba”) and its center are between the two \textrm{'b'}’b’s.
 
 @param s s description
 @return <#return value description#>
 */
+ (NSString *)longestPalindrome:(NSString *)s;

@end
