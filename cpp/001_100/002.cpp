//
//  002.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/6/15.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *prev = 0;
        int carry = 0;
        while (l1 || l2) {
            ListNode *cur;
            if (prev) {
                cur = new ListNode(0);
            } else {
                cur = head;
            }
            int sum = carry;
            if (l1) {
                sum += l1->val;
            }
            if (l2) {
                sum += l2->val;
            }
            cur->val = sum % 10;
            carry = sum / 10;
            
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
            if (prev) {
                prev->next = cur;
            }
            prev = cur;
        }
        if (carry > 0) {
            prev->next = new ListNode(1);
        }
        return head;
    }
};

void printList(ListNode *l) {
    while (l->next) {
        cout << l->val << "->";
        l = l->next;
    }
    cout << l->val << '\n';
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "LeetCode 002 Add Two Numbers, C++ ... ...\n";
    
    ListNode *a1 = new ListNode(2);
    ListNode *a2 = new ListNode(4);
    ListNode *a3 = new ListNode(3);
    ListNode *a4 = new ListNode(3);
    
    ListNode *b1 = new ListNode(8);
    ListNode *b2 = new ListNode(6);
    ListNode *b3 = new ListNode(4);
    
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    b1->next = b2;
    b2->next = b3;
    
    printList(a1);
    printList(b1);

    Solution sol;
    printList(sol.addTwoNumbers(a1, b1));
    
    return 0;
}