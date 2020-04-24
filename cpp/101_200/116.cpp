//
//  116.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/18/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    void building(deque<TreeLinkNode*>q, vector<int>& nodes) {
        // build tree from serialization
        if (nodes.empty())
            return;
        if (nodes.front() != 0) {
            TreeLinkNode *left = new TreeLinkNode(nodes.front());
            q.front()->left = left;
            q.push_back(left);
        }
        nodes.erase(nodes.begin());

        if (nodes.empty())
            return;
        if (nodes.front() != 0) {
            TreeLinkNode *right = new TreeLinkNode(nodes.front());
            q.front()->right = right;
            q.push_back(right);
        }
        nodes.erase(nodes.begin());

        q.pop_front();
        building(q, nodes);
    }
public:
    TreeLinkNode* build(vector<int> nodes) {
        // build tree from serialization
        TreeLinkNode *root = new TreeLinkNode(nodes.front());
        deque<TreeLinkNode*> q {root};
        nodes.erase(nodes.begin());
        building(q, nodes);
        return root;
    }

    void printT(TreeLinkNode *root) {
        // print serialized tree
        deque<TreeLinkNode*> q;
        q.push_back(root);
        vector<int> v;
        while (!q.empty()) {
            TreeLinkNode *p = q.front();
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

    void connect(TreeLinkNode *root) {
        if (!root || !root->left)
            return;
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 116 Populating Next Right Pointers in Each Node, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {1,2,3,4,5,6,7};
    TreeLinkNode *root = sol.build(nodes);

    sol.printT(root);
    sol.connect(root);
    
    cout << root->left->right->next->next->val;
    
    return 0;
}