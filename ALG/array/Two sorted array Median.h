//
//  Two sorted array Median.h
//  ALG
//
//  Created by junlongj on 2017/10/12.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 求两个有序数组的中位数
 
 中位数:这群数据里的一半的数据比它大，而另外一半数据比它小
 */
@interface Two_sorted_array_Median : NSObject

/**
 归并排序，然后求中.o(m+n)
 a[m]
 b[n]


 @param arr1 <#arr1 description#>
 @param arr2 <#arr2 description#>
 @return <#return value description#>
 */
+ (NSInteger)calculateMedianWithArr1:(NSArray *)arr1
                                arr2:(NSArray *)arr2;
@end
