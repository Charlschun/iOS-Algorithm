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
 https://leetcode-cn.com/problems/palindrome-linked-list/
 Given a singly linked list, determine if it is a palindrome.
 
 Example 1:
 
 Input: 1->2
 Output: false
 Example 2:
 
 Input: 1->2->2->1
 Output: true
 Follow up:
 Could you do it in O(n) time and O(1) space?
 
 思路：先找到中路节点，然后翻转后半部分链表，这样前后链表如果是一样的，就是回文
 */
bool isPalindrome(ListNode* head) {
    if (!head) return true;
    ListNode *fast,*slow;
    fast = slow = head;
    //找到中路节点
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    //翻转后半部分链表
    ListNode *pre,*ct,*next;
    pre = slow;
    ct = slow->next;
    pre->next = nullptr;
    while (ct) {
        next = ct->next;
        ct->next = pre;
        pre = ct;
        ct = next;
    }
    while (pre && head) {
        if (pre->val != head->val) {
            return false;
        }
        pre = pre->next;
        head = head->next;
    }
    return true;
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
    ListNode *l1 = creatLinkList({1,2,3,2,2,1});
    cout << isPalindrome(l1) << endl;
    return 0;
}
