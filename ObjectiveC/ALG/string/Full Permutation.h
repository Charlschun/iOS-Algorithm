//
//  Full Permutation.h
//  ALG
//
//  Created by junlongj on 2017/10/11.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
//全排列
/*
 思路:固定第N位数字,然后让剩余的元素重新组合后随机插入
 假设abcd是输入
 f(abcd)  = a + f(bcd)
 f(bcd) =  b + f(cd)
 f(cd) = {cd,dc}
 很明显这是一个递归的过程
 伪代码:

 func  FullPermutation (int A[],p,r){
 if r-p <=1
 {
 var set = new Set();
 add(set, A[pr])
 add(set, A[rp])
 return set
 }
 return A[p] + FullPermutation(A, p+1, r) //把A[p]随机插入到剩余的组合中
 }
 */
@interface Full_Permutation : NSObject
+ (NSMutableArray *)permutation:(NSMutableArray<NSString *> *)target
                           from:(NSInteger)from
                             to:(NSInteger)to;
@end
