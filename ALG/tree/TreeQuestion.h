//
//  TreeQuestion.h
//  ALG
//
//  Created by junlongj on 2017/10/15.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BinaryTree.h"


@interface BTSNode:NSObject
@property (nonatomic ,strong)id value;
@property (nonatomic ,strong)BTSNode *leftNode;
@property (nonatomic ,strong)BTSNode *rightNode;
@property (nonatomic,strong )BTSNode *superNode;
@end


@interface TreeQuestion : NSObject

/**
 Given inorder and postorder traversal of a tree, construct the binary tree.
 根据先序和中序结果构建二叉树
 思路:
 
 1.根据前序（后序也适用）遍历结果，找到树根，设为ROOT，并生成一个以ROOT为根节点，左右子树
 都为NULL的树
 2.根据ROOT在中序遍历中的索引，将中序遍历结果分为：左子树，右子树；同时我们也要明确左右子树
 对应的前序（后序）遍历结果
 3.递归的执行步骤1和2即可构造出唯一的二叉树。

 */
+(BinaryTreeNode *)ConstructBinaryTreeByPreorder:(NSArray *)preorder andInorder:(NSArray *)inorder;

+ (BinaryTreeNode *)InvertBinaryTree:(BinaryTreeNode *)root;

/**
 思路的话：
 广度优先遍历
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 
 For example:
 Given binary tree [3,9,20,null,null,15,7],
 3
 / \
 9  20
 /  \
 15   7
 return its bottom-up level order traversal as:
 [
 [15,7],
 [9,20],
 [3]
 ]

 */
+ (NSMutableArray *)levelOrderBottom:(BinaryTreeNode *)root;

/**
 判断一个数组是不是二叉排序树的后序遍历
 思路：
 1.从第0位开始，找到第一位比根节点大的元素，记录此位置i。在此位置之前都属于左子树（此时已经断定左子树都小于根节点）
 2.检查右子树是否都大于跟节点（从第i位开始，到根节点前）
 3.递归判断左右子树是否都属于二叉搜索树
 @param afterResult
 @param start <#end description#>
 @param end <#end description#>
 @return <#return value description#>
 */
+ (BOOL)isSquenceOfBST:(NSArray *)afterResult start:(NSInteger)start end:(NSInteger)end;


+ (NSMutableArray *)pathSumInTree:(BinaryTreeNode *)root sum:(NSInteger)sum;;

/**
 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
思路：
 
 根据中序遍历的特点，要找到一个节点的下一个节点无非就是三种情况：
 1、有右子树，这时只需要把其右孩子作为下一个遍历的（并不是要找的）节点，然后沿着该节点的左子树（如果有的话）出发，直到遇到叶子节点，那么该叶子节点就是其下一个要找的节点；
 2、没有右子树，则判断该节点是否是其父节点的左孩子，如果是则其下一个要找的节点是其父节点；
 3、如果不是其父节点的左孩子，则把其父节点作为下一个遍历的节点，向上回溯，直到找到父节点没有父节点并且父节点是父节点的父节点的左孩子为止。综合这三种情况就可以找到二叉树中任意一个节点的下一个节点。
 

 @param node <#node description#>
 @return <#return value description#>
 */
+ (BTSNode *)nextPointInOrderTreeWithNode:(BTSNode *)node;
@end
