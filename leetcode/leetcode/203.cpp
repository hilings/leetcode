//
//  203.cpp
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

    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newhead = new ListNode(0), *p = newhead;
        newhead->next = head;
        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        p = newhead->next;
        delete newhead;
        return p;
    }
};



int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 203. Remove Linked List Elements, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {1,2,6,3,4,5,6};
    int val = 6;
    ListNode *head = sol.buildL(nodes);
    
    sol.printL(head);
    
    ListNode *ret = sol.removeElements(head, val);
    sol.printL(ret);
    
    return 0;
}