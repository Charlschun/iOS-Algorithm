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
struct SLNode {
    int val;
    SLNode *next;
    SLNode(int x):val(x),next(nullptr){};
};

struct LinkedList {
    size_t size = 0;
    SLNode *head;
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size) return -1;
        if(index == 0) return head->val;
        int ct = 0;
        SLNode *node = head;
        while(ct++ < index){
            node = node->next;
        };
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        SLNode *node = new SLNode(val);
        if(!head){
            head = node;
        }else{
            node->next = head;
            head = node;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(size == 0) return;
        SLNode *ct = head;
        while(ct->next){
            ct = ct->next;
        };
        SLNode *node = new SLNode(val);
        ct->next = node;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index >= size) return;
        if (index == 0) addAtHead(val);
        //add
        int ct = 0;
        SLNode *node = head;
        while(ct++ < index-1){
            node = node->next;
        };
        SLNode *after = node->next;
        SLNode *n = new SLNode(val);
        node->next = n;
        n->next = after;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size) return;
        if(index == 0){
            head = head->next;
        }else{
            int ct = 0;
            SLNode *node = head;
            while(ct++ < index-1){
                node = node->next;
            };
            node->next = node->next->next;
        }
    }
    
    void print(){
        SLNode *ct = head;
        while(ct){
            cout << ct->val << " ";
            ct = ct->next;
        }
        cout << endl;
    }
};

namespace DoublePointer {
    class Solution {
    public:
        SLNode *creatLinkList(const vector<int> vi){
            SLNode *head, *ct;
            head = ct = nullptr;
            for (auto val : vi) {
                SLNode *node = new SLNode(val);
                if (!head) {
                    head = node;
                }else{
                    ct->next = node;
                }
                ct = node;
            }
            return head;
        };
        //是否有环
        bool hasCycle(SLNode *head){
            SLNode *fast,*slow;
            fast = slow = head;
            
            while (fast) {
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow) {
                    return true;
                }
            }
            return false;
        }
        //环的长度
        /*
         环的长度 ,比如现在A,B在赛跑,A的速度是B的两倍，当A跑玩2圈的时候，B刚好跑完1圈。此时B跑的长度即相当于环的长度。
         2*v*t - v*t = 环的长度
         */
        int ringLength(SLNode *head){
            SLNode *fast,*slow;
            if (!hasCycle(head)) {
                return 0;
            }
            fast = slow = head;
            int length = 0;
            while (fast) {
                fast = fast->next->next;
                slow = slow->next;
                length++;
                if (fast == slow) {
                    break;
                }
            }
            return length;
        }
        /*
         判断两个链表是否相交
         方法一:先计算出两个链表的长度,l1,l2,然后长的先走l2-l1步.在同时开始走
         方法二:判断最后一个节点是否相等
         */
        SLNode *getIntersectionNode(SLNode *headA, SLNode *headB) {
            //先计算出两个链表的长度,l1,l2,然后长的先走l2-l1步.在同时开始走
            int l1 = 0,l2 = 0;
            SLNode *ct = headA;
            SLNode *ct2 = headB;
            while (ct) {
                l1++;
                ct = ct->next;
            }
            while (ct2) {
                l2++;
                ct2 = ct2->next;
            }
            ct = headA;
            ct2 = headB;
            
            int i = 0;
            while (l1 > l2 && i < l1 - l2) {
                i++;
                ct = ct->next;
            }
            i = 0;
            while (l2 > l1 && i < l2 - l1) {
                i++;
                ct2 = ct2->next;
            }
            i = 0;
            while (ct2 && ct) {
                if (ct == ct2) {
                    //find
                    return ct;
                }
                ct2 = ct2 -> next;
                ct = ct -> next;
            }
            return nullptr;
        }
        bool isIntersection(SLNode *headA, SLNode *headB) {
            //先计算出两个链表的长度,l1,l2,然后长的先走l2-l1步.在同时开始走
            SLNode *ct = headA;
            SLNode *ct2 = headB;
            while (ct2->next) {
                ct2 = ct2 -> next;
            }
            while (ct->next) {
                ct = ct->next;
            }
            if (ct2 == ct) {
                return true;
            }
            return false;
        }
        SLNode* removeNthFromEnd(SLNode* head, int n) {
            int ct = 1;
            SLNode *fast, *slow;
            fast=slow=head;
            while (ct++ < n+1) {
                fast = fast->next;
            }
            while (fast && fast->next) {
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = slow->next->next;
            return head;
        }
    };
}

int main(int argc, const char * argv[]) {
    
    //1->2->3->4->5->1
    SLNode *head = new SLNode(3);
    SLNode *node1 = new SLNode(2);
    SLNode *node2 = new SLNode(0);
    SLNode *node3 = new SLNode(-4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    
    DoublePointer::Solution sl;
    cout << sl.hasCycle(head) << endl;
    
    //两个链表是否相交
    SLNode *inter1 = sl.creatLinkList({4});
    SLNode *inter2 = sl.creatLinkList({5,0,1});
    SLNode *inter3 = sl.creatLinkList({8,4,5});
    inter1->next = inter3;
    inter2->next = inter3;
    cout << "是否相交: " << sl.isIntersection(inter1, inter2) << " " <<  sl.getIntersectionNode(inter1, inter2) << endl;
    
    cout << "删除倒数N个节点: " << sl.removeNthFromEnd(inter1, 2);//4,8,4,5
    return 0;
}
