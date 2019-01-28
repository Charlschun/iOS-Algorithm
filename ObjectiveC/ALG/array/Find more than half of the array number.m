//
//  Find more than half of the array number.m
//  ALG
//
//  Created by junlongj on 2017/10/13.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Find more than half of the array number.h"

@implementation Find_more_than_half_of_the_array_number

+ (NSInteger)findInArray:(NSArray *)array{
    NSMutableArray *stack = [NSMutableArray array];
    for (int i = 0; i < array.count; i ++) {
        //如果栈为空或者，相邻的两个数一样的话，入栈
        if (stack.count == 0  || stack.lastObject == array[i]) {
            [stack addObject:array[i]];
        }else{
            //如果相邻的两个数不一样的话，移除栈顶
            [stack removeLastObject];
        }
    }
    return [stack.lastObject integerValue];
}

@end
