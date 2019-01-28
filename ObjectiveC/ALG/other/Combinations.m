//
//  Combinations.m
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Combinations.h"

@implementation Combinations

+(NSArray *)CombinationsWithRange:(NSInteger)rangeMax count:(NSInteger)count{
    NSMutableArray *save = @[].mutableCopy;
    NSMutableArray *combSet = @[].mutableCopy;
    [self CombinationsWithRange:rangeMax count:count startLocation:1 comb:save combSet:combSet];
    return combSet.copy;
}

+ (void)CombinationsWithRange:(NSInteger)rangeMax
                        count:(NSInteger)count
                        startLocation:(NSInteger)startLocation
                         comb:(NSMutableArray *)comb
                      combSet:(NSMutableArray <NSMutableArray*>*)combSet{
    // 1....rangeMax里面选择count个数然后组合
    //如果元素获取完毕，直接返回
    if (comb.count == count) {
        [combSet addObject:[NSMutableArray arrayWithArray:comb]];
        return;
    }else{
        // try each possibility number in current position
        for (NSInteger i = startLocation; i <= rangeMax; i++) {
            [comb addObject:@(i)];
            //// after selecting number for current position, process next position
            [self CombinationsWithRange:rangeMax count:count startLocation:i+1 comb:comb combSet:combSet];
            // clear the current position to try next possible number
            //本次递归完毕，清空数组.
            [comb removeLastObject];
        }
    }
}

+(NSArray *)subSetsWithSets:(NSArray *)set {
    NSMutableArray *save = @[].mutableCopy;
    NSMutableArray *combSet = @[].mutableCopy;
    [self subSetsWithSets:set startLocation:1 comb:save combSet:combSet];
    return combSet.copy;
}

+ (void)subSetsWithSets:(NSArray *)set
          startLocation:(NSInteger)startLocation
                   comb:(NSMutableArray *)comb
                combSet:(NSMutableArray <NSMutableArray*>*)combSet{
    
    [combSet addObject:[NSMutableArray arrayWithArray:comb]];
    
    for (NSInteger i = startLocation ; i < set.count; i ++) {
        [comb addObject:set[i]];
        [self subSetsWithSets:set startLocation:startLocation+1 comb:comb combSet:combSet];
        [comb removeLastObject];
    }
}

@end
