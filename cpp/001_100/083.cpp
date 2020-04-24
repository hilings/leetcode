//
//  083.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/6/16.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while (p)
            (p->next && p->next->val == p->val) ? p->next = p->next->next : p = p->next;
        return head;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 083 Remove Duplicates from Sorted List, C++ ...\n\n";
    Solution sol;

    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(1);
    ListNode *a3 = new ListNode(2);
    ListNode *a4 = new ListNode(3);
    ListNode *a5 = new ListNode(3);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    printL(a1);
    
    ListNode *r = sol.deleteDuplicates(a1);
    printL(r);
    
    return 0;
}