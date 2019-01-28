//
//  Graph.h
//  ALG
//
//  Created by junlongj on 2017/9/30.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface PointNode : NSObject
@property (nonatomic ,assign) int value;
//是否已经遍历过
@property (nonatomic ,assign) BOOL isRead;
@end

@interface Graph : NSObject
@property (nonatomic ,strong)NSMutableArray<PointNode *> *points;
@property (nonatomic ,strong)NSMutableArray<NSMutableArray<NSNumber *> *> *lines;
+ (instancetype)creat;
/*
 基本思想：首先从图中某个顶点v0出发，访问此顶点，然后依次从v0相邻的顶点出发深度优先遍历，直至图中所有与v0路径相通的顶点都被访问了；若此时尚有顶点未被访问，则从中选一个顶点作为起始点，重复上述过程，直到所有的顶点都被访问。可以看出深度优先遍历是一个递归的过程。
 */
- (void)depthFirstSearch;

- (void)broadFirstSearch;
@end
