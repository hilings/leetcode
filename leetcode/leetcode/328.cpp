//
//  328.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/25/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
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
    ListNode *buildL(vector<int>& nodes) {
        vector<ListNode*> v;
        for (auto a: nodes) {
            v.push_back(new ListNode(a));
        }
        for (size_t i = 0; i < v.size()-1; i++) {
            v[i]->next = v[i+1];
        }
        return v.front();
    }
    void printL(ListNode* head) {
        while (head) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "(null)\n";
    }

    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *head2 = head->next, *cur = head2->next, *tail1 = head, *tail2 = head2;
        tail1->next = NULL;
        tail2->next = NULL;
        bool odd = true;
        while (cur) {
            //cout << cur->val << '\n';
            ListNode *tmp = cur->next;
            cur->next = NULL;
            if (odd) {
                tail1->next = cur;
                tail1 = cur;
            } else {
                tail2->next = cur;
                tail2 = cur;
            }
            cur = tmp;
            odd = !odd;
        }
        tail1->next = head2;
        return head;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 328. Odd Even Linked List, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {1,2,3,4,5};
    ListNode *head = sol.buildL(nodes);
    sol.printL(head);
    
    ListNode *r = sol.oddEvenList(head);
    sol.printL(r);
    
    return 0;
}