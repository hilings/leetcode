//
//  138.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/25/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *buildL(vector<int>& nodes) {
        vector<RandomListNode*> v;
        for (auto a: nodes) {
            v.push_back(new RandomListNode(a));
        }
        for (size_t i = 0; i < v.size()-1; i++) {
            v[i]->next = v[i+1];
        }
        return v.front();
    }
    void printL(RandomListNode* head) {
        while (head) {
            cout << head->label << " -> ";
            head = head->next;
        }
        cout << "(null)\n";
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*,RandomListNode*> um;
        RandomListNode* p = head;
        while (p) {
            um[p] = new RandomListNode(p->label);
            p = p->next;
        }
        p = head;
        while (p) {
            um[p]->next = um[p->next];
            if (p->random)
                um[p]->random = um[p->random];
            p = p->next;
        }
        return um[head];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 138. Copy List with Random Pointer, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {1,2,3,4,5};
    RandomListNode* head = sol.buildL(nodes);
    RandomListNode* p = head;
    p->random = p->next->next;
    p->next->random = p->next->next->next;
    p->next->next->random = p->next->next->next->next;
    cout << p->random->random->label << '\n';

    RandomListNode* r = sol.copyRandomList(head);

    sol.printL(r);
    cout << r->random->random->label << '\n';

    return 0;
}