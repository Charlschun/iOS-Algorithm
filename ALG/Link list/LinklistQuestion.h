//
//  Reverse Linked List.h
//  ALG
//
//  Created by junlongj on 2017/10/13.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LinkedList.h"
@interface LinklistQuestion : NSObject

+ (void)printList:(ListNode *)node;
//翻转链表
+ (ListNode *)reverse:(ListNode *)node;


/**
 Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 
 Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 

 @param deleteNode <#deleteNode description#>
 @param root <#root description#>
 */
+ (ListNode *)deleteNode:(id )deleteNodeValue inList:(ListNode *)root;


/**
 
 两个思路:
 第一个：先计算出链表的长度L,然后从前向后的第L-n+1就是我们要删除的节点.
 第二个:搞两个指针，他们的起始位置差了n，就是说first-second=n，然后当first跑到链表末尾的时候，second正好跑到倒数第n的位置.
 
 Given a linked list, remove the nth node from the end of list and return its head.
 
 For example,
 
 Given linked list: 1->2->3->4->5, and n = 2.
 
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.

 */
+(ListNode *)removeNthFrom:(NSInteger)nth inList:(ListNode *)root;


/**
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

 @param root <#root description#>
 @param root2 <#root2 description#>
 @return <#return value description#>
 */
+ (ListNode *)mergeTwoSortedList:(ListNode *)root other:(ListNode *)root2;


/**
 求两个链表的交点位置.
 暂不不考虑有环的情况、
 思路：单链表肯定是Y行交叉，就是说从交点位置起后续节点都一样。可以这样，求出两个链表的长度L1,L2,然后求出差值len,让长的那个链表先走len，短的那个再走，这样他们两个将同时到达交点处.

 @param root1 <#root1 description#>
 @param root2 <#root2 description#>
 @return <#return value description#>
 */
+ (ListNode *)pointOfIntersection:(ListNode *)root1 other:(ListNode *)root2;


/**
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 


 @param root <#root description#>
 @return <#return value description#>
 */
+ (ListNode *)deleteDuplicates:(ListNode *)root;

/**
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 

 */
+ (ListNode *)addTwoNumbers:(ListNode *)node1 node2:(ListNode *)node2;

/**
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

 @param lists <#lists description#>
 @return <#return value description#>
 */
+ (ListNode *)mergeKSortedLists:(NSArray<ListNode *>*)lists;

@end
