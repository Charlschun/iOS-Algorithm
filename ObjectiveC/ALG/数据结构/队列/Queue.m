//
//  Queue.m
//  ALG
//
//  Created by junlongj on 2017/9/22.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Queue.h"

@implementation Queue

+(instancetype)creatQueue:(NSMutableArray *)arrays{
    Queue *q = [Queue new];
    q->_datas = arrays;
    q->_head = 0;
    q->_tail = arrays.count;//指向末尾
    return q;
}

+(NSMutableArray *)decodeQQ:(Queue *)queue{
    NSMutableArray *results = @[].mutableCopy;
    while (queue->_head < queue->_tail - 1) {
        //首先pop首位
        [results addObject:queue->_datas[queue->_head]];
        //指向第二位
        queue->_head++;
        [results addObject:queue->_datas[queue->_tail]];
        queue->_tail ++;
        queue->_head++;
    }
    [results addObject:queue->_datas[queue->_head]];
    return results;
}
@end
