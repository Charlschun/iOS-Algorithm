//
//  Maximum Subarray.h
//  ALG
//
//  Created by junlongj on 2017/10/12.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 
 For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */
@interface Maximum_Subarray : NSObject

/**
 
 //将当前a[i] 和之前的max[...i-1]+a[i]作比较,如果a[i]最大，max = a[i]抛弃之间的.
 否则的话 max = max[...i-1]+a[i]


 @return <#return value description#>
 */
+ (NSInteger)max_subArray;
@end
