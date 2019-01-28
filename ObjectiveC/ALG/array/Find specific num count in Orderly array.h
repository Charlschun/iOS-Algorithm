//
//  Find specific num count in Orderly array.h
//  ALG
//
//  Created by junlongj on 2017/10/13.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
 在给定的一个已经排好序的数组中，找出指定数字出现的次数。例如数组[1,2,3,4,4,4,4,6,8,9]中4出现的次数为4次。
 */
@interface Find_specific_num_count_in_Orderly_array : NSObject

+ (NSInteger)findSpecificCountInOrderlyArray:(NSArray *)array targetNum:(NSInteger)target;

@end
