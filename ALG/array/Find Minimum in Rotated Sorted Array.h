//
//  Find Minimum in Rotated Sorted Array.h
//  ALG
//
//  Created by junlongj on 2017/10/12.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Find_Minimum_in_Rotated_Sorted_Array : NSObject

+ (NSInteger)findMininumInRotatedArray:(NSArray *)array;
/*
 二分查找一直找中点，直到找到谷底的地方就是我们要的结果啦,下方的O
 4 5 6 7 0 1 2
 |
 | |
 | | |
 | | | |
 | | | |
 | | | |     |
 | | | |   | |
 */
+ (NSInteger)findMininumInRotatedArrayByBinarySearch:(NSArray *)array;
/**
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 
 You may assume no duplicate exists in the array.

 */
+ (NSInteger)findTargetInRotatedArrayByBinarySearch:(NSArray *)array
                                         andTarget:(NSNumber*) target;
@end
