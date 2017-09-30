//
//  LinkedList.h
//  ALG
//
//  Created by junlongj on 2017/9/22.
//  Copyright © 2017年 Jincc. All rights reserved.
//

/*
 1、如何判断一个单链表有环
 2、如何判断一个环的入口点在哪里
 3、如何知道环的长度
 4、如何知道两个单链表（无环）是否相交
 5、如果两个单链表（无环）相交，如何知道它们相交的第一个节点是什么
 6、如何知道两个单链表（有环）是否相交
 7、如果两个单链表（有环）相交，如何知道它们相交的第一个节点是什么
 
 
 3、从碰撞点开始，两个指针p和q，q以一步步长前进，q以两步步长前进，到下次碰撞所经过的操作次数即是环的长度。这很好理解，比如两个运动员A和B从起点开始跑步，A的速度是B的两倍，当A跑玩一圈的时候，B刚好跑完两圈，A和B又同时在起点上。此时A跑的长度即相当于环的长度。
 假设甩尾（在环外）长度为 len1（结点个数），环内长度为 len2 ，则时间复杂度为“环是否存在的时间复杂度”+O(len2)。
 
 4、法一：将链表A的尾节点的next指针指向链表B的头结点，从而构造了一个新链表。问题转化为求这个新链表是否有环的问题。
 时间复杂度为环是否存在的时间复杂度，即O（length(A)+length(B)），使用了两个额外指针
 法二：两个链表相交，则从相交的节点起，其后的所有的节点都是都是两个链表共有的。因此，如果它们相交，则最后一个节点一定是共有的。因此，判断两链表相交的方法是：遍历第一个链表，记住最后一个节点。然后遍历第二个链表，到最后一个节点时和第一个链表的最后一个节点做比较，如果相同，则相交。
 时间复杂度：O（length(A)+length(B)），但是只用了一个额外指针存储最后一个节点
 
 5、将链表A的尾节点的next指针指向链表B的头结点，从而构造了一个环。问题转化为求这个环的入口问题。
 时间复杂度：求环入口的时间复杂度
 
 6、分别判断两个链表A、B是否有环（注，两个有环链表相交是指这个环属于两个链表共有）
 如果仅有一个有环，则A、B不可能相交
 如果两个都有环，则求出A的环入口，判断其是否在B链表上，如果在，则说明A、B相交。
 时间复杂度：“环入口问题的时间复杂度”+O（length（B））
 
 7、分别计算出两个链表A、B的长度LA和LB（环的长度和环到入口点长度之和就是链表长度），参照问题3。
 如果LA>LB，则链表A指针先走LA-LB，链表B指针再开始走，则两个指针相遇的位置就是相交的第一个节点。
 如果LB>LA，则链表B指针先走LB-LA，链表A指针再开始走，则两个指针相遇的位置就是相交的第一个节点。
 时间复杂度：O（max（LA,LB））
 */

#import <Foundation/Foundation.h>
@interface ListNode :NSObject
@property (nonatomic ,strong)id data;
@property (nonatomic ,strong)ListNode *next;

+ (instancetype)creat:(NSArray *)array;
@end

@interface List :NSObject

@property (nonatomic ,strong)ListNode *head;//头节点
@property (nonatomic ,strong)ListNode *tail;//尾节点
@property (nonatomic ,assign)NSInteger size;

+ (instancetype)creat;
//增加节点
- (void)add:(id)value;
//遍历节点
- (void)traversal;
//查找node
- (ListNode *)find:(id)x;

- (void)delete:(id)x;

/**
 //1->2->3->4
 //1->2->4
 //把第四个节点的值赋给第三个节点
 //跳过第三个节点
 @param node <#node description#>
 */
- (void)deleteNode:(ListNode *)node;

- (void)insert:(id) value afterNode:(ListNode *)afterNode;

- (void)insertNodeAtLast:(ListNode *)node;

- (void)insertHead:(id)value;

/**
 反转链表
 */
- (void)reverse;

/**
 是否存在环 o(n)
 采用快慢步长法。令两个指针p和q分别指向头结点，p每次前进一步，q每次前进两步，如果p和q能重合，则有环。可以这么理解，这种做法相当于p静止不动，q每次前进一步，所有肯定有追上p的时候。

 @return <#return value description#>
 */
- (BOOL)isExistLoop;

/**
 环的长度 ,比如现在A,B在赛跑,A的速度是B的两倍，当A跑玩2圈的时候，B刚好跑完1圈。此时B跑的长度即相当于环的长度。
 2*v*t - v*t = 环的长度

 @return <#return value description#>
 */
- (NSInteger)ringLength;

- (BOOL)isEmpty;
@end


#import "addTwoNumbers.h"
#import "mergeKSortedLists.h"
#import "isPalindrome.h"

