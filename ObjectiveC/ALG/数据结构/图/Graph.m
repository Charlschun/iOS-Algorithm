//
//  Graph.m
//  ALG
//
//  Created by junlongj on 2017/9/30.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "Graph.h"
@implementation PointNode

@end


@implementation Graph

+(instancetype)creat{
    Graph *graph =  Graph.new;
    return graph;
}
-(instancetype)init{
    self = [super init];
    if (!self) return nil;
    //创建数据
    int  pointCount = 7;
    NSMutableArray *points = @[].mutableCopy;
    NSMutableArray *lines = @[].mutableCopy;
    for (int i = 0; i < pointCount; i ++) {
        PointNode *node = [PointNode new];
        node.value  = i;
        [points addObject:node];
        NSMutableArray *p = @[].mutableCopy;
        for (int j = 0; j < pointCount; j ++) {
            [p addObject:@0];
        }
        [lines addObject:p];
    }
    _points = points;
    _lines = lines;
    [self addLine:0 otherPoint:1 weight:1];
    [self addLine:0 otherPoint:2 weight:1];
    [self addLine:1 otherPoint:3 weight:1];
    [self addLine:1 otherPoint:4 weight:1];
    [self addLine:2 otherPoint:5 weight:1];
    [self addLine:2 otherPoint:6 weight:1];
    [self addLine:5 otherPoint:6 weight:1];
    return self;
}

- (void)addLine:(NSInteger)i otherPoint:(NSInteger)j weight:(NSInteger)weight{
    _lines[i][j] = @(weight);
}
- (void)depthFirstSearch{
    for (int i = 0 ; i < _points.count; i ++) {
        if (!_points[i].isRead) {
            [self depthFirstSearchWithPoint:i];
        }
    }
    
}

- (void)broadFirstSearch{
    for (NSInteger i = 0; i < _points.count; i ++ ) {
        if (_points[i].isRead == false) {
            [self broadFirstSearchWithIndex:i];
        }
    }
}

- (void)broadFirstSearchWithIndex:(NSInteger)index{
    PointNode *point = _points[index];
    point.isRead = true;
    NSLog(@"broad:%zd",point.value);
    
    NSMutableArray<PointNode*> *queue = @[].mutableCopy;
    [queue addObject:point];
    
    while (queue.count) {
        PointNode *node = queue[0];
        [queue removeObject:node];
        for (int i = 0 ; i < _points.count; i ++) {
            if (_lines[node.value][i].integerValue > 0) {
                NSLog(@"broad:%zd",_points[i].value);
                [queue addObject:_points[i]];
                _points[i].isRead =true;
            }
        }
    }

}

- (void)depthFirstSearchWithPoint:(NSInteger)i {
    PointNode *point = _points[i];
    point.isRead = true;
    NSLog(@"depth:%zd",point.value);
    NSInteger nearPoint = [self findNearPoint:i];
    while (nearPoint != -1) {
        //如果途中遇到没有深度遍历的点,loop
        if (!_points[nearPoint].isRead) {
            [self depthFirstSearchWithPoint:nearPoint];
        }
        //去找到下一个临近的点
        nearPoint = [self findNearPoint:i index2:nearPoint];
    }
    
}

- (NSInteger)findNearPoint:(NSInteger)index {
    for (int  j = 0; j < _points.count; j ++) {
        if (_lines[index][j].integerValue > 0 ) {
            return j;
        }
    }
    return -1;
}

- (NSInteger)findNearPoint:(NSInteger)index  index2:(NSInteger)index2{
    for (NSInteger  j = index2+1; j < _points.count; j ++) {
        if (_lines[index][j].integerValue > 0 ) {
            return j;
        }
    }
    return -1;
}

@end
