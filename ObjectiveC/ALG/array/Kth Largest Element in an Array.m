//
//  Kth Largest Element in an Array.m
//  ALG
//
//  Created by junlongj on 2017/10/13.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Kth Largest Element in an Array.h"

@implementation Kth_Largest_Element_in_an_Array

+(NSInteger)findKthLargestInArray:(NSMutableArray *)array kth:(NSInteger)kth{
    
    return [self quickSort:array left:0 right:array.count-1 kth:kth];
}

+ (NSInteger)quickSort:(NSMutableArray *)array left:(NSInteger) left right:(NSInteger)right kth:(NSInteger)kth{
    
//    if (left >= right) {
//        return ;
//    }
    NSInteger i ,j;
    i = left;
    j = right;
    NSNumber *pivot=  array[left];

    while (i < j) {
        //找到右边第一个比pivot小的数
        while (i<j && array[j]>=pivot) {
            j-=1;
        }

        while (i<j && array[i]<=pivot) {
            i+=1;
        }
        if (i < j ) {
            //swap
            [array exchangeObjectAtIndex:i withObjectAtIndex:j];
        }
    }
    [array exchangeObjectAtIndex:i withObjectAtIndex:left];

    //第一轮快排结束
    if (right - i + 1 == kth) {
        return pivot.integerValue;
    }else if (right - i + 1  > kth){
        return  [self quickSort:array left:i+1 right:right kth:kth];
    }else{
        return [self quickSort:array left:left right:i-1 kth:kth];

    }

}

@end
