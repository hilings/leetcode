//
//  725_Split_Linked_List_in_Parts.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/20/20.
//  Copyright © 2020 Hilings Studio. All rights reserved.
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
    ListNode *buildL(vector<int> &nodes) {
        vector<ListNode *> v;
        for (auto a : nodes) {
            v.push_back(new ListNode(a));
        }
        for (size_t i = 0; i < v.size() - 1; i++) {
            v[i]->next = v[i + 1];
        }
        return v.front();
    }
    void printL(ListNode *head) {
        while (head) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "(null)\n";
    }

    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        ListNode *p = root;
        int l = 0;
        for (; p; p = p->next) {
            l++;
        }
        int l_shorter = l / k, count_longer = l % k;

        vector<ListNode *> r;
        p = root;
        for (int i = 0; i < k; i++) {
            r.push_back(p);

            if (!p) {
                continue;
            }

            int l = i < count_longer ? l_shorter + 1 : l_shorter;
            ListNode *tail = p;
            for (int j = 0; j < l - 1; j++) {
                tail = tail->next;
            }
            p = tail->next;
            tail->next = NULL;
        }

        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 725. Split Linked List in Parts, C++ ...\n\n";
    Solution sol;

    vector<int> nodes{
        // 1, 2, 3
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10

    };
    ListNode *root = sol.buildL(nodes);
    int k = 3;

    vector<ListNode *> r = sol.splitListToParts(root, k);
    for (auto p : r) {
        sol.printL(p);
    }
    cout << '\n';

    return 0;
}
