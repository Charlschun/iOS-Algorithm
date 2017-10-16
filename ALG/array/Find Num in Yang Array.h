//
//  Find Num in Yang Array.h
//  ALG
//
//  Created by junlongj on 2017/10/13.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

 */

@interface Find_Num_in_Yang_Array : NSObject

/**
 思路，从矩阵的左小角出发，比a[i][j]小的话，上移，大的话下移

 @param target <#target description#>
 @param a <#a description#>
 @return <#return value description#>
 */
+ (BOOL)findNum:(int)target inArray:(int [3][3])a;

@end
