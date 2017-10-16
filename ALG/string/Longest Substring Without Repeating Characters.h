//
//  Longest Substring Without Repeating Characters.h
//  ALG
//
//  Created by junlongj on 2017/10/11.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 Given a string, find the length of the longest substring without repeating characters.
 
 Examples:
 
 Given "abcabcbb", the answer is "abc", which the length is 3.
 
 Given "bbbbb", the answer is "b", with the length of 1.
 
 Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
@interface Longest_Substring_Without_Repeating_Characters : NSObject

/**
 思路：把整个string分割成各个substring，然后判断每个substring是不是包含重复的char
 那么怎么分割呢？用2层循环，0<i<n   i<j<n
 有怎么判断是否包含重复的字符呢？ 哈希
 @param str <#str description#>
 @return <#return value description#>
 */
+ (NSInteger)lengthOfLongestSubstring:(NSString *)str;


/**
 思路:通过创建一个虚拟的箱子[i,j]，然后我们通过判断当前元素已经存在过箱子里面来滑动它的位置i++或者j++，最终j-i就是我们的长度啦

 @param str <#str description#>
 @return <#return value description#>
 */
+ (NSInteger)lengthOfLongestSubstringBySlowWindowWithStr:(NSString *)str;

@end
