//
//  086.cpp
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

void printL(ListNode *head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "(null)\n";
}

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *newhead1 = new ListNode(0), *newhead2 = new ListNode(0), *p = newhead1, *q = newhead2;
        while (head) {
            if (head->val < x) {
                p->next = head;
                p = p->next;
                head = head->next;
                p->next = NULL;
            } else {
                q->next = head;
                q = q->next;
                head = head->next;
                q->next = NULL;
            }
        }
        p->next = newhead2->next;
        return newhead1->next;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 086 Partition List, C++ ...\n\n";
    Solution sol;

    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(4);
    ListNode *a3 = new ListNode(3);
    ListNode *a4 = new ListNode(2);
    ListNode *a5 = new ListNode(5);
    ListNode *a6 = new ListNode(2);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = a6;
    printL(a1);
    
    int x = 3;
    
    ListNode *r = sol.partition(a1, x);
    printL(r);
    
    return 0;
}