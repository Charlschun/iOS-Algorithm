//
//  HeapSort.m
//  ALG
//
//  Created by junlongj on 2017/9/20.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "HeapSort.h"

@implementation HeapSort

- (void)heapSort:(NSMutableArray *)array{
    //1.构建大跟堆，就是根节点是最大的
    for (NSInteger i = array.count - 1; i >= 0; i --) {
        [self _adjustHeap:array size:array.count index:i];
    }
    //2.然后依次与最末尾交换，沉到数组底部成为最大的
    NSInteger j = array.count - 1;
    while (j>0) {
        [array exchangeObjectAtIndex:j withObjectAtIndex:0];
        j--;
        [self _adjustHeap:array size:j index:0];
    }
}

- (void)_adjustHeap:(NSMutableArray *)array size:(NSInteger)size index:(NSInteger)i{
    
    NSNumber* temp = array[i];//先取出当前元素i
    NSInteger left ,right ;
    left = 2 * i + 1;
    right = left + 1;
    //首先指向他的左子节点
    for (NSInteger k = left; k < size; k = k * 2 + 1) {
        //如果右子节点大的话，指向右子节点
        if (k + 1 < size && array[k]< array[k+1])  {
            k ++;
        }
        //如果子节点比根节点大的话，替换.
        if (array[k] > temp) {
            array[i] = array[k];
            i = k;
        }else{
            break;
        }
    }
    array[i] = temp;
}
@end
