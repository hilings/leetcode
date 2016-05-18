//
//  237.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/14/16.
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

    void deleteNode(ListNode* node) {
        if (node) {
            node->val = node->next->val;
            node->next = node->next->next;
        } else {
            node = NULL;
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 237. Delete Node in a Linked List, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {1,2,3,4};
    ListNode *head = sol.buildL(nodes);
    sol.printL(head);

    ListNode *node = head->next->next;
    sol.deleteNode(node);

    sol.printL(head);

    return 0;
}