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
using namespace std;
//单链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){};
};
/*
 https://leetcode-cn.com/problems/merge-two-sorted-lists/
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 
 Example:
 
 Input: 1->2->4, 1->3->4
 Output: 1->1->2->3->4->4
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *head,*ct,*ct1,*ct2;
    ct1 = l1;
    ct2 = l2;
    head = ct = nullptr;
    while (ct1 && ct2) {
        ListNode *node;
        if (ct1->val < ct2->val) {
            node = new ListNode(ct1->val);
            ct1 = ct1->next;
        }else{
            node = new ListNode(ct2->val);
            ct2 = ct2->next;
        }
        if (!head) {
            head = node;
        }else{
            ct->next = node;
        }
        ct = node;
    }
    while (ct1) {
        ct->next = new ListNode(ct1->val);
        ct1 = ct1->next;
    }
    while (ct2) {
        ListNode *node = new ListNode(ct2->val);
        ct->next = node;
        ct = node;
        ct2 = ct2->next;
    }
    return head;
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
    ListNode *l1 = creatLinkList({1,2});
    ListNode *l2 = creatLinkList({1,3,4});
    ListNode *mergeL = mergeTwoLists(l1, l2);
    return 0;
}
