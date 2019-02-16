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
 https://leetcode-cn.com/problems/rotate-list/
 Given a linked list, rotate the list to the right by k places, where k is non-negative.
 
 Example 1:
 
 Input: 1->2->3->4->5->NULL, k = 2
 Output: 4->5->1->2->3->NULL
 Explanation:
 rotate 1 steps to the right: 5->1->2->3->4->NULL
 rotate 2 steps to the right: 4->5->1->2->3->NULL
 Example 2:
 
 Input: 0->1->2->NULL, k = 4
 Output: 2->0->1->NULL
 Explanation:
 rotate 1 steps to the right: 2->0->1->NULL
 rotate 2 steps to the right: 1->2->0->NULL
 rotate 3 steps to the right: 0->1->2->NULL
 rotate 4 steps to the right: 2->0->1->NULL
 */
ListNode* rotateRight(ListNode* head, int k) {
    //先计算链表长度
    int count = 0;
    ListNode *ct = head;
    while (ct) {
        count++;
        ct = ct->next;
    }
    k = k % count;
    
    //然后我们利用双指针法来定位到倒数第k个元素
    ListNode *fast,*slow;
    fast = slow = head;
    int i = 0;
    while (i++ < k) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    //找到后半部分的数据
    fast = head;
    while (fast->next != slow) {
        fast = fast->next;
    }
    //slow就是我们要找的链表的前半部分
    ListNode *newHead;
    newHead = slow;
    while (slow->next) {
        slow = slow->next;
    }
    fast->next = nullptr;
    slow->next = head;
    return newHead;
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
    ListNode *l1 = creatLinkList({1,2,3,4,5});
    l1 = rotateRight(l1,2);
    return 0;
}
