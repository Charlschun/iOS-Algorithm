//
//  TreeQuestion.m
//  ALG
//
//  Created by junlongj on 2017/10/15.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "TreeQuestion.h"

@implementation BTSNode

@end

@implementation TreeQuestion

+(BinaryTreeNode *)ConstructBinaryTreeByPreorder:(NSArray *)preorder andInorder:(NSArray *)inorder{
    
    if (!inorder.count || !preorder.count || inorder.count !=preorder.count) {
        return nil;
    }
    //先创建根节点.
    id rootV = preorder.firstObject;
    BinaryTreeNode *root = [BinaryTreeNode creatNode:rootV];
    //找到跟节点在中序数组中的位置
    int i = 0;
    for (; i < inorder.count; i ++) {
        if (inorder[i] == rootV) {
            break;
        }
    }
    //说明没找到
    if (i >=inorder.count) {
        return nil;
    }
    //左子树的先序数组和中序数组
    NSArray *leftPre = [preorder  subarrayWithRange:NSMakeRange(1, i)];
    NSArray *leftIn = [inorder subarrayWithRange:NSMakeRange(0, i)];
       //创建左子节点
    root.leftNode = [self ConstructBinaryTreeByPreorder:leftPre andInorder:leftIn];
    //获取
    NSArray *rightPre = [preorder subarrayWithRange:NSMakeRange(i+1, preorder.count - i - 1)];
    NSArray *rightin = [inorder subarrayWithRange:NSMakeRange(i+1, inorder.count - i - 1)];
   //创建右子节点.
    root.rightNode = [self ConstructBinaryTreeByPreorder:rightPre andInorder:rightin];
    return root;
    
}

+(BinaryTreeNode *)InvertBinaryTree:(BinaryTreeNode *)root{
    NSMutableArray *stack = [NSMutableArray array];
    [stack addObject:root];
    while (stack.count) {
        NSInteger count = stack.count;
        for ( int i = 0; i < count; i++) {
            BinaryTreeNode *ct = stack.firstObject;
            [stack removeObject:ct];
            BinaryTreeNode *temp = ct.leftNode;
            ct.leftNode = ct.rightNode;
            ct.rightNode = temp;
            if (ct.leftNode) {
                [stack addObject:ct.leftNode];
            }
            if (ct.rightNode) {
                [stack addObject:ct.rightNode];
            }
        }
    }
    return root;
}

+ (void)_InvertBinaryTree:(BinaryTreeNode *)root{
    if (root == nil) {
        return ;
    }
    if (root.leftNode ==nil && root.rightNode == nil) {
        return ;
    }
    //交换
    BinaryTreeNode *temp = root.leftNode;
    root.leftNode = root.rightNode;
    root.rightNode = temp;
    
    [self _InvertBinaryTree:root.leftNode];
    [self _InvertBinaryTree:root.rightNode];
}

+(NSMutableArray *)levelOrderBottom:(BinaryTreeNode *)root{
    NSMutableArray *stack = [NSMutableArray array];
    [stack addObject:root];
    NSMutableArray *result = @[].mutableCopy;
    while (stack.count) {
        NSMutableArray *sub = [[NSMutableArray alloc]init];
        NSInteger size = stack.count;
        for (int i = 0; i < size; i ++) {
            BinaryTreeNode *ct = stack.firstObject;
            [stack removeObject:ct];
            [sub addObject:ct.value];

            if (ct.leftNode) {
                [stack addObject:ct.leftNode];
            }
            if (ct.rightNode) {
                [stack addObject:ct.rightNode];
            }
        }
       [result addObject:sub];
    }
    return [result reverseObjectEnumerator].allObjects.mutableCopy;
}

+(BOOL)isSquenceOfBST:(NSArray *)afterResult
                start:(NSInteger)start
                  end:(NSInteger)end{
    //left<root<right
    //首先我们找到左子树，和右子树的范围》
    if (start< 0 || end <=0) {
        return true;
    }
    NSInteger findLocation = end;
    for (; findLocation >= 0 ; findLocation --) {
        if (afterResult[findLocation] < afterResult[end]) {
            break;
        }
    }
    
    //find
    for (int j = 0; j< findLocation ; j++) {
        if (afterResult[j] > afterResult[end]) {
            return false;
        }
    }
    //继续判断左右子树
    return [self isSquenceOfBST:afterResult start:start end:findLocation] && [self isSquenceOfBST:afterResult start:findLocation+1 end:end-1];
}

+ (NSMutableArray *)pathSumInTree:(BinaryTreeNode *)root sum:(NSInteger)sum;{
    NSMutableArray *target = [NSMutableArray array];
    [self pathSumInTree:root sum:sum pathArray:target];
    return target;
}
+ (BOOL)pathSumInTree:(BinaryTreeNode *)root sum:(NSInteger)sum pathArray:(NSMutableArray *)pathArray{
    if (root == nil) {
        return false;
    }
    [pathArray addObject:root.value];
    if (sum == [root.value integerValue]) {
        //路径找到完毕
        return pathArray;
    }
    sum = sum - [root.value integerValue];
    //继续在左右子树中找
    BOOL isFind = [self pathSumInTree:root.leftNode sum:sum pathArray:pathArray];
    if (!isFind) {
       isFind = [self pathSumInTree:root.rightNode sum:sum pathArray:pathArray];
    }
    //如果都没找到移除跟节点.
    if (!isFind) {
        [pathArray removeLastObject];
    }
    return isFind;
}

+(BTSNode *)nextPointInOrderTreeWithNode:(BTSNode *)node{
    if (node == nil) {
        return nil;
    }
    //中序顺序 左，跟，右
    //如果当前节点是跟的话，查看它是否存在右节点，返回的右节点的叶子左节点
    if (node.rightNode) {
        BTSNode *ct = node.rightNode;
        while (ct.leftNode) {
            ct = ct.leftNode;
        }
        return ct;
    }else{
        //不存在右子节点
        //如果它自身是左节点的话.下一个就是跟节点
        if (node.superNode.leftNode == node) {
            return node.superNode;
        }else{
            //它是右子节点.
            //向上找其父节点，直到父节点是其父节点的父节点的左孩子
            BTSNode *ct  = node.superNode;
            while (ct.superNode ) {
                if (ct == ct.superNode.leftNode) {
                    return ct.superNode;
                }
                ct = ct.superNode;
            }
            return nil;
        }
        
    }
}

+(BOOL)isValidBST:(BinaryTreeNode *)root {
    return [self _isValidBST:root min:NSIntegerMin max:NSIntegerMax];
}

+ (BOOL)_isValidBST:(BinaryTreeNode *)root min:(NSInteger)min max:(NSInteger)max{
    if (root == nil) {
        return true;
    }
    if ([root.value integerValue]>=min && [root.value integerValue] <=max) {
    }else{
        return false;
    }
    BOOL left = [self _isValidBST:root.leftNode min:min max:[root.value integerValue]] ;
    BOOL right = [self _isValidBST:root.rightNode min:[root.value integerValue] max:max] ;
    return left &&right;
}
@end
