//
//  Two sorted array Median.m
//  ALG
//
//  Created by junlongj on 2017/10/12.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Two sorted array Median.h"

@implementation Two_sorted_array_Median

+ (NSInteger)calculateMedianWithArr1:(NSArray *)arr1
                                arr2:(NSArray *)arr2{
    
    NSInteger i ,j;
    i = j = 0;
    NSMutableArray *sortArray = @[].mutableCopy;
    while (i < arr1.count && j < arr2.count) {
        if (arr1[i] < arr2[j]) {
            [sortArray addObject:arr1[i++]];
        }else{
            [sortArray addObject:arr2[j++]];
        }
    }
    while (i<arr1.count) {
        [sortArray addObject:arr1[i++]];
    }
    while (j<arr2.count) {
        [sortArray addObject:arr2[j++]];
    }
    NSInteger length = sortArray.count;
    //如果总个数是单数
    if (length % 2) {
        return [sortArray[length/2] integerValue];
    }else{
        return  ([sortArray[length/2 -1] integerValue] + [sortArray[length/2] integerValue] ) /2.0;
    }
    
}

@end
