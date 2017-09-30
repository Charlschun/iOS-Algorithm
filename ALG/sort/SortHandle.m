//
//  SortHandle.m
//  ALG
//
//  Created by junlongj on 2017/9/19.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "SortHandle.h"
#import "HeapSort.h"
#import "ShellSort.h"
@implementation SortHandle

+ (void)bubbleSortWithArray:(NSMutableArray<NSNumber *> *)array{
    for (int i = 0; i < array.count; i ++) {
        
        for (int j = 0 ; j < array.count - 1 - i ; j ++) {
            if (array[j] > array[j + 1]) {
                //wap
                NSNumber *temp = array[j];
                array[j] = array[j + 1];
                array[j+1] = temp;
            }
        }
    }
}

+(void)simpleSelectSortWithArray:(NSMutableArray<NSNumber *> *)array{
    for (NSInteger i = 0 ; i < array.count; i ++) {
        NSInteger minIndex =  i;
        for (NSInteger j = i + 1; j < array.count; j ++) {
            if (array[j] < array[minIndex]) {
                //swap
                minIndex = j;
            }
        }
        if (minIndex != i ) {
            [array exchangeObjectAtIndex:minIndex withObjectAtIndex:i];
        }
    }
}

+ (void)quickSortWithArray:(NSMutableArray<NSNumber *> *)array{
    [self _alickSort:array left:0 right:array.count - 1];
}

+ (void)_alickSort:(NSMutableArray *)array left:(NSInteger)left right:(NSInteger)right{
    if (left >= right) {
        return;
    }
    NSNumber *temp = array[left];
    NSInteger i,j;
    i = left;
    j = right;
    while (i<j) {
        //找到第一个比temp小的
        while (i<j&& array[j] >= temp) {
            j-=1;
        }
        while (i<j&&array[i]<= temp  ) {
            i+=1;
        }
        //交换他们的位置
        if (i < j ) {
            [array exchangeObjectAtIndex:i  withObjectAtIndex:j];
        }
    }
    //把标杆的值放在最中间
    [array exchangeObjectAtIndex:left withObjectAtIndex:i];
    [self _alickSort:array left:left right:i - 1];
    [self _alickSort:array left:i + 1 right:right];
    
}

//http://upload-images.jianshu.io/upload_images/1170656-8f8fe207ea0d0609.gif?imageMogr2/auto-orient/strip
+ (void)insertSortWithArray:(NSMutableArray <NSNumber *> *)array{
    
    for (int i = 1; i < array.count; i ++) {
        
        //待插入的数据
        NSInteger temp = [array[i] integerValue];
        NSInteger j = i ;
        //开始遍历i以前的所有项，然后依次比较，一直找到合适的位置，把temp放进去.
        //这里因为要在前0-i之间插入值，所以要把比temp大的值都向右移动
        while (j > 0 && [array[j -1]  integerValue] >  temp) {
            array[j] = array[j-1];
            j--;
        }
        
        array[j] =  [NSNumber numberWithInteger:temp];
    
    }
    
}

+ (void)binaryinsertSortWithArray:(NSMutableArray <NSNumber *> *)array{

    for (int i = 1; i < array.count; i ++) {
        //待插入的数据
        NSInteger temp = [array[i] integerValue];
        //开始遍历i以前的所有项，然后依次比较，一直找到合适的位置，把temp放进去.
        //这里因为要在前0-i之间插入值，所以要把比temp大的值都向右移动
        
        //这里开始二分查找合适的位置
        NSInteger left = 0;
        NSInteger right = i - 1;
        while (left <= right) {
            NSInteger mid = left + (right - left) /2 ;
            //比较mid的value和temp的关系
            if ([array[mid] integerValue] < temp) {
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        
        //现在遍历完之后，被分成了3部分0--left ,left ,left-right
        //先把left-right向后移
        NSInteger k = i;
        while (k > left) {
            array[k] = array[k-1];
            k--;
        }
    
        //对left赋值
        array[left] = [NSNumber numberWithInteger:temp];
    }
}

+(void)mergeSortWithArray:(NSMutableArray<NSNumber *> *)array{
    
    [self _separate:array left:0 right:array.count - 1];
}
+ (void)_separate:(NSMutableArray *)array left:(NSInteger)left right:(NSInteger)right{
    if (left < right) {
        //首先将目标数组分离成两个数组
        NSInteger mid = left + (right - left) / 2;
        [self _separate:array left:left right:mid];
        [self _separate:array left:mid + 1 right:right];
        //然后合并他们
        [self _merge:array left:left mid:mid right:right];
    }
}

+ (void)_merge:(NSMutableArray *)array left:(NSInteger)left mid:(NSInteger)mid right:(NSInteger)right{
    //现在的两个数组，都是有序有组，我们只需要把他合并在一起就行了
    NSLog(@"---%zd---%zd",left,right);
    NSInteger i ,j ,k;
    i = left;
    j = mid + 1;
    k = 0;
    NSMutableArray *save = @[].mutableCopy;
    while (i <= mid && j <= right) {
        //谁小加入谁要数组，然后小的那个数组的第二个元素跟他再比.
        if (array[i] < array[j]) {
            save[k++] = array[i++];
        }else{
            save[k++] = array[j++];
        }
    }
    //加入剩下的元素
    while (i<=mid) {
        save[k++] = array[i++];
    }
    while (j<=right) {
        save[k++] = array[j++];
    }
    //然后对数组的left-right部分重新赋值
    k = 0;
    while (left<=right) {
        array[left++] = save[k++];
    }
}

+(void)heapSort:(NSMutableArray *)array{
    [HeapSort heapSort:array];
}

+ (void)shellSort:(NSMutableArray *)array{
    [ShellSort shellSort:array];
}

@end
