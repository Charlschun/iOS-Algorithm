//
//  Set Matrix Zeroes.h
//  ALG
//
//  Created by junlongj on 2017/10/17.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
 
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 
 */
@interface Set_Matrix_Zeroes : NSObject

/**
 我们考虑使用第一行和第一列来保存是否需要置为零的状态,那么第一行和第一列本身的状态怎么办呢？可以通过两个变量来保存就行了。然后根据第一行和第一列的记录对其他元素进行置0。最后再根据前面的两个标记来确定是不是要把第一行和第一列置0就可以了。这样的做法只需要两个额外变量，所以空间复杂度是O(1)。
 时间上来说上面三种方法都是一样的，需要进行两次扫描，一次确定行列置0情况，一次对矩阵进行实际的置0操作，所以总的时间复杂度是O(m*n)。
 */
+ (void)Set_Matrix_Zeroes;
@end
