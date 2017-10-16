//
//  Kth Largest Element in an Array.h
//  ALG
//
//  Created by junlongj on 2017/10/13.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
 　Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 　　For example,
 　　Given [3,2,1,5,6,4] and k = 2, return 5.
 　　Note:
 　　You may assume k is always valid, 1 ≤ k ≤ array’s length.
 
 这个问题，我们可以通过堆排序或者快速排序来解决.
 */
@interface Kth_Largest_Element_in_an_Array : NSObject


+(NSInteger)findKthLargestInArray:(NSMutableArray *)array kth:(NSInteger)kth;

@end
