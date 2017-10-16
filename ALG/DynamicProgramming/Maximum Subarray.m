//
//  Maximum Subarray.m
//  ALG
//
//  Created by junlongj on 2017/10/12.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Maximum Subarray.h"

@implementation Maximum_Subarray

+ (NSInteger)max_subArray{
    NSArray *origin = @[@-2,@1,@-3,@4,@-1,@2,@1,@-5,@4];
//    NSInteger result = 0;
//    for (int i = 0 ; i < origin.count ; i ++) {
//        for (int j = i  + 1; j < origin.count; j ++) {
//            result = MAX(result, [self calculateSumWithArray:origin from:i to:j]);
//        }
//    }
//    return result;
    
    //初始化状态
    NSInteger globalMaximum = [origin[0] integerValue];
    NSInteger maximumSoFar = [origin[0] integerValue];
    NSInteger length = origin.count;
    
    for(NSInteger i=1; i<length; i++){
        //当前的value
        NSInteger ct = [origin[i] integerValue] ;
        //将当前a[i] 和之前的a[...i-1]+a[i]作比较,如果a[i]最大，抛弃之间的.
        //maximumSoFar为之前最大的sum
        //执行完这句以后，maximumSoFar为当前最大的sum
        maximumSoFar = MAX(ct + maximumSoFar,ct);
        NSLog(@"maximumSoFar:%zd",maximumSoFar);
        globalMaximum = MAX(globalMaximum, maximumSoFar);
    }
    NSLog(@"globalMaximum:%zd",globalMaximum);
    return globalMaximum;
}

+ (NSInteger)calculateSumWithArray:(NSArray *)array from:(NSInteger)from to:(NSInteger)to{
    __block NSInteger sum = 0;
    NSArray *sub = [array subarrayWithRange:NSMakeRange(from , to-from)];
    [sub enumerateObjectsUsingBlock:^(NSNumber*  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        sum +=obj.integerValue;
    }];
    return sum;
}

@end
