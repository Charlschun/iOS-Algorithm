//
//  HightlightBinaryTree.h
//  ALG
//
//  Created by junlongj on 2017/9/26.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BinaryTree.h"
//http://www.cnblogs.com/llhthinker/p/4906631.html

/**
 二叉树尤其就有两个是高亮的，找出他们间的最短路径
 1.创建二叉树
 2.找出高亮节点.
 3.求出他们到根节点的路径
 4.两层for循环找出他们的公共节点，然后连接起来.
 */
@interface BinaryTree (Hightlight)

+(instancetype)creatHightlightTree:(NSString *)str;

- (NSMutableArray *)findShortestPath;
@end



