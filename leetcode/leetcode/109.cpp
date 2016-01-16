//
//  109.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/15/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode *root;
        int l = 0;
        for (ListNode *p = head; p; l++,p=p->next) ;
        if (l == 0)
            root = NULL;
        else if (l == 1)
            root = new TreeNode(head->val);
        else if (l == 2) {
            root = new TreeNode(head->next->val);
            head->next = NULL;
            root->left = sortedListToBST(head);
        } else {
            ListNode *p = head;
            for (size_t i = 0; i < l/2-1; i++)
                p = p->next;
            root = new TreeNode(p->next->val);
            root->right = sortedListToBST(p->next->next);
            p->next = NULL;
            root->left = sortedListToBST(head);
        }
        return root;
    }

    void printT(TreeNode *root) {   // print serialized tree
        deque<TreeNode*> q;
        q.push_back(root);
        vector<int> v;
        while (!q.empty()) {
            TreeNode *p = q.front();
            if (p) {
                v.push_back(p->val);
                q.push_back(p->left);
                q.push_back(p->right);
            } else
                v.push_back(0);
            q.pop_front();
        }
        while (v.back() == 0)
            v.pop_back();
        for (auto a: v) {
            if (a != 0)
                cout << a;
            else
                cout << '#';
            cout << ' ';
        }
        cout << '\n';
    }

    ListNode *buildL(vector<int>& nodes) {
        vector<ListNode*> v;
        for (auto a: nodes)
            v.push_back(new ListNode(a));
        for (size_t i = 0; i < v.size()-1; i++)
            v[i]->next = v[i+1];
        return v.front();
    }
    void printL(ListNode* head) {
        while (head) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "(null)\n";
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 109 Convert Sorted List to Binary Search Tree, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {1,2,3,4,5,6,7};
    ListNode *head = sol.buildL(nodes);
    sol.printL(head);
    
    TreeNode *root = sol.sortedListToBST(head);
    sol.printT(root);
    
    return 0;
}