//
//  _3Num.h
//  ALG
//
//  Created by junlongj on 2017/10/16.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
 
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 
 Note: The solution set must not contain duplicate triplets.
 
 For example, given array S = [-1, 0, 1, 2, -1, -4],
 
 A solution set is:
 [
 [-1, 0, 1],
 [-1, -1, 2]
 ]
 */
@interface _3Num : NSObject

/**
 思路：
 先将数组按照升序排序,然后固定第一个数的位置,查找另两个数为-num[i]的和，当结果大于0的时候后边往后退一步，否则前边进一步，时间复杂度O(n^2)，所以时间复杂度为O（n^2）

 @param array <#array description#>
 @return <#return value description#>
 */
+ (NSArray *)threeNumInArray:(NSArray *)array;

@end
