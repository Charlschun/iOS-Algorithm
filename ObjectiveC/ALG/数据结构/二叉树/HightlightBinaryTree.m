//
//  HightlightBinaryTree.m
//  ALG
//
//  Created by junlongj on 2017/9/26.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "HightlightBinaryTree.h"

@implementation BinaryTree(Hightlight)
+(instancetype)creatHightlightTree:(NSString *)str{
    BinaryTree *tree = [[[self class]alloc]init];
    tree.root = [tree creatHightlightTree:str node:nil];
    return tree;
}
int globalCT = -1;
- (BinaryTreeNode *)creatHightlightTree:(NSString *)str node:(BinaryTreeNode *)node {
    globalCT+=1;
    NSString *_c = [str substringWithRange:NSMakeRange(globalCT , 1)];

    if (![_c isEqualToString:@"#"]) {
        //创建节点
        node = [BinaryTreeNode creatNode:_c];

        NSLog(@"creat left node");
        //创建它的左节点 ，将两个节点连接 child.left -> self.left
        node.leftNode = [self creatHightlightTree:str node:node.leftNode];
        NSLog(@"creat right node");
        //创建它的右节点
        node.rightNode = [self creatHightlightTree:str node:node.rightNode];
    }
    return  node;
}

-(NSMutableArray *)findShortestPath{
    //首先的找到两个高亮的节点.
    NSMutableArray *hights = [NSMutableArray arrayWithCapacity:2];
    [self findhightlightNode:self.root tartgetArray:hights];
    if (hights.count != 2) {
        return nil;
    }
    //分别查找他们各自到根节点的路径
    NSMutableArray *hight1ToRootPaths = @[].mutableCopy;
    NSMutableArray *hight2ToRootPaths = @[].mutableCopy;
    [self nodeToRootPath:self.root
                findNode:hights[0] targetArray:hight1ToRootPaths];
    [self nodeToRootPath:self.root
                findNode:hights[1] targetArray:hight2ToRootPaths];

    NSMutableArray *paths = @[].mutableCopy;
    //寻找公共节点.
    for (NSInteger i = hight1ToRootPaths.count - 1; i >= 0; i --) {
        BinaryTreeNode *node1  = hight1ToRootPaths[i];
        [paths addObject:node1];
        for (NSInteger j = hight2ToRootPaths.count - 1; j >= 0 ; j -- ) {
            BinaryTreeNode *node2 = hight2ToRootPaths[j];
            if (node1 == node2) {
                //find公共节点.
                j +=1;//
                while (j <= hight2ToRootPaths.count -1) {
                    [paths addObject:hight2ToRootPaths[j]];
                    j+=1;
                }
               return paths;
            }
        }
    }
    
    return nil;
}

- (void)findhightlightNode:(BinaryTreeNode *)node
              tartgetArray:(NSMutableArray *)targetArray{
    //先序遍历
    // 先访问根，再遍历左子树，再遍历右子树。典型的递归思想。
    if (node == nil) {
        return;
    }
    if ([node.value isEqualToString:@"1"]) {
        //find
        [targetArray addObject:node];
    }
    [self findhightlightNode:node.leftNode tartgetArray:targetArray];
    [self findhightlightNode:node.rightNode   tartgetArray:targetArray];
}

- (BOOL)nodeToRootPath:(BinaryTreeNode *)node
              findNode:(BinaryTreeNode *)findNode
           targetArray:(NSMutableArray *)targetArray{
    if (node == nil) {
        return false;
    }
    if (node == findNode) {
        //find
        [targetArray addObject:node];
        return true;
    }
    //没找到的话，先把根节点压入栈,再找他的子节点
    [targetArray addObject:node];
    
    bool isFind = false;
    isFind = [self nodeToRootPath:node.leftNode findNode:findNode targetArray:targetArray];
    if (!isFind) {
       isFind = [self nodeToRootPath:node.rightNode findNode:findNode targetArray:targetArray];
    }
    if (!isFind) {
        [targetArray removeLastObject];
    }
    return isFind;
}


@end
