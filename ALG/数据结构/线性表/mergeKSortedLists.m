//
//  mergeKSortedLists.m
//  ALG
//
//  Created by junlongj on 2017/9/23.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "mergeKSortedLists.h"
ListNode *getMinNode(NSArray<ListNode *> *lists){
    return  [lists sortedArrayUsingComparator:^NSComparisonResult(ListNode*  _Nonnull obj1, ListNode*  _Nonnull obj2) {
        return  obj1.data >=obj2.data;
    }].firstObject;
}

ListNode *mergeKSortedLists(NSArray<ListNode *> *lists){
    ListNode *root =  ListNode.new;
    root.data = @0;
    ListNode *ct = root;//当前的node
    
    NSMutableArray *queue = @[].mutableCopy;
    [queue addObjectsFromArray:lists];
    while (queue.count) {
        //找到最新的节点以后
        ListNode *min = getMinNode(queue);
        [queue removeObject:min];
        //再把最小节点的next节点加入到数组中做比较
        if (min.next) {
            [queue addObject:min.next];
        }
        ct.next = min;
        ct = min;
    }
    
    return root.next;
}

