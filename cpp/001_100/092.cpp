//
//  092.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/8/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
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

void printL(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "(null)\n";
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        ListNode *pre = newhead, *p, *q;
        for (int i = 0; i < m-1; i++)
            pre = pre->next;
        p = pre->next;
        q = p->next;
        while (m++ < n) {
            ListNode *t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        pre->next->next = q;
        pre->next = p;
        return newhead->next;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 092 Reverse Linked List II, C++ ...\n\n";
    Solution sol;

    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(3);
    ListNode *a4 = new ListNode(4);
    ListNode *a5 = new ListNode(5);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    
    int m = 2, n = 4;
    
    ListNode *r = sol.reverseBetween(a1, m, n);
    printL(r);
    
    return 0;
}