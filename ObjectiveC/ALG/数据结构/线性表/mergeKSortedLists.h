//
//  mergeKSortedLists.h
//  ALG
//
//  Created by junlongj on 2017/9/23.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LinkedList.h"
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
// 1->2->3
// 2->5->6

// 1->2->2->3->5->6
extern ListNode *mergeKSortedLists(NSArray<ListNode *> *lists);
