
//
//  main.cpp
//  LeetCode
//
//  Created by junl on 2019/1/21.
//  Copyright © 2019 junl. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//https://leetcode-cn.com/problems/add-two-numbers/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = nullptr;
    ListNode *ct = head;
    int up = 0;
    int sum = 0;
    while (l1 && l2) {
        //将两数字相加
        sum = l1->val + l2->val + up;
        ListNode *node = new ListNode(sum % 10);
        up = sum / 10;
        if (!head) {
            head = node;
        }else{
            ct->next = node;
        }
        ct = node;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1) {
        l2 = l1;
    }
    if (l2) {
        sum = l2->val + up;
        up = sum/10;
        ListNode *node = new ListNode(sum%10);
        ct->next = node;
        ct = node;
    }
    if (up) {
        ListNode *node = new ListNode(up);
        ct->next = node;
    }
    return head;
};

ListNode *creattree(const vector<int> nos){
    ListNode *head = nullptr;
    ListNode *ct = head;
    for (int x : nos) {
        ListNode *node = new ListNode(x);
        if (!head) {
            head = node;
        }else{
            ct->next = node;
        }
        ct = node;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *node = creattree(vector<int>{1});
    ListNode *node2 = creattree(vector<int>{9,9});
    ListNode *result = addTwoNumbers(node, node2);
    return 0;
}
