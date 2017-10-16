//
//  Longest Substring Without Repeating Characters.m
//  ALG
//
//  Created by junlongj on 2017/10/11.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Longest Substring Without Repeating Characters.h"

@implementation Longest_Substring_Without_Repeating_Characters


+ (NSInteger)lengthOfLongestSubstringBySlowWindowWithStr:(NSString *)str
{
    /*
     123123
     */
    NSInteger maxlength = 0;
    NSInteger i , j;
    i = j = 0;
    //集合里面装的就是[i,j]范围的对象
    NSMutableSet *set = [NSMutableSet set];
    while (i < str.length && j < str.length) {
        //我们把set想象成一个箱子，set箱子里面装的就是[i,j]范围的对象
        NSString *subStr = [str substringWithRange:NSMakeRange(j, 1)];
        //如果str[j]在我的箱子里面.
        if ([set containsObject:subStr]) {
            //移除掉第一个重复对象.
            [set removeObject:[str substringWithRange:NSMakeRange(i, 1)]];
            //然后左边缩短一步
            i++;
        }else{
            [set addObject:subStr];
            //然后右边扩大一步
            j++;
            maxlength = MAX(maxlength, j-i);
        }
    }
    return maxlength;
}


/**
 思路：把整个string分割成各个substring，然后判断每个substring是不是包含重复的char

 @param str <#str description#>
 @return <#return value description#>
 */
+ (NSInteger)lengthOfLongestSubstring:(NSString *)str{
    NSInteger maxLength = 0;
    for (NSInteger i = 0; i < str.length; i ++) {
        for (NSInteger j = i+1; j < str.length; j ++) {
            if ([self isAllUnique:str start:i  end:j]) {
                maxLength = MAX(maxLength, j - i);
            }
        }
    }
    return maxLength;
}

/**
 范围内的字符串是否包含重复的字符
 通过哈希表来判断是否包含重复元素.

 @param str <#str description#>
 @param start <#start description#>
 @param end <#end description#>
 @return <#return value description#>
 */
+ (BOOL)isAllUnique:(NSString *)str start:(NSInteger)start end:(NSInteger)end{
    NSMutableSet *set = [NSMutableSet set];
    for (NSInteger i = start; i <end; i ++) {
        NSString *subs = [str substringWithRange:NSMakeRange(i, 1)];
        if ([set containsObject:subs]) {
            return false;
        }
        [set addObject:subs];
    }
    return true;
}

@end
