//
//  024.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/30/15.
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

void printList(ListNode *h) {
    while (h) {
        cout << h->val << " -> ";
        h = h->next;
    }
    cout << "(null)\n";
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        printList(head);
        
        ListNode *h = new ListNode(0);
        ListNode *p = h;
        while (head && head->next) {
            ListNode *q = head->next;
            p->next = q;
            head->next = q->next;
            q->next = head;
            
            p = head;
            head = head->next;
        }
        p->next = head;
        printList(h->next);
        return h->next;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 024 Swap Nodes in Pairs, C++ ...\n\n";
    
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(3);
    ListNode *a4 = new ListNode(4);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    
    Solution sol;
    sol.swapPairs(a1);
    
    return 0;
}