//
//  061.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/16/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;

        ListNode *tail = head;
        int length = 1;
        while(tail->next) {
            length++;
            tail = tail->next;
        }
        tail->next = head;

        ListNode *newtail = head;
        k = length-1-k%length;
        for(int i = 0; i < k; i++) {
            newtail = newtail->next;
        }
        ListNode * newhead = newtail->next;
        newtail->next = NULL;

        return newhead;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 061 Rotate List, C++ ...\n\n";

    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(3);
    ListNode *a4 = new ListNode(4);
    ListNode *a5 = new ListNode(5);
    a1->next = a2;
    //a2->next = a3;
    //a3->next = a4;
    //a4->next = a5;
    
    int k = 0;
    
    Solution sol;
    ListNode *r = sol.rotateRight(a1, k);
    while(r) {
        cout << r->val << "->";
        r = r->next;
    }
    
    return 0;
}
