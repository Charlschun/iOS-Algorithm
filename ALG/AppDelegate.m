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
#import "DynamicProgramming.h"
#import "GreedyALG.h"
#import "Longest Palindromic Substring.h"
#import "Longest Substring Without Repeating Characters.h"
#import "String to Integer.h"
#import "Full Permutation.h"
#import "Maximum Subarray.h"
#import "Two sorted array Median.h"
#import "Find Minimum in Rotated Sorted Array.h"
#import "Find Num in Yang Array.h"
#import "Find more than half of the array number.h"
#import "Kth Largest Element in an Array.h"
#import "Find specific num count in Orderly array.h"
#import "LinklistQuestion.h"
#import "TreeQuestion.h"
#import "Two num.h"
#import "_3Num.h"
#import "Valid Parentheses.h"
#import "Implement strStr().h"
#import "Generate Parentheses.h"
#import "Group Anagrams.h"
#import "Add Binary.h"
#import "Combinations.h"
#import "Word Search.h"
#import "Decode Ways.h"
#import "isPalindrome.h"
#import "Valid Palindrome.h"
#import "Palindrome Partitioning.h"
@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    NSMutableArray *targetArray = @[].mutableCopy;
    [targetArray addObject:@9];
    for (int i = 0 ; i < 10; i ++) {
        [targetArray addObject:@(arc4random_uniform(100))];
    }
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
//    [self Graph];
//    [self greedy];
//    [self dynamicProgramming];
    [self string_alg];
    [self dynamic_alg];
    [self array_alg];
    [self linkedlist_alg];
    [self tree_alg];
    [self other_alg];
    return YES;
}
- (void)other_alg{
    NSArray *combinations = [Combinations CombinationsWithRange:4 count:2];
    NSLog(@"排列1..4中的2个数:%@",combinations);
}
- (void)tree_alg{
    NSLog(@"根据先序和中序结果，创建二叉树");
    BinaryTreeNode *node =  [TreeQuestion ConstructBinaryTreeByPreorder:@[@1,@2,@4,@5,@3,@6] andInorder:@[@4,@2,@5,@1,@3,@6]];
    BinaryTree *tree = [BinaryTree new];
    tree.root = node;
    [tree inOrder:node handle:^(BinaryTreeNode *node) {
        NSLog(@"node:%@",node.value);
    }];
    NSLog(@"反转二叉树");
    [TreeQuestion InvertBinaryTree:node];
    [tree inOrder:node handle:^(BinaryTreeNode *node) {
        NSLog(@"node:%@",node.value);
    }];
    NSLog(@"DFS its bottom-up level order traversal");
    NSMutableArray *leavelBottom =  [TreeQuestion levelOrderBottom:node];
    NSLog(@"%@",leavelBottom.description);
    NSMutableArray *result = [TreeQuestion pathSumInTree:node sum:101];
    NSLog(@"找到二叉树中和为10的路径:%@",result);
    
    BinaryTreeNode *node2=  [BinaryTreeNode creatNode:@2];
    BinaryTreeNode *node3=  [BinaryTreeNode creatNode:@3];
    BinaryTreeNode *node4=  [BinaryTreeNode creatNode:@4];
    BinaryTreeNode *node5=  [BinaryTreeNode creatNode:@5];
    BinaryTreeNode *node6=  [BinaryTreeNode creatNode:@6];
    BinaryTreeNode *node7=  [BinaryTreeNode creatNode:@7];
    BinaryTreeNode *node8=  [BinaryTreeNode creatNode:@8];
    BinaryTreeNode *node9=  [BinaryTreeNode creatNode:@9];
    node.value = @1;
    node.leftNode = node2;
    node.rightNode = node3;
    node2.leftNode = node4;
    node2.rightNode = node5;
    node3.leftNode = node6;
    node3.rightNode = node7;
    node5.leftNode = node8;
    node5.rightNode = node9;
    [tree inOrder:node handle:^(BinaryTreeNode *node) {
        NSLog(@"node:%@",node.value);
    }];
    
}

- (void)linkedlist_alg{
    ListNode *origin = [ListNode creat:@[@1,@2,@3,@4]];
    ListNode *node = origin;
     NSLog(@"翻转链表");
    node = [LinklistQuestion reverse:node];
    //删除链表指定节点
    NSLog(@"删除链表指定节点");
    node = [LinklistQuestion deleteNode:@2 inList:node];
    [LinklistQuestion printList:node];

    NSLog(@"删除倒数第二个节点");
    node = [ListNode creat:@[@1,@2,@3,@4]];
    node = [LinklistQuestion removeNthFrom:2 inList:node];
   [LinklistQuestion printList:node];
    
    NSLog(@"合并两个有序链表");
    
   node =  [LinklistQuestion mergeTwoSortedList:[ListNode creat:@[@1,@3,@5,@7]] other:[ListNode creat:@[@2,@4,@6]]];
    [LinklistQuestion printList:node];
    
    ListNode *node1 = [ListNode new];
    node1.data = @1;
    ListNode *node2 = [ListNode new];
    node2.data = @2;
    ListNode *node3 = [ListNode new];
    node3.data = @3;
    ListNode *node4 = [ListNode new];
    node4.data = @4;
    
    node1.next = node2;
    node2.next = node3;
    
    node4.next = node1;
    //现在有两个链表
    //1,2,3
    //4,1,2,3
    NSLog(@"两个链表是否相交");
    node = [LinklistQuestion pointOfIntersection:node4 other:node1];
    [LinklistQuestion printList:node];
    
    NSLog(@"两个链表相加");
    node = [LinklistQuestion addTwoNumbers:[ListNode creat:@[@2,@4,@3]] node2:[ListNode creat:@[@5,@6,@4]]];
     [LinklistQuestion printList:node];
    NSLog(@"合并K个排过序的链表");
    node = [LinklistQuestion mergeKSortedLists:@[[ListNode creat:@[@1,@2]],
                                                 [ListNode creat:@[@2,@2]],
                                                 [ListNode creat:@[@2,@3]]]];
     [LinklistQuestion printList:node];
    
}

