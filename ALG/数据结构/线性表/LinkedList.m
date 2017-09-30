//
//  LinkedList.m
//  ALG
//
//  Created by junlongj on 2017/9/22.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "LinkedList.h"

@implementation ListNode

+(instancetype)creat:(NSArray *)array{
    __block ListNode *root,*ct;
    [array enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        ListNode *temp = [ListNode new];
        temp.data = obj;
        if (root == nil) {
            root = temp;
            ct = temp;
            root.next = nil;
        }else{
            ct.next = temp;
            ct = temp;
        }
    }];
    
    return  root;
}

@end

@implementation List

+(instancetype)creat{
    return  [List new];
}

-(void)add:(id)value{
    ListNode *node = ListNode.new ;
    node.data = value;
    if (self.head == nil) {
        //头节点不存在
        self.head = node;
        self.tail = node;
    }else{
        self.tail.next = node;
        self.tail = node;
    }
    self.size ++;
}

- (void)traversal{
    ListNode *ct = self.head;
    while (ct) {
        NSLog(@"----%@",ct.data);
        ct = ct.next;
    }
}

- (ListNode *)find:(id)x{
    ListNode *ct = self.head;
    while (ct ) {
        if (ct.data == x) {
            //找到啦
            return ct;
        }
        ct = ct.next;
    }
    return nil;
}

- (void)deleteNode:(ListNode *)node{
    //1->2->3->4
    //1->2->4
    //把第四个节点的值赋给第三个节点
    node.data = node.next.data;
    //跳过第三个节点
    node.next = node.next.next;
}

- (void)delete:(id)x{
    ListNode *ct = self.head;
    if (self.head == nil) {
        return;
    }
    if (self.head.data == x ) {
        ListNode *newHead = self.head.next;
        self.head.next = nil;
        self.head = newHead;
        return;
    }
    //首先我要找到x的节点和之前的节点
    while (ct.next != nil && ct.next.data != x) {
        ct = ct.next;
    }
    //现在ct就是x之前的那个节点
    ListNode *pre = ct;
    ListNode *deleteNode = ct.next;
    ListNode *next = deleteNode.next;
    //如果要删除的是为节点的话
    if (deleteNode == self.tail) {
        pre.next = nil;
        self.tail=  pre;
    }else{
        deleteNode.next = nil;
        pre.next = nil;
        pre.next = next;
    }
    self.size --;
}

- (void)insert:(id) value afterNode:(ListNode *)afterNode{
    if (afterNode== nil) {
        return;
    }
    ListNode *node = ListNode.new;
    node.data = value;
    if (afterNode == self.tail) {
        //afternode为尾节点，直接插到最后
        afterNode.next = node;
        self.tail = node;
    }else{
        //
        ListNode *next =  afterNode.next;
        afterNode.next = nil;
        afterNode.next = node;
        node.next = next;
    }
    self.size++;
}

- (void)insertNodeAtLast:(ListNode *)node{
    if (node==nil) {
        return;
    }
    self.tail.next = node;
    self.tail = node;
    self.size++;
}

- (void)insertHead:(id)value{
    ListNode *node = ListNode.new;
    node.data = value;
    node.next=  self.head;
    self.head = node;
    self.size++;
}

-(void)reverse{
    NSLog(@"%s",__func__);
    ListNode *ct,*pre,*next;
    
    //断开根节点
    pre = self.head;
    ct = pre.next;
    pre.next = nil;
    while (ct) {
        next = ct.next;
        //依次将节点指向前一个节点.
        ct.next = pre;
        pre = ct ;
        ct = next;
    }
    self.tail = self.head;
    self.head = pre;
    
}
- (BOOL)isExistLoop{
    ListNode *slow,*fast;
    slow = fast = self.head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow == fast) {
            //find
            return true;
        }
    }
    return false;
}

- (NSInteger)ringLength{
    if (!self.isExistLoop) {
        return 0;
    }
    NSInteger lenght = 0;
    ListNode *slow,*fast;
    slow = fast = self.head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
       lenght ++;
        if (slow == fast) {
            //find
            break;
        }else{
        }
    }
    return lenght;
}

/**
 判断两个链表是否是相交的.相交的意思就是说，从相交的节点开始，以后的所有节点都是共有的。
 两个方法:
 1.把它们拼成一个链表，看是否形成环.
 2.如果他们相交，那么他们的最后一个节点肯定是一样的。
 

 @param other <#other description#>
 @return <#return value description#>
 */
- (BOOL)isIntersectWithList:(List *)other{
    //第一个方法
//    List *newList = self;
//    newList.tail.next = other.head;
//    return  [newList isExistLoop];
    
    //第二个方法
    ListNode *selfct = self.head;
    ListNode *otherct = other.head;
    while (selfct) {
        selfct = selfct.next;
    }
    while (otherct) {
        otherct = otherct.next;
    }
    if (selfct == otherct) {
        return true;
    }
    return false;
}


-(BOOL)isEmpty{
    return self.head == nil;
}

@end


