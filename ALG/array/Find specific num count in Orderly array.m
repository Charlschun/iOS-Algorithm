//
//  Find specific num count in Orderly array.m
//  ALG
//
//  Created by junlongj on 2017/10/13.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Find specific num count in Orderly array.h"

@implementation Find_specific_num_count_in_Orderly_array

/**
 [1,2,3,4,4,4,4,6,8,9]

 @param array <#array description#>
 @param target <#target description#>
 @return <#return value description#>
 */
+(NSInteger)findSpecificCountInOrderlyArray:(NSArray *)array targetNum:(NSInteger)target{
    NSInteger left ,right;
    left = 0;
    right = array.count-1;
    NSInteger count = 0;
    while (left < right) {
        NSInteger mid = left + (right - left)/2;
        if ([array[mid] integerValue] == target) {
            //发现了target的位置,然后在它的位置周围找
            count +=1;
            NSInteger k = mid;
            NSInteger m = mid;
            while ([array[--k] integerValue] == target) {
                count+=1;
            }
            while ([array[++m] integerValue] == target) {
                count+=1;
            }
            return count;
        }else if ([array[mid] integerValue] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}

@end
