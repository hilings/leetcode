//
//  list.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/15/16.
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
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *p = head;
        while (p) {
            ListNode *t = p->next;
            p->next = prev;
            prev = p;
            p = t;
        }
        return prev;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode XXX List, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {1,2,3,4,5,6,7};
    ListNode *head = sol.buildL(nodes);
    sol.printL(head);

    ListNode *r = sol.reverse(head);    //reverse
    sol.printL(r);

    return 0;
}