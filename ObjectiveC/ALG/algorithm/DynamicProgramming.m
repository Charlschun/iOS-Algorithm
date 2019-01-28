//
//  DynamicProgramming.m
//  ALG
//
//  Created by junlongj on 2017/10/9.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "DynamicProgramming.h"
const NSInteger line = 5;
@implementation DynamicProgramming

+ (void)triangleMaxTotal{
    //从上到下，求出从顶部到底部的最大路径,这是一个二维数组，下一步必须是a[i+1][j]或者a[i+1][j+1]
    NSMutableArray *triangle  = @[@[@7],
                                  @[@3,@8],
                                  @[@8,@1,@0],
                                  @[@2,@7,@4,@4],
                                  @[@4,@5,@2,@6,@5]].mutableCopy;
    //初始化子路径的max和,用来保存计算过的值.避免重复计算>
    NSMutableArray *maxPaths = @[].mutableCopy;
    for (int i = 1 ; i <= line; i ++) {
        NSMutableArray *subPaths = @[].mutableCopy;
        for (int j = 1; j <= i ; j ++) {
            [subPaths addObject:@(-1)];
        }
        [maxPaths addObject:subPaths];
    }
    NSInteger maxPath = [self _triangleMaxWithtriangle:triangle maxPaths:maxPaths i:0 j:0];
    NSInteger maxPath2 = [self _triangleBottomToUpMaxWithtriangle:triangle maxPaths:maxPaths];
    NSLog(@"maxPath:%zd,maxPath2-----:%zd",maxPath,maxPath2);
}

/**
 方法一，从上到下递归

 @param triangle <#triangle description#>
 @param maxPaths <#maxPaths description#>
 @param i <#i description#>
 @param j <#j description#>
 @return <#return value description#>
 */
+ (NSInteger)_triangleMaxWithtriangle:(NSMutableArray *)triangle
                             maxPaths:(NSMutableArray *)maxPaths
                                    i:(NSInteger)i
                                    j:(NSInteger)j{
    
    if ([maxPaths[i][j] integerValue] != -1) {
        return [maxPaths[i][j] integerValue];
    }
    //最后一行
    if (i == line-1) {
        return [triangle[i][j] integerValue];
    }else{
        NSInteger max1 = [self _triangleMaxWithtriangle:triangle maxPaths:maxPaths i:i + 1 j:j];
        NSInteger max2 = [self _triangleMaxWithtriangle:triangle maxPaths:maxPaths i:i + 1 j:j+1];
        NSInteger max  =  [triangle[i][j] integerValue] + MAX(max1, max2);
        maxPaths[i][j] = @(max);
    }
    return [maxPaths[i][j] integerValue];
}

/**
 方法二，从下到上推算

 @param triangle <#triangle description#>
 @param maxPaths <#maxPaths description#>
 @return <#return value description#>
 */
+ (NSInteger)_triangleBottomToUpMaxWithtriangle:(NSMutableArray *)triangle
                             maxPaths:(NSMutableArray *)maxPaths{
    //最后一行不用计算，保存就行
    for (int i = 0; i < line; i ++) {
        maxPaths[line-1][i] = triangle[line-1][i];
    }
    
    for (int i = line - 2; i >=0;i--) {
        for (int j = 0 ; j <= i; j++) {
            NSInteger max1 =  [maxPaths[i+1][j] integerValue];
            NSInteger max2 = [maxPaths[i+1][j+1] integerValue];
            maxPaths[i][j] = @(MAX(max1, max2) + [triangle[i][j] integerValue]);
        }
    }
    return [maxPaths[0][0] integerValue];
    
}



+ (void)dynamicProgramming{
    NSArray *prices = @[@0,@1,@5,@8,@9,@10,@17,@17,@20,@24,@30];
    int total =  100;
    
    NSMutableArray *saveCalu = @[].mutableCopy;
    saveCalu [0] = @0;
    for (int i = 1 ; i <= total ; i ++) {
        saveCalu[i] = @(-1);
    }
    BottomUpCutRod(prices, total, saveCalu);
    NSLog(@"totalPrice:%zd",[saveCalu[total] integerValue]);
}

+ (NSInteger)_cutrod:(NSArray *)prices total:(NSInteger)total{
    NSInteger q = - 1;
    if (total == 0) {
        return 0;
    }else{
        for (NSInteger i = 1; i <= total; i ++) {
            NSInteger price = extracted(i, prices);
            q = MAX(q, price + [self _cutrod:prices total:total-i]);
        }
        NSLog(@"经历了:%zd",q);
        return q;
    }
}

static NSInteger extracted(int j, NSArray *p) {
    NSInteger price ;
    if (j < p.count) {
        price = [p[j] integerValue];
    }else{
        price = 0;
    }
    return price;
}

static void BottomUpCutRod(NSArray* p,int n,NSMutableArray*r)
{
    NSInteger q = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            NSInteger price = extracted(j, p);
            q = MAX(q,  price + [r[i - j] integerValue]);
        }
        r[i] = @(q);
    }
}
@end
