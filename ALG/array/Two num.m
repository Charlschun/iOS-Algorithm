//
//  Two num.m
//  ALG
//
//  Created by junlongj on 2017/10/16.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Two num.h"

@implementation Two_num

+ (NSArray *)twoSumInArray:(NSArray *)array andSum:(NSInteger)sum{
    //Given nums = [2, 7, 11, 15], target = 9,
    NSMutableArray *result = @[].mutableCopy;
    for (int i = 0; i < array.count; i ++) {
        for (int j = i + 1; j < array.count; j++) {
            if ([array[i] integerValue] + [array[j] integerValue] == sum) {
                [result addObject:@[@(i),@(j)]];
            }
        }
    }
    return  result;
}
+(NSArray *)twoSumByHashInArray:(NSArray *)array andSum:(NSInteger)sum{
    NSMutableDictionary *table = [NSMutableDictionary dictionary];
    for (int i =  0 ; i < array.count; i++) {
        NSInteger other = sum - [array[i] integerValue];
        //如果存在上一个元素满足和为sum
        NSNumber *index = [table objectForKey:@(other)];
        if (index) {
            return @[index,@(i)];
        }
        //把没有匹配的加入到hashtable里面去
        [table setObject:@(i) forKey:array[i]];
    }
    return nil;
}
@end
