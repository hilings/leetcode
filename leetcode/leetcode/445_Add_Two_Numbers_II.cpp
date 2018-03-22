//
//  445_Add_Two_Numbers_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/19/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = 0;
        stack<int> stk1, stk2;
        while (l1) {
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stk2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        while (!stk1.empty() || !stk2.empty() || carry == 1) {
            int a = stk1.empty() ? 0 : stk1.top(), b = stk2.empty() ? 0 : stk2.top(), val = a+b+carry;
            if (!stk1.empty()) {
                stk1.pop();
            }
            if (!stk2.empty()) {
                stk2.pop();
            }
            ListNode* cur = new ListNode(val%10);
            carry = val / 10;
            cur->next = head;
            head = cur;
        }
        return head;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "445. Add Two Numbers II, C++ ...\n\n";
    Solution sol;

    vector<int> nodes1 {7,2,4};
    vector<int> nodes2 {5,6,4};
    ListNode* l1 = sol.buildL(nodes1);
    ListNode* l2 = sol.buildL(nodes2);

    ListNode* r = sol.addTwoNumbers(l1, l2);
    sol.printL(r);

    return 0;
}
