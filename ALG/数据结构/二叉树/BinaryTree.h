//
//  BinaryTree.h
//  ALG
//
//  Created by junlongj on 2017/9/25.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BinaryTreeNode:NSObject
@property (nonatomic ,strong)id value;
@property (nonatomic ,strong)BinaryTreeNode *leftNode;
@property (nonatomic ,strong)BinaryTreeNode *rightNode;
+ (instancetype)creatNode:(id)value;
@end

/**
 二叉排序树概念:（1）若左子树不空，则左子树上所有结点的值均小于或等于它的根结点的值；
 　　　　（2）若右子树不空，则右子树上所有结点的值均大于或等于它的根结点的值；
 　　　　（3）左、右子树也分别为二叉排序树；树

 索引：O(log(n))
 查找：O(log(n))
 插入：O(log(n))
 删除：O(log(n))
 */
@interface BinaryTree : NSObject

@property (nonatomic ,strong)BinaryTreeNode *root;
/**
 创建树
 */
+ (instancetype)creatTree:(NSArray *)array;


- (void)addNode:(id)value;


/**
 发现节点

 @param value <#value description#>
 @return <#return value description#>
 */
- (BinaryTreeNode *)findNode:(id)value;

/**
 targetNode --------- root node之间的路径
 思路：
 先判断根节点是不是目标node,将rootnode压入栈，在rootnode的左子树和右子树里寻找，如果都没找到的话，删除rootnode


 @param targetNode <#targetNode description#>
 @return <#return value description#>
 */
- (NSMutableArray *)pathOfTree:(BinaryTreeNode *)targetNode;

/**
 所有的节点数
 左节点+右节+1

 @return <#return value description#>
 */
- (NSInteger)numberOfNodesInTree;

/**
 数的深度

 @return <#return value description#>
 */
- (NSInteger)depthInTree;


/**
 二叉树的宽度
 
 从头结点开始，记录每一层的个数，对于当前层的每一个节点，在他们弹出自身后将其左右节点压入dequeue，当把当前层全部弹出之后，在队列剩下的就是下一层的节点。

 @return <#return value description#>
 */
- (NSInteger)widthOfTree;
/**
 /**
   删除节点

  @param BOOL 删除成功与否
  @return <#return value description#>
  */

- (BOOL)deleteNode:(id)value;

/**
  反转二叉树，即交换所有节点的左右子树。
 */
- (void)reverseTree;

- (void)reverseNotRecursive;

/**
 广度优先
 
 从头结点开始，记录每一层的个数，对于当前层的每一个节点，在他们弹出自身后将其左右节点压入dequeue，当把当前层全部弹出之后，在队列剩下的就是下一层的节点。
 
 @param handler
 */
- (void)levelTraverseWithHandler:(void(^)(BinaryTreeNode *treeNode))handler;

/**
 //先序遍历
 // 先访问根，再遍历左子树，再遍历右子树。典型的递归思想。

 @param node <#rootNode description#>
 @param handle <#handle description#>
 */
- (void)preOrder:(BinaryTreeNode *)node handle:(void(^)(BinaryTreeNode*))handle;


/**
 　　从根节点开始（注意并不是先访问根节点），中序遍历根节点的左子树，然后是访问根节点，最后中序遍历右子树。可以看到，如果是二叉排序树，中序遍历的结果就是个有序序列。

 @param node <#node description#>
 @param handle <#handle description#>
 */
- (void)inOrder:(BinaryTreeNode *)node handle:(void(^)(BinaryTreeNode*))handle;

/**
 左、右、根

 @param node <#node description#>
 @param handle <#handle description#>
 */
- (void)postOrder:(BinaryTreeNode *)node  handle:(void(^)(BinaryTreeNode*))handle;

/**
 是否平衡二叉树
 从根节点出发，邱左右节点的深度，如果误差>1的话，就不是平衡二叉树，否则继续遍历子节点.
 
 @param node
 @return <#return value description#>
 */
- (BOOL)isBalancedTree:(BinaryTreeNode *)node;

/**
 是否是完全二叉树
 我们遍历到空洞的时候，就会发现，空洞后面还有没有遍历到的值。这样，只要根据是否遍历到空洞，整个树的遍历是否结束来判断是否是完全的二叉树。
 
 
 
 @return <#return value description#>
 */
-(BOOL)isCompleteTree;
@end
