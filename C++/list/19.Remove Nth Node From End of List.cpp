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
 https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 Given a linked list, remove the n-th node from the end of list and return its head.
 
 Example:
 
 Given linked list: 1->2->3->4->5, and n = 2.
 
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 
 Given n will always be valid.
 */


ListNode* removeNthFromEnd(ListNode* head, int n) {
    int i = 0;
    ListNode *fast,*slow;
    fast = slow = head;
    //先找到val=3这个点
    while (i++ < n && fast->next) {
        fast = fast->next;
    }
    while (fast && fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    //说明n=链表的长度，我们需要删除的是头结点
    if (slow == head) {
        return head->next;
    }
    if (slow->next) {
        slow->next = slow->next->next;
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
    ListNode *head = creatLinkList({1,2});
    ListNode *n_head = removeNthFromEnd(head, 1 );
    return 0;
}
