//
//  147.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/29/16.
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
        if (nodes.empty())
            return NULL;
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

    ListNode* insertionSortList(ListNode* head) {
        ListNode *newhead = new ListNode(0), *cur = head, *p = newhead;
        while (cur) {
            ListNode* tmp = cur->next;
            if (p->next && cur->val < p->next->val)
                p = newhead;
            while(p->next && cur->val >= p->next->val)
                p = p->next;
            cur->next = p->next;
            p->next = cur;
            cur = tmp;
        }
        return newhead->next;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 147. Insertion Sort List, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {1,3,5,4,2};
    ListNode *head = sol.buildL(nodes);
    
    sol.printL(head);
    
    ListNode * r = sol.insertionSortList(head);
    sol.printL(r);
    
    return 0;
}