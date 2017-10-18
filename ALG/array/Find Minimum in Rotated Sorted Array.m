//
//  Find Minimum in Rotated Sorted Array.m
//  ALG
//
//  Created by junlongj on 2017/10/12.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Find Minimum in Rotated Sorted Array.h"

@implementation Find_Minimum_in_Rotated_Sorted_Array

+ (NSInteger)findMininumInRotatedArray:(NSArray *)array{
    NSInteger j = 0 ;
    while (j < array.count) {
        if (array[j] < array[j+1]) {
            j++;
        }else{
            break;
        }
    }
    return MIN([array[0] integerValue], [array[j+1] integerValue]);
    
}
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
+(NSInteger)findMininumInRotatedArrayByBinarySearch:(NSArray *)array{
    
    NSInteger left ,right ;
    left = 0;
    right = array.count - 1;
    while (left <= right) {
        NSInteger mid = left + (right - left) / 2;
        //临界值的处理
        if (mid == array.count - 1) {
            //找到了最右边.
            return MIN([array[mid] integerValue], [array[left] integerValue]);
        }
        if (mid == 0) {
            //找到了最左边
            return MIN([array[mid] integerValue], [array[right] integerValue]);
        }
        //如果当前的数比左右都小,说明找到波谷了
        if (array[mid]< array[mid + 1] && array[mid] < array[mid - 1]) {
            return MIN([array[mid] integerValue], [array[0] integerValue]);
        }
        //继续二分查找
        if (array[mid] > array[right]){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    
    return 0;
}

/**
 4 5 6 7 0 1 2.
 
 find 1

 @param array <#array description#>
 @param target <#target description#>
 @return <#return value description#>
 */
+(NSInteger)findTargetInRotatedArrayByBinarySearch:(NSArray *)array
                                         andTarget:(NSNumber*) target{
    NSInteger left ,right;
    left = 0;
    right = array.count - 1;
    while (left <= right) {
        NSInteger mid = left + (right - left) / 2;
        if (array[mid] == target ) {
            return mid;
        }
        if (array[right] < array[mid]) {
            if (array[left] > target) {
                //说明在最右边
                left = mid +1;
            }else{
                right = mid - 1;
            }
        }else{
            if (array[right] < target) {
                //说明在左边
                right = mid - 1;
            }else{
                left = mid + 1;
            }
            
        }
    }
    return  -1;
}

@end
