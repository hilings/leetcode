//
//  141.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/27/16.
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
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        ListNode *p = head, *q = p->next;
        while (q && q != p) {
            p = p->next;
            q = q->next;
            if (q)
                q = q->next;
        }
        return p == q;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 141. Linked List Cycle, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {1};
    ListNode *head = sol.buildL(nodes);
    
    sol.printL(head);
    bool r = sol.hasCycle(head);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}