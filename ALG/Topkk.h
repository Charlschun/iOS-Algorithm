//
//  Topkk.h
//  ALG
//
//  Created by junlongj on 2017/9/28.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Topkk : NSObject

/**
 计算出str中频率出现最多的词汇

 @param keyNumber 保存的前几位
 @return <#return value description#>
 */
+ (NSMutableArray *)topkUsingHeapWithKeyNumber:(NSInteger)keyNumber;

+ (NSMutableArray *)topkUsingQuickSortWithKeyNumber:(NSInteger)keyNumber;

@end
