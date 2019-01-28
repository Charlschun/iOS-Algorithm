//
//  Full Permutation.m
//  ALG
//
//  Created by junlongj on 2017/10/11.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Full Permutation.h"

@implementation Full_Permutation

/*
 if r-p <=1
 {
 add(set, A[pr])
 add(set, A[rp])
 return set
 }
 return A[p] + FullPermutation(A, p+1, r)
 
 */

+ (NSMutableArray *)permutation:(NSMutableArray<NSString *> *)target
               from:(NSInteger)from
                 to:(NSInteger)to{
    if (to - from <= 1) {
        //add 剩下的两个元素
        NSMutableArray *set = [NSMutableArray array];
        [set addObject:@[target[from],target[to]]];
        [set addObject:@[target[to],target[from]]];
        return set;
    }
    NSMutableArray *remainingSet = [self permutation:target from:from+1 to:to];
    //固定第一位数a[from]，然后随机插入到a[from+1...to]里面的任何位置
    return [self randomInsert:target[from]
                        inSet:remainingSet];
}

+ (NSMutableArray*)randomInsert:(NSString *)target inSet:(NSMutableArray *)set{
    
    NSMutableArray *result= @[].mutableCopy;
    for (NSInteger i = 0; i < set.count; i ++) {
        NSMutableArray *_innerString = set[i];
        NSMutableArray *_newSave = [_innerString mutableCopy];
        for (NSInteger j = 0; j < _innerString.count + 1; j ++) {
            _newSave[j] = target;
            for (int j = 0, k = 0; k < _innerString.count; j++, k++) {
                if (j == i)
                    j++;
                _newSave[j] = _innerString[k];
            }
            [result addObject:_newSave];
        }
    }
    return result;
}
@end
