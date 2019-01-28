//
//  BinaryTree.m
//  ALG
//
//  Created by junlongj on 2017/9/25.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "BinaryTree.h"

@implementation BinaryTreeNode
+(instancetype)creatNode:(id)value{
    BinaryTreeNode *node = BinaryTreeNode.new;
    node.value = value;
    return node;
}
@end

@implementation BinaryTree

#pragma mark - public

- (BinaryTreeNode *)findNode:(id)value{
    BinaryTreeNode *ct = self.root;
    while (ct) {
        if (ct.value == value) {
            return  ct;
        }else if (ct.value > value){
            ct =  ct.leftNode;
        }else{
            ct = ct.rightNode;
        }
    }

    return ct;
}

-(BOOL)deleteNode:(id)value{
    BinaryTreeNode *ct = self.root;
    BinaryTreeNode *parentNode = nil;
    BOOL isLeft = true;
    while (ct && ct.value != value) {
        parentNode = ct;
        if (ct.value > value){
            ct =  ct.leftNode;
            isLeft = true;
        }else{
            isLeft = false;
            ct = ct.rightNode;
        }
    }
    if (ct == nil) {
        NSLog(@"要删除的节点不存在");
        return false;
    }
    
    BinaryTreeNode *deleteNode = ct;
    //要删除的节点有三种情况
    // 1.叶子结点
    //2.该节点有一个子节点
    //3.该节点有二个子节点
    if (deleteNode.leftNode == nil && deleteNode.rightNode == nil) {
        //如果为根节点
        if (deleteNode == self.root) {
            self.root = nil;
            return true;
        }
        if (isLeft) {
            parentNode.leftNode = nil;
        }else{
            parentNode.rightNode = nil;
        }
    }else if (deleteNode.leftNode  && deleteNode.rightNode){
        //两个节点都存在
        //而对于要删除的结点有两个儿子的情况，比较常用处理逻辑为，在其子树中找寻一个结点来替换，而这个结点我们成为中序后继结点。
        //对于这个节点，他应该是中序排序deleteNode相邻的两个节点中的一个.
        
        BinaryTreeNode *succeederNode = [self _findSucceederNode:deleteNode];
        if (deleteNode == self.root) {
            self.root = succeederNode;
            return true;
        }else{
            if (isLeft) {
                parentNode.leftNode = succeederNode;
            }else{
                parentNode.rightNode = succeederNode;
            }
        }
        
        
        
    }else{
        //只有一个子节点
        BinaryTreeNode *existNode = deleteNode.leftNode ? deleteNode.leftNode : deleteNode.rightNode;
        if (deleteNode == self.root) {
            self.root = existNode;
            return true;
        }
        if (isLeft) {
            parentNode.leftNode = existNode;
        }else{
            parentNode.rightNode =existNode;
        }
    }
    
    return  true;
}

- (BinaryTreeNode *)_findSucceederNode:(BinaryTreeNode *)deleteNode{
    
    /*
                       5
                 2           8
             1       3    6    10
     */
    BinaryTreeNode  *rct,*rparent;
    //rightNode的值会大于deleteNode的值
    rct = deleteNode.rightNode;
    //然后一直找到最小的值
    while (rct.leftNode) {
        rparent = rct;
        rct = rct.leftNode;
    }
    //如果后继节点是deleteNode的右子节点的话
    //看上面的图，比如现在要删除2这个节点，后继节点为3
    if (rct == deleteNode.rightNode) {
        //3.left = 1
        rct.leftNode = deleteNode.leftNode;
        deleteNode.leftNode = nil;
        deleteNode.rightNode = nil;
        return rct;
    }else{
        //rct为发现的替换root的节点
        rparent.leftNode = nil;
        rct.leftNode = deleteNode.leftNode;
        rct.rightNode = deleteNode.rightNode;
        return rct;
    }
}

- (NSMutableArray *)pathOfTree:(BinaryTreeNode *)targetNode{
    if (targetNode == nil) {
        return nil;
    }
    NSMutableArray *array = @[].mutableCopy;
    [self _findNodeIntree:targetNode otherNode:self.root pathArray:array];
    return array;
}

