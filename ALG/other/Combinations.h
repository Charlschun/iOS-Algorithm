//
//  Combinations.h
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 
 For example,
 If n = 4 and k = 2, a solution is:
 
 [
 [2,4],
 [3,4],
 [2,3],
 [1,2],
 [1,3],
 [1,4],
 ]

 */
@interface Combinations : NSObject
//http://blog.csdn.net/u010500263/article/details/18435495

+ (NSArray *)CombinationsWithRange:(NSInteger)rangeMax count:(NSInteger)count;

/**
 Given a set of distinct integers, nums, return all possible subsets.
 
 Note: The solution set must not contain duplicate subsets.
 
 For example,
 If nums = [1,2,3], a solution is:
 
 [
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]

 @param set <#set description#>
 @return <#return value description#>
 */
+ (NSArray *)subSetsWithSets:(NSArray *)set;
@end
