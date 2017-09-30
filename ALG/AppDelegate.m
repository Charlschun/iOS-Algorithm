//
//  AppDelegate.m
//  ALG
//
//  Created by junlongj on 2017/9/19.
//  Copyright © 2017年 Jincc. All rights reserved.
//

#import "AppDelegate.h"
#import "SortHandle.h"
#import "LinkedList.h"
#import "BinarySearch.h"
#import "BinaryTree.h"
#import "HightlightBinaryTree.h"
#import "Trie.h"
#import "Topkk.h"
#import "Graph.h"
@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
//    NSMutableArray *targetArray = @[].mutableCopy;
//    [targetArray addObject:@9];
//    for (int i = 0 ; i < 10; i ++) {
//        [targetArray addObject:@(arc4random_uniform(100))];
//    }
//    [targetArray addObject:@9];
//    NSLog(@"----%@",targetArray.description);
    //冒泡
//    [SortHandle bubbleSortWithArray:targetArray];
    //快速
//    [SortHandle quickSortWithArray:targetArray];
    //插入
//    [SortHandle insertSortWithArray:targetArray];
    //二分插入
//    [SortHandle binaryinsertSortWithArray:targetArray];
    //归并排序
//   [SortHandle mergeSortWithArray:targetArray];
    //堆排序
//    [SortHandle heapSort:targetArray];
    //希尔排序
//    [SortHandle shellSort:targetArray];
//    LinkedList *list =  [LinkedList creatLinked:targetArray.copy];
//    [LinkedList traversalLinked:list traversalBlock:^(LinkedList *node) {
//        NSLog(@"---%@",node->_data);
//    }];
//    //反转链表
//    list = [LinkedList reverseList:list];
//    [LinkedList traversalLinked:list traversalBlock:^(LinkedList *node) {
//        NSLog(@"反转后---%@",node->_data);
//    }];
//    NSLog(@"----%@",targetArray.description);
    
    
//   NSInteger index =  [BinarySearch binarySearchFindFirstEqual:targetArray target:9];
//
//    [self list];
//    [self addTwoNumbers];
//    [self mergeKSortedLists];
//    [self isPalindrome];
//    [self binaryTree];
//    [self HightlightBinaryTree];
//    [self trie];
//    [self topk];
    [self Graph];
    return YES;
}
- (void)Graph{
    Graph *graph = [Graph creat];
//    [graph depthFirstSearch];
    [graph broadFirstSearch];
}

- (void)topk{
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        NSMutableArray *heaps =  [Topkk topkUsingHeapWithKeyNumber:10];
        heaps = [Topkk topkUsingQuickSortWithKeyNumber:10];
    });
}

- (void)trie{
   Trie *dicTree =  [Trie creat];
    [dicTree insert:@"apple"];
    [dicTree insert:@"apcd"];
    [dicTree search:@"ap"];
}
- (void)HightlightBinaryTree{
    BinaryTree *tree =  [BinaryTree creatHightlightTree:@"0001##0##0##01#0##0##"];
    [tree levelTraverseWithHandler:^(BinaryTreeNode *treeNode) {
        
    }];
    [tree findShortestPath];
    
}


- (void)binaryTree{
    NSArray *arr = @[@5,@2,@8,@1,@3,@6,@10];
    BinaryTree *tree =  [BinaryTree creatTree:arr];
    
    
    [tree levelTraverseWithHandler:^(BinaryTreeNode *treeNode) {
        
    }];
    [tree preOrder:tree.root handle:^(BinaryTreeNode *node) {
        NSLog(@"preOrder:%@",node.value);
    }];
    [tree inOrder:tree.root handle:^(BinaryTreeNode *node) {
         NSLog(@"inOrder:%@",node.value);
    }];
    NSLog(@"删除节点10");
    [tree deleteNode:@2];
    [tree inOrder:tree.root handle:^(BinaryTreeNode *node) {
        NSLog(@"inOrder:%@",node.value);
    }];
    NSLog(@"反转二叉树");
    [tree reverseTree];
    [tree inOrder:tree.root handle:^(BinaryTreeNode *node) {
        NSLog(@"inOrder:%@",node.value);
    }];
    NSLog(@"非递归反转");
    [tree reverseNotRecursive];
    [tree inOrder:tree.root handle:^(BinaryTreeNode *node) {
        NSLog(@"inOrder:%@",node.value);
    }];
    NSLog(@"所有的节点数:%zd",[tree numberOfNodesInTree]);
    NSLog(@"数的宽度:%zd",[tree widthOfTree]);

    BinaryTreeNode *node = [tree findNode:@6];
    
    for (BinaryTreeNode *find_ in     [tree pathOfTree:node]) {
        NSLog(@"路径：%@",find_.value);
    }
    
}
- (void)list{
    List *list = [List creat];
    [list add:@2];
    [list add:@3];
    [list add:@4];
    [list add:@5];
    [list add:@6];
    [list add:@7];
    [list add:@8];
//    [list traversal];
    ListNode* find3 = [list find:@4];
    [list insertNodeAtLast:find3];
    
    BOOL isloop =  [list isExistLoop];
    NSLog(@"是否存在环:%i",isloop);
    NSLog(@"环的长度:%i",[list ringLength]);
//    [list insert:@5 afterNode:find3];
//    NSLog(@"find:%@",find3);
//    [list delete:@3];
//     [list traversal];
//    [list reverse];
//    [list traversal];
}

- (void)addTwoNumbers{
   // (2 -> 4 -> 3) + (5 -> 6 -> 4)
    // Output: 7 -> 0 -> 8
    ListNode *node1 = [ListNode creat:@[@2,@4,@3]];
    ListNode *node2 = [ListNode creat:@[@5,@6,@4]];
    ListNode *node3 = addTwoNumbers(node1, node2);
    while (node3) {
        NSLog(@"addTwoNumber:%@",node3.data);
        node3 = node3.next;
    }
}

- (void)mergeKSortedLists{
    ListNode *node1 = [ListNode creat:@[@2,@3,@4]];
    ListNode *node2 = [ListNode creat:@[@1,@6,@8]];
    ListNode *node3 =  mergeKSortedLists(@[node1,node2]);
    while (node3) {
        NSLog(@"mergeKSortedLists:%@",node3.data);
        node3 = node3.next;
    }
}
- (void)isPalindrome{
    ListNode *node = [ListNode creat:@[@"a",@"b",@"c",@"c",@"b",@"a"]];
    NSLog(@"是否为回文字符串:%i",isPalindrome(node));
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