- (BOOL)_findNodeIntree:(BinaryTreeNode *)targetNode otherNode:(BinaryTreeNode *)rootNode pathArray:(NSMutableArray *)paths
{
    if (rootNode == nil) {
        return false;
    }
    //节点==target，找到啦
    if (targetNode == rootNode) {
        //find
        [paths addObject:targetNode];
        return true;
    }
    //把根节点压入数组
    [paths addObject:rootNode];
    BOOL isFind = false;
    //先找左子树
    isFind = [self _findNodeIntree:targetNode otherNode:rootNode.leftNode pathArray:paths];
    //再找右子树
    if (!isFind) {
         isFind = [self _findNodeIntree:targetNode otherNode:rootNode.rightNode pathArray:paths];
    }
    //如果都没找到移除跟节点.
    if (!isFind) {
        [paths removeLastObject];
    }
    return isFind;
}
-(NSInteger)numberOfNodesInTree{
    return  [self _numberOfNodesInTree:self.root];
}

-(NSInteger)_numberOfNodesInTree:(BinaryTreeNode *)node{
    if (node == nil) {
        return 0;
    }
    return [self _numberOfNodesInTree:node.leftNode] + [self _numberOfNodesInTree:node.rightNode] + 1;
}

-(NSInteger)widthOfTree{
    //从头结点开始，记录每一层的个数，对于当前层的每一个节点，在他们弹出自身后将其左右节点压入dequeue，当把当前层全部弹出之后，在队列剩下的就是下一层的节点。
    if (self.root == nil) {
        return 0;
    }
    NSInteger maxWidth = 0;
    NSInteger curWidth = 0;//当前层的宽度
    NSMutableArray *queue=  @[].mutableCopy;
    [queue addObject:self.root];
    
    while (true) {
        curWidth = queue.count;
        if (curWidth == 0) {
            break;
        }
        NSInteger j = curWidth;
        while (j > 0) {
            j -=1;
            BinaryTreeNode *root = queue.firstObject;
            [queue removeObject:root];
            if (root.leftNode) {
                [queue addObject:root.leftNode];
            }
            if (root.rightNode) {
                [queue addObject:root.rightNode];
            }
        }
        maxWidth = MAX(queue.count, maxWidth);
    }
    return maxWidth;
}

- (NSInteger)depthInTree{
    return [self _depthInTree:self.root];
}

- (NSInteger)_depthInTree:(BinaryTreeNode *)node{
    if (node == nil) {
        return 0;
    }
    //叶子节点
    if (node.leftNode == nil && node.rightNode == nil) {
        return 1;
    }
    NSInteger leftDepth = [self _depthInTree:node.leftNode];
    NSInteger rightDepth = [self _depthInTree:node.rightNode];
    return  MAX(leftDepth, rightDepth) + 1;
}

-(void)reverseNotRecursive{
    if (!self.root) {
        return;
    }
    if (self.root.leftNode == nil  && self.root.rightNode == nil) {
        return;
    }
    NSMutableArray *queue = @[].mutableCopy;
    //加入根节点
    [queue addObject:self.root];
    while (queue.count != 0 ) {
        BinaryTreeNode *node =  [queue objectAtIndex:0];
        [queue removeObject:node];
        BinaryTreeNode *nodeTemp = node.leftNode;
        //交换左右节点
        node.leftNode = node.rightNode;
        node.rightNode = nodeTemp;
        if (node.leftNode) {
            [queue addObject:node.leftNode];
        }
        if (node.rightNode) {
            [queue addObject:node.rightNode];
        }
    }
}

-(void)reverseTree{
    [self _reverseTreeNode:self.root];
}
- (void)_reverseTreeNode:(BinaryTreeNode *)node{
    if (!node) {
        return;
    }
    if (node.leftNode == nil  && node.rightNode == nil) {
        return;
    }
    //反转二叉树
    BinaryTreeNode *temp = node.leftNode;
    node.leftNode = node.rightNode;
    node.rightNode = temp;
    
    //继续递归交换子节点
    [self _reverseTreeNode:node.leftNode];
    [self _reverseTreeNode:node.rightNode];
}

- (void)addNode:(id)value{
    BinaryTreeNode *node = [BinaryTreeNode creatNode:value];
    if (self.root == nil) {
        self.root = node;
        return;
    }
    //循环遍历
    BinaryTreeNode *ct = self.root;
    while (true) {
        if (value <= ct.value) {
            //放在左子树
            //如果左子树不存在，创建左子树,结束
            if (ct.leftNode == nil) {
                ct.leftNode = node;
                return;
            }else{
                //如果存在，继续判断左子树的value与value
                ct = ct.leftNode;
            }
        }else{
            //放在右子树
            if (ct.rightNode == nil) {
                ct.rightNode = node;
                return;
            }else{
                ct = ct.rightNode;
            }
        }
    }
}

