//
//  main.cpp
//  LeetCode
//
//  Created by junl on 2019/1/21.
//  Copyright © 2019 junl. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <set>
#include <algorithm>
using namespace std;
//单链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){};
};
/*
 https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 
 Example 1:
 
 Input: 1->1->2
 Output: 1->2
 Example 2:
 
 Input: 1->1->2->3->3
 Output: 1->2->3
 */
ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;
    ListNode *pre,*ct;
    pre = head;
    ct = head->next;
    //pre保存的是上一个指针的值，如果相等的话，就删除ct这个节点，不相同的话跟新pre的值
    while (ct) {
        if (pre->val == ct->val) {
            pre->next = ct->next;
        }else{
            pre = ct;
        }
        ct = ct->next;
    }
    return head;
}
/*
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 
 Example 1:
 
 Input: 1->2->3->3->4->4->5
 Output: 1->2->5
 Example 2:
 
 Input: 1->1->1->2->3
 Output: 2->3

 
 利用两层循环，内部循环找到相邻的相同元素，然后跳过
 */
ListNode* deleteDuplicates2(ListNode* head) {
    if (!head) return head;
    ListNode *ct = new ListNode(0);
    ct->next = head;
    head = ct;
    ListNode *left,*right;
    while (ct->next) {
        left = ct->next;
        right = left;
        while (right->next && right->next->val == left->val) {
            right = right->next;
        }
        if (left == right) {
            ct = ct->next;
        }else{
            ct->next = right->next;
        }
    }
    return head->next;
}
ListNode *creatLinkList(const vector<int> vi){
    ListNode *head, *ct;
    head = ct = nullptr;
    for (auto val : vi) {
        ListNode *node = new ListNode(val);
        if (!head) {
            head = node;
        }else{
            ct->next = node;
        }
        ct = node;
    }
    return head;
};
int main(int argc, const char * argv[]) {
    ListNode *l1 = creatLinkList({1,1,1,2,3});
    l1 = deleteDuplicates2(l1);
    return 0;
}
