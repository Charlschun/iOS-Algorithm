//
//  Set Matrix Zeroes.m
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Set Matrix Zeroes.h"

@implementation Set_Matrix_Zeroes

+(void)Set_Matrix_Zeroes{
    

    NSArray *a = @[@[@1,@0,@1],
                   @[@1,@1,@0],
                   @[@1,@1,@1]];
    
    BOOL rowNeedZero = false;
    BOOL colNeedZero = false;
    //先看第一列是否需要变0
    for (int i = 0 ; i < a.count; i ++) {
        if ([a[i][0] integerValue] == 0) {
            rowNeedZero = true;
            break;
        }
    }
    //D一行
    for (int i = 0 ; i < [a[0] count]; i ++) {
        if ([a[0][i] integerValue] == 0) {
            colNeedZero = true;
            break;
        }
    }
    //如果a[i][j] == 0 保存到第一行和第一列的数据中
    for (int i = 1; i < [a count]; i ++) {
        for (int j = 1; j < [a [0] count]; j ++) {
            if ([a[i][j] integerValue] == 0) {
                a[i][0] = @0;
                a[0][j] = @0;
            }
        }
    }
    
    for (int i = 1; i < [a count]; i ++) {
        for (int j = 1; j < [a [0] count]; j ++) {
            if ([a[i][0] integerValue] == 0 ||
                [a[0][j] integerValue] == 0) {
                a[i][j] = @0;
            }
        }
    }
    
    if (rowNeedZero) {
        for (int i = 0 ; i < a.count; i ++) {
            a[i][0]  = @0;
        }
    }
    
    if (colNeedZero) {
        for (int i = 0 ; i < a.count; i ++) {
            a[0][i]  = @0;
        }
    }
    
}

@end
