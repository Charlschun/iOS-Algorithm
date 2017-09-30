//
//  addTwoNumbers.m
//  ALG
//
//  Created by junlongj on 2017/9/23.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "addTwoNumbers.h"

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
ListNode *addTwoNumbers(ListNode *node1,ListNode*node2){
    ListNode *root =  ListNode.new;
    root.data = @0;
    ListNode *ct1,*ct2,*ct;
    ct1 = node1;
    ct2 = node2;
    ct = root;
    NSInteger sum = 0;
    while (ct1 && ct2) {
        //每一次要先加入上一次和的整数部分
        sum /=10;
        //+ node1
        if (ct1) {
            sum += [ct1.data integerValue];
            ct1 = ct1.next;
        }
        //+node2
        if (ct2) {
            sum += [ct2.data integerValue];
            ct2 = ct2.next;
        }
        //当前只保留余数部分，整数部分记到下一次数据中
        ListNode *remainder =  ListNode.new;
        remainder.data = @(sum %10);
        ct.next = remainder;
        ct = remainder;
    }
    //判断最后一次时候还有整数部分
    if (sum/10==1) {
        ListNode *remainder =  ListNode.new;
        remainder.data = @(1);
        ct.next = remainder;
    }
    return root.next;
}