/**
 广度优先 

 @param handler <#handler description#>
 */
- (void)levelTraverseWithHandler:(void(^)(BinaryTreeNode *treeNode))handler{
    
    if (self.root == nil) {
        return;
    }
    NSInteger ctWidth = 0;
    NSMutableArray *queue = @[].mutableCopy;
    [queue addObject:self.root];
    
    while (true) {
        ctWidth = queue.count;
        if (queue.count == 0) {
            break;
        }
        NSInteger j = ctWidth;
        //弹出当前层里面的所有节点。
        NSMutableString *string =  [NSMutableString string];
        while (j>0) {
            j -=1;
            BinaryTreeNode *root = queue.firstObject;
            [queue removeObject:root];
            if (handler) {
                handler(root);
            }
            if (j != 0) {
                [string appendFormat:@"%@    ",root.value];
            }else{
                [string appendFormat:@"%@\n",root.value];
            }
            if (root.leftNode) {
                [queue addObject:root.leftNode];
            }
            if (root.rightNode) {
                [queue addObject:root.rightNode];
            }
        }
        NSLog(@"%@",string);
    }
}

- (void)preOrder:(BinaryTreeNode *)node handle:(void(^)(BinaryTreeNode*))handle{
    //先序遍历
   // 先访问根，再遍历左子树，再遍历右子树。典型的递归思想。
    if (node == nil) {
        return;
    }
    if (handle) {
        handle(node);
    }
    [self preOrder:node.leftNode handle:handle];
    [self preOrder:node.rightNode handle:handle];

}

- (void)inOrder:(BinaryTreeNode *)node handle:(void(^)(BinaryTreeNode*))handle{
    //中序遍历
    // 再遍历左子树，访问根，再遍历右子树。典型的递归思想。
    if (node == nil) {
        return;
    }
    [self inOrder:node.leftNode handle:handle];
    if (handle) {
        handle(node);
    }
    [self inOrder:node.rightNode handle:handle];
    
}

- (void)postOrder:(BinaryTreeNode *)node  handle:(void(^)(BinaryTreeNode*))handle{
    if (node == nil) {
        return;
    }
    [self postOrder:node.leftNode handle:handle];
    [self postOrder:node.rightNode handle:handle];
    if (handle) {
        handle(node);
    }
}

/**
 是否平衡二叉树
从根节点出发，邱左右节点的深度，如果误差>1的话，就不是平衡二叉树，否则继续遍历子节点.

 @param node <#node description#>
 @return <#return value description#>
 */
- (BOOL)isBalancedTree:(BinaryTreeNode *)node{
    if (node == nil) {
        return  true;
    }
    NSInteger leftDepth = [self _depthInTree:node.leftNode];
    NSInteger rightDepth = [self _depthInTree:node.rightNode];
    if (abs((int)(leftDepth - rightDepth))>1) {
        return  false;
    }
    return [self isBalancedTree:node.leftNode] && [self isBalancedTree:node.rightNode];
}

/**
 是否是完全二叉树
 我们遍历到空洞的时候，就会发现，空洞后面还有没有遍历到的值。这样，只要根据是否遍历到空洞，整个树的遍历是否结束来判断是否是完全的二叉树。
 


 @return <#return value description#>
 */
-(BOOL)isCompleteTree{
    NSMutableArray *queue = @[].mutableCopy;
    [queue addObject:self.root];
    // 广度优先遍历,找到第一个null节点
    while (queue.lastObject != [NSNull null]) {
        BinaryTreeNode *node = queue.lastObject;
        [queue removeObject:node];
        if (node.leftNode) {
            [queue addObject:node.leftNode];
        }else{
            [queue addObject:[NSNull null]];
        }
        if (node.rightNode) {
            [queue addObject:node.rightNode];
        }else{
            [queue addObject:[NSNull null]];
        }
    }
    while (queue.count > 0) {
        BinaryTreeNode *node = queue.lastObject;
        [queue removeObject:node];
        if (![node isEqual:[NSNull null]]) {
            return false;
        }
    }
    return true;
}

+(BinaryTree*)creatTree:(NSArray *)array{
    BinaryTree *tree = BinaryTree.new;
    for (NSNumber *value  in array) {
        [tree addNode:value];
    }
    return tree;
}



@end
