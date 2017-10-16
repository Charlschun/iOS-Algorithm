//
//  Find Num in Yang Array.m
//  ALG
//
//  Created by junlongj on 2017/10/13.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Find Num in Yang Array.h"

@implementation Find_Num_in_Yang_Array

/**
 思路，从矩阵的左小角出发，比a[i][j]小的话，上移，大的话下移

 @param num <#num description#>
 @param array <#array description#>
 @return <#return value description#>
 */
+ (BOOL)findNum:(int)target inArray:(int [3][3]) a{
    int Maxi,Maxj ;
    Maxi = Maxj = 2;
    int i = 0;
    int j = Maxj;
    int ct = a[i][j];//初始位置，左下角
    while (i < Maxi && j > 0) {
        if (ct == target) {
            return true;
        }else if (ct < target ) {
            ct = a[++i][j];
        }else{
            ct = a[i][--j];
        }
    }
    return false;
}

@end
