//
//  160.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/7/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while (p != q) {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 160. Intersection of Two Linked Lists, C++ ...\n\n";
    Solution sol;

    vector<int> nodesA {1,2,3,4,5};
    vector<int> nodesB {11,22};
    ListNode *headA = sol.buildL(nodesA);
    ListNode *headB = sol.buildL(nodesB);
    headB->next->next = headA->next->next;
    sol.printL(headA);
    sol.printL(headB);
    
    ListNode *r = sol.getIntersectionNode(headA, headB);
    cout << r->val << '\n';
    
    return 0;
}