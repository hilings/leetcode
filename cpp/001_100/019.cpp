//
//  019.cpp
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *q = head;
        for (int i = 0; i < n; i++)
            q = q->next;
        if (!q)
            return head->next;
        
        ListNode *p = head;
        while(q->next) {
            q = q->next;
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};

void printList(ListNode *head) {
    while(head->next) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << '\n';
}

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 019 Remove Nth Node From End of List, C++ ... ...\n";

    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(3);
    ListNode *a4 = new ListNode(4);
    ListNode *a5 = new ListNode(5);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    
    printList(a1);
    
    int n = 5;
    
    Solution sol;
    printList(sol.removeNthFromEnd(a1, n));
    
    return 0;
}