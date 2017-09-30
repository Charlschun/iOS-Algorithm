//
//  isPalindrome.m
//  ALG
//
//  Created by junlongj on 2017/9/23.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "isPalindrome.h"

BOOL isPalindrome(ListNode *node){
    
    if (node == nil || node.next == nil) {
        return true;
    }
    NSMutableArray *front = @[].mutableCopy;
    ListNode *fast,*slow;
    fast = slow = node;
    //两个指针一起跑，当fast跑到末尾的时候，slow正好在一半的位置
    while (fast && fast.next) {
        [front addObject:slow.data];
        slow = slow.next;
        fast = fast.next.next;
    }
    if (fast) {
        slow = slow.next;
    }
    //开始比较stack里的数据和slow的后半截是不是一样的
    while (slow) {
        NSInteger lastIndex= front.count - 1;
        if (slow.data != front[lastIndex]) {
            return false;
        }
        //继续比较下一个
        slow = slow.next;
        [front removeObjectAtIndex:lastIndex];
    }
    return true;
    
}
