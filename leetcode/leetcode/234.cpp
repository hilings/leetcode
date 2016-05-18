//
//  234.cpp
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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head)
            return true;
        ListNode* p = head;
        int n = 0;
        while (p) {
            n++;
            p = p->next;
        }
        //cout << n << '\n';

        p = head;
        for (int i = 0; i < n - n/2; i++) {
            p = p->next;
        }
        //cout << p->val;

        ListNode* halfHead = reverseList(p);
        for (int i = 0; i < n/2; i++) {
            if (head->val != halfHead->val)
                return false;
            head = head->next;
            halfHead = halfHead->next;
        }
        return true;
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 234. Palindrome Linked List, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {1,1,2,1};
    ListNode *head = sol.buildL(nodes);
    
    sol.printL(head);
    
    bool r = sol.isPalindrome(head);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}