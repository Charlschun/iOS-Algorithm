//
//  Practice.m
//  ALG
//
//  Created by junlongj on 2017/9/22.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Practice.h"

@implementation Practice
+ (void)decodeQQ{
    NSMutableArray *array = @[@6,@3,@1,@7,@5,@8,@9,@2,@4].mutableCopy;
    NSMutableArray *qq = @[].mutableCopy;
    //    //每次将数组的拿到数组的前两位，第一位扔掉，第二位放到数组的末尾
    //    while (array.count>1) {
    //        NSNumber *first = array[0];
    //        NSNumber *second = array[1];
    //        [array removeObject:first];
    //        [array removeObject:second];
    //        [array addObject:second];
    //        [qq addObject:first];
    //    }
    //    [qq addObjectsFromArray:array];
    //    NSLog(@"decodeqq:%@",qq);
    
    
    int head,tail ,k ;
    head = 0;
    tail = 9;
    k = 0;
    //head与tail之间的数据为原始数据，现在我们每次删除数据将head指针++，删除数据tail++
    //这里为什么小于tail-1保证头尾指针之间最后只有一个元素。
    while (head < tail -1) {
        qq[k++] = array[head];
        //弹出第一个数
        head++;
        //末尾加入第二个数
        array[tail] = array[head];
        
        tail++;
        //继续移动
        head++;
    }
    qq[k++] = array[head];
    NSLog(@"_%@",qq);
}

@end
