//
//  Reverse Linked List.m
//  ALG
//
//  Created by junlongj on 2017/10/13.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "LinklistQuestion.h"

@implementation LinklistQuestion

+(ListNode *)reverse:(ListNode *)node{
    ListNode *pre,*ct;
    pre = node;
    ct = node.next;
    //根节点断开
    pre.next = nil;
    while (ct) {
        //当前的节点翻转
        ListNode *next = ct.next;
        ct.next = pre;
        
        pre = ct;
        ct = next;
    }
    [self printList:pre];
    return pre;
}

+ (ListNode *)deleteNode:(id )deleteNodeValue inList:(ListNode *)root{
    //1,2,3,4
    //1,2,4
    
    //所以说我要先找到3的前一个节点和后一个节点，然后把他们连接在一起
    
    ListNode *ct = root;
    if (deleteNodeValue == root.data) {
        return root.next;
    }
    while (ct.next && ct.next.data != deleteNodeValue) {
        ct = ct.next;
    }
    //ct就是2
    ListNode *deleteNode = ct.next;
    if (deleteNode == nil) {
        //说明删除的是最后的元素
        return ct;
    }
    deleteNode.data = deleteNode.next.data;
    ct.next = deleteNode.next;
    return root;
}

+(ListNode *)removeNthFrom:(NSInteger)nth inList:(ListNode *)root{
    ListNode *first,*second;
    first = second = root;
    for (int i = 0; i < nth; i++) {
        first = first.next;
    }
    //现在first和second之间的距离为n
    ListNode *lasted = nil;
    while (first.next) {
        lasted = first;
        first = first.next;
        second = second.next;
    }
    if (nth == 1) {
        //删除为节点
        lasted.next = nil;
        return root;
    }else{
        //删除节点
        second.next = second.next.next;
        return root;
    }
}

+(ListNode *)mergeTwoSortedList:(ListNode *)root other:(ListNode *)root2{
    ListNode *ct1,*ct2,*mergeRoot,*ctMerge;
    ct1 = root;
    ct2= root2;
    
    while (ct1 && ct2) {
        ListNode * result = [ListNode new];
        if (ct1.data < ct2.data) {
            result.data = ct1.data;
            ct1 = ct1.next;
        }else{
            result.data = ct2.data;
            ct2 = ct2.next;
        }
        if (mergeRoot == nil) {
            mergeRoot = result;
            ctMerge = mergeRoot;
        }else{
            ctMerge.next = result;
            ctMerge = result;
        }
    }
    while (ct1) {
        ListNode * result = [ListNode new];
        result.data = ct1.data;
        ctMerge.next = result;
        ctMerge = result;
        ct1 = ct1.next;
    }
    while (ct2) {
        ListNode * result = [ListNode new];
        result.data = ct2.data;
        ctMerge.next = result;
        ctMerge = result;
        ct2 = ct2.next;
    }
    return mergeRoot;
}


+(ListNode *)pointOfIntersection:(ListNode *)root1 other:(ListNode *)root2{
    NSInteger length1 ,length2;
    length2 = length1 = 0;
    //求出链表1的长度
    ListNode *ct1,*ct2;
    ct1 = root1;
    ct2 = root2;
    while (ct1) {
        length1+=1;
        ct1 = ct1.next;
    }
    //求出链表2的长度.
    while (ct2) {
        length2 +=1;
        ct2 = ct2.next;
    }
    ct1 = root1;
    ct2 = root2;
     //如果两个链表长度不一样
    if (length1 > length2) {
        NSInteger i = length1 - length2;
        while (i>0) {
            i--;
            ct1 = ct1.next;
        }
    }else if (length1 < length2){
        NSInteger i = length2 - length1;
        while (i>0) {
            i--;
            ct2 = ct2.next;
        }
    }
    
    while (ct1&&ct2) {
        if (ct1.data == ct2.data) {
            return ct1;
        }
        ct1 = ct1.next;
        ct2 = ct2.next;
    }
    return nil;
    
}

+(ListNode *)deleteDuplicates:(ListNode *)root{
    ListNode *ct = root;
    while (ct && ct.next) {
        if (ct.data == ct.next.data) {
            ct.next =  ct.next.next;
        }else{
            ct = ct.next;
        }
    }
    return root;
}

+(ListNode *)addTwoNumbers:(ListNode *)node1 node2:(ListNode *)node2{
    ListNode *root = nil,*ct = nil;
    /*
     Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
     Output: 7 -> 0 -> 8
     */
    ListNode *ct1,*ct2;
    ct1 = node1;
    ct2 = node2;
    NSInteger sum = 0;
    while (ct1 && ct2) {
       sum = [ct1.data integerValue] + [ct2.data integerValue] + sum;
        ListNode *node = [ListNode new];
        node.data = @(sum %10);
        if (root == nil) {
            root = node;
            ct = node;
        }else{
            ct.next = node;
            ct = node;
        }
        sum  = sum / 10;
        ct1 = ct1.next;
        ct2 = ct2.next;
    }
    return root;
}

+(ListNode *)mergeKSortedLists:(NSArray<ListNode *> *)lists{
    ListNode *root = [ListNode new];
    ListNode *ct = root;
    NSMutableArray *stack = [lists mutableCopy];
    while (stack.count) {
        //获取stack中最新的节点
       ListNode *minNode =  [self getMinNodeInLists:stack];
        //创建新的节点
        ListNode *newNode = [ListNode new];
        newNode.data = minNode.data;
        ct.next = newNode;
        ct = newNode;
        [stack removeObject:minNode];
        if (minNode.next) {
            [stack addObject:minNode.next];
        }
    }
    return root.next;
}

+(ListNode *)getMinNodeInLists:(NSArray<ListNode *> *)lists{
   return  [lists sortedArrayUsingComparator:^NSComparisonResult(ListNode*  _Nonnull obj1, ListNode*  _Nonnull obj2) {
        return obj1.data >= obj2.data;
    }].firstObject;
}

+ (void)printList:(ListNode *)node{
    ListNode *ct = node;
    while (ct) {
        NSLog(@"printList----%@",ct.data);
        ct = ct.next;
    }
}

@end
