//
//  Queue.h
//  ALG
//
//  Created by junlongj on 2017/9/22.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 在首部插入，在尾部删除的线性结构
 */
@interface Queue : NSObject
{
    NSMutableArray *_datas;
    NSInteger _head;//收指针
    NSInteger _tail;//尾指针
}

+ (instancetype)creatQueue:(NSMutableArray *)arrays;

+ (NSMutableArray*)decodeQQ:(Queue *)queue;

@end
