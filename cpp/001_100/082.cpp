//
//  082.cpp
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
        ListNode *newhead = new ListNode(0), *p = newhead;
        while (head) {
            int curval = head->val;
            cout << "checking " << curval << '\n';
            if (!head->next || (head->next && head->next->val != curval)) {
                p->next = head;
                p = p->next;
                head = head->next;
            } else {
                cout << "skipping " << curval << '\n';
                while (head && head->val == curval)
                    head = head->next;
            }
        }
        p->next = NULL;
        return newhead->next;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 082 Remove Duplicates from Sorted List II, C++ ...\n\n";
    Solution sol;

    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(2);
    ListNode *a4 = new ListNode(3);
    ListNode *a5 = new ListNode(4);
    ListNode *a6 = new ListNode(4);
    ListNode *a7 = new ListNode(5);
    a1->next = a2;
    a2->next = a3;
    /*
     a3->next = a4;
     a4->next = a5;
     a5->next = a6;
     a6->next = a7;
     */
    
    printL(a1);
    ListNode *r = sol.deleteDuplicates(a1);
    printL(r);
    
    return 0;
}