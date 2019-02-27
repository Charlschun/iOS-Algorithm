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
#include <array>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
 https://leetcode-cn.com/problems/sort-list/
 Sort a linked list in O(n log n) time using constant space complexity.
 
 Example 1:
 
 Input: 4->2->1->3
 Output: 1->2->3->4
 Example 2:
 
 Input: -1->5->3->4->0
 Output: -1->0->3->4->5
 */
ListNode* sortList(ListNode* head) {
    ListNode *ct = head;
    //插入排序
    while (ct->next) {
        ListNode *next =ct->next;
        //如果next比ct小，则需要把next插入到之前已经排好序的数组里面
        if (next->val < ct->val) {
            ListNode *ct1=head;
            //如果next的值比head还小的话，插入到头部
            if (ct1->val > next->val) {
                ct->next=next->next;
                next->next=head;
                head=next;
            }else{
                //找到第一个比next大的
                while (ct1->next->val<next->val) {
                    ct1=ct1->next;
                }
                ct->next=next->next;
                ListNode *next1=ct1->next;
                ct1->next=next;
                next->next=next1;
            }
        }
        ct=next;
    }
    return head;
}
int main(int argc, const char * argv[]) {
    ListNode *head= new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head = sortList(head);
    return 0;
}

