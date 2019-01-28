//
//  BinarySearch.m
//  ALG
//
//  Created by junlongj on 2017/9/22.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "BinarySearch.h"

@implementation BinarySearch

+ (NSInteger)binarySearch:(NSMutableArray*)array target:(NSInteger)target {
    NSInteger left,right;
    left = 0;
    right = array.count - 1;
    while (left <= right) {
        NSInteger mid = left + (right - left) /2;
        NSInteger midValue = [array[mid] integerValue];
        if (midValue == target)
            return mid;
        else if (midValue < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return  -1;
}


+ (NSInteger)binarySearchFindFirstEqual:(NSMutableArray*)array target:(NSInteger)target {
    NSInteger left,right,findIndex;
    left = 0;
    right = array.count - 1;
    findIndex  = -1;
    while (left <= right) {
        NSInteger mid = left + (right - left) /2;
        NSInteger midValue = [array[mid] integerValue];
        if (midValue == target)
        {
            if (findIndex == -1) {
                findIndex = mid;
            }else{
                findIndex = MIN(findIndex, mid);
            }
            right = mid - 1;
        }
        else if (midValue < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return  findIndex;
}
@end