- (void)array_alg{
   NSInteger median =  [Two_sorted_array_Median calculateMedianWithArr1:@[@1,@2,@3] arr2:@[@4,@5,@6]];
    NSLog(@"两个有序数的中位数:%zd",median);
    
    NSInteger findMin = [Find_Minimum_in_Rotated_Sorted_Array findMininumInRotatedArrayByBinarySearch:@[@4,@5,@1,@3]];
    NSLog(@"旋转数组找最小值:%zd",findMin);
    
    NSInteger findTarget = [Find_Minimum_in_Rotated_Sorted_Array findTargetInRotatedArrayByBinarySearch:@[@2,@3,@4,@5,@1] andTarget:@1];
     NSLog(@"旋转数组找target:%zd",findTarget);
    
    int yang[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    BOOL findYang = [Find_Num_in_Yang_Array findNum:15 inArray:yang];
    NSLog(@"在一个yang数组里面是否找到了特定数字:%i",findYang);
    
    NSArray *halfArray = @[@1,@2,@3,@2,@2,@2,@5,@4,@2];
    NSInteger halfValue = [Find_more_than_half_of_the_array_number findInArray:halfArray];
    NSLog(@"找到数组中超过一半的数字:%zd",halfValue);
    
    NSMutableArray *kthArr = @[@3,@2,@1,@5,@6,@4].mutableCopy;
    NSInteger kthNum =  [Kth_Largest_Element_in_an_Array findKthLargestInArray:kthArr kth:2];
    NSLog(@"Kth_Largest_Element_in_an_Array:%zd",kthNum);
    
    NSArray *reCountArr = @[@1,@2,@3,@4,@4,@4,@4,@6,@8,@9];
    NSInteger reCount = [Find_specific_num_count_in_Orderly_array findSpecificCountInOrderlyArray:reCountArr targetNum:4];
    
    NSLog(@"二分法计算有序数组中数字出现的次数:%zd",reCount);
    
    NSArray *twoSum = [Two_num twoSumInArray:@[@1,@3,@2,@2] andSum:4];
    NSLog(@"给定一个数组然后返回和为4的indices:%@",twoSum);
    NSArray *threeNum = [_3Num threeNumInArray:@[@-1, @0, @1, @2, @-1, @-4]];
    NSLog(@"三个数相加==0:%@",[threeNum description]);
    
    NSArray *group = [Group_Anagrams groupAnagrames:@[@"eat", @"tea", @"tan",@"ate", @"nat", @"bat"]];
    NSLog(@"group分组:%@",group);
    
    NSLog(@"word search:%i",[Word_Search isWordSearch:@"ABCCED"]);
}
- (void)dynamic_alg{
    [Maximum_Subarray max_subArray];
}

- (void)string_alg{
    [Longest_Palindromic_Substring isPalidromic:@"1abba"];
    [Longest_Palindromic_Substring isPalidromic:@"abcba"];
    NSString *palid = [Longest_Palindromic_Substring longestPalindrome:@"babcbada"];
    NSLog(@"最长回文:%@",palid);
    
   NSInteger withoutRep =  [Longest_Substring_Without_Repeating_Characters lengthOfLongestSubstringBySlowWindowWithStr:@"abcba"];
    NSLog(@"Longest_Substring_Without_Repeating_Characters:%zd",withoutRep);
    
    //字符串转成数字.
    
    NSLog(@"字符串转数字:%zd",[String_to_Integer tranformToNumberWithStr:@"12!30"]);
    
    NSLog(@"全排列:%@",[Full_Permutation permutation:@[@"a",@"b",@"c"] from:0 to:2]);
    
    BOOL isValid = [Valid_Parentheses validParentheses:@"([])[]{}"];
    NSLog(@"括号是否是有效的:%i",isValid);
    
    
    NSArray *gp = [Generate_Parentheses generateParenthses:3];
    NSLog(@"生成3对括号的结合:%@",gp);
    
    [Implement_strStr__ subRangeInString:@"abcde" subString:@"bc"];
    
    NSString *addb = [Add_Binary addBinary:@"11" b2:@"1"];
    NSLog(@"相加两个二进制数:%@",addb);
    
    NSInteger count_ = [Decode_Ways numDecodings:@"121"];
    NSLog(@"解密方式数量;%zd",count_);
    
    BOOL isVp = [Valid_Palindrome isValidPalindrome:@"A man, a plan, a canal: Panama"];
    NSLog(@"是否是有效的回文:%i",isVp);
    
    NSArray *vv = [Palindrome_Partitioning partition:@"aab"];
    NSLog(@"字符串里的substring也是回文的组合:%@",vv);
}

- (void)greedy{
    [GreedyALG greedy];
}
- (void)dynamicProgramming{
    [DynamicProgramming dynamicProgramming];
    [DynamicProgramming triangleMaxTotal];
}

- (void)Graph{
    Graph *graph = [Graph creat];
    [graph depthFirstSearch];
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
