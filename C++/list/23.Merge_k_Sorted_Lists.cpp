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
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 
 Example:
 
 Input:
 [
 1->4->5,
 1->3->4,
 2->6
 ]
 Output: 1->1->2->3->4->4->5->6
 */

ListNode* mergeKLists( vector<ListNode*>& lists) {
    ListNode *head = nullptr ,*ct = nullptr;

    while (!lists.empty()) {
        //取最小值
        sort(lists.begin(), lists.end(),[](ListNode *l,ListNode *r){return l->val < r->val;});
        ListNode *node = new ListNode(lists[0]->val);
        if (!head) {
            head = node;
        }else{
            ct->next = node;
        }
        ct = node;
        //移除加入过的节点
        ListNode *deleteNode = lists[0];
        lists.erase(lists.begin());
        if (deleteNode->next) {
            lists.push_back(deleteNode->next);
        }
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
    vector<ListNode*> lists{l1,l2};
    ListNode * h = mergeKLists(lists);
    return 0;
}
