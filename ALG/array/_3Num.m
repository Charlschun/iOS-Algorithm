//
//  _3Num.m
//  ALG
//
//  Created by junlongj on 2017/10/16.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "_3Num.h"

@implementation _3Num

+(NSArray *)threeNumInArray:(NSArray *)array {
//    //现在要三个数相加=0
//    //我先固定第一个数，
//    NSMutableArray *result = @[].mutableCopy;
//
//    for (int k = 0; k < array.count; k ++) {
//        for (int i = k+1 ; i < array.count; i ++) {
//            for (int j = i+1; j < array.count; j ++) {
//                if ([array[i] integerValue]  + [array[j] integerValue] +[array[k] integerValue] == 0) {
//                    //find
//                    [result addObject:@[array[k],array[i],array[j]]];
//                }
//            }
//        }
//    }
//    return result.copy;
    
   //首先将数组排序
   array =  [array sortedArrayUsingComparator:^NSComparisonResult(id  _Nonnull obj1, id  _Nonnull obj2) {
        if ([obj1 integerValue] < [obj2 integerValue]) {
            return NSOrderedAscending;
        }else if ([obj1 integerValue] == [obj2 integerValue]){
            return NSOrderedSame;
        }else{
            return NSOrderedDescending;
        }
    }];
    
    //@[@-1, @0, @1, @2, @-1, @-4]
    NSMutableArray *result = @[].mutableCopy;
    for ( int i = 0; i < array.count; i ++) {
        //首先固定第一个数的位置
//        NSInteger sum = - [array[i] integerValue];
        //主要要后两个元素的和 = sum
        if ([array[i] integerValue] > 0) {
            break;
        }
       if(i>0 && [array[i] integerValue]==[array[i-1] integerValue])
             continue;
        NSInteger start ,end ;
        start = i+1;
        end = array.count - 1;
        while (start < end) {
            NSInteger sum = [array[start] integerValue] + [array[end] integerValue] + [array[i] integerValue];
            if (sum == 0) {
                //find
                 [result addObject: @[array[i],array[start],array[end]]];
                start+=1;
                end-=1;
       
                //跳过重复的数据
                while (start<end && [array[start] integerValue] == [array[start-1] integerValue]) {
                    start+=1;
                }
                while (start < end && [array[end] integerValue] == [array[end+1] integerValue]) {
                    end-=1;
                }
            }else if (sum < 0) {
                //说明当前的数小了，需要前进
                start+=1;
            }else{
                end-=1;
            }
        }
    }
    return result;
    
}

@end
