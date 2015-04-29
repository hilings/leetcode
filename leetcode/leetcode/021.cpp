//
//  021.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/28/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        ListNode *head;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        
        ListNode *p = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1)
            p->next = l1;
        else
            p->next = l2;
        return head;
    }
};

void printList(ListNode *head) {
    if (!head)
        return;
    while (head->next) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << '\n';
}

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 021 Merge Two Sorted Lists, C++ ... ...\n";
    
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(3);
    ListNode *a3 = new ListNode(5);
    ListNode *b1 = new ListNode(2);
    ListNode *b2 = new ListNode(4);
    ListNode *b3 = new ListNode(6);

    a1->next = a2;
    //a2->next = a3;
    b1->next = b2;
    b2->next = b3;
    printList(a1);
    printList(b1);
    
    Solution sol;
    printList(sol.mergeTwoLists(a1, b1));
    
    return 0;
}
