//
//  206.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/31/16.
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

    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *cur = head;
        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 206. Reverse Linked List, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {1,2,3,4,5,6,7};
    ListNode *head = sol.buildL(nodes);
    
    sol.printL(head);
    
    ListNode *r = sol.reverseList(head);
    sol.printL(r);
    
    return 0;
}