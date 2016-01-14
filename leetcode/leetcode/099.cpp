//
//  099.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/12/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

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
    void building(deque<TreeNode*> q, vector<int> nodes) {
        if (nodes.empty())
            return;
        if (nodes.front() != 0) {
            TreeNode* left = new TreeNode(nodes.front());
            q.front()->left = left;
            q.push_back(left);
        }
        nodes.erase(nodes.begin());

        if (nodes.empty())
            return;
        if (nodes.front() != 0) {
            TreeNode* right = new TreeNode(nodes.front());
            q.front()->right = right;
            q.push_back(right);
        }
        nodes.erase(nodes.begin());

        q.pop_front();
        building(q, nodes);
    }

    void solve(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {	// iterative
        if (!root)
            return;
        solve(root->left, prev, first, second);
        if (prev && prev->val >= root->val) {
            if (!first)
                first = prev;
            second = root;
        }
        prev = root;
        solve(root->right, prev, first, second);
    }
public:
    void recoverTree(TreeNode* root) {	// iterative
        TreeNode *first = NULL, *second = NULL, *prev = NULL;
        solve(root, prev, first, second);
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }

    void recoverTree2(TreeNode* root) {	//Morris-traversal
        TreeNode* cur = root, *last = NULL, *first = NULL, *second = NULL;
        while (cur) {
            if (last && last->val >= cur->val) {
                if (!first)
                    first = last;
                second = cur;
            }
            if (!cur->left) {
                last = cur;
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur)
                    prev = prev->right;
                if (!prev->right) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = NULL;
                    last = cur;
                    cur = cur->right;
                }
            }
        }
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }

    TreeNode* build(vector<int> nodes) {
        TreeNode* root = new TreeNode(nodes.front());
        deque<TreeNode*> q {root};
        nodes.erase(nodes.begin());
        building(q, nodes);
        return root;
    }

    void printT(TreeNode* root) {
        deque<TreeNode*> q {root};
        vector<int> v;
        while (!q.empty()) {
            if (q.front()) {
                v.push_back(q.front()->val);
                q.push_back(q.front()->left);
                q.push_back(q.front()->right);
            }
            else
                v.push_back(0);
            q.pop_front();
        }
        while (v.back() == 0)
            v.pop_back();
        for (auto a: v)
            cout << a << ' ';
        cout << '\n';
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 099 Recover Binary Search Tree, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {1,2,3};
    TreeNode* root = sol.build(nodes);
    
    sol.printT(root);
    sol.recoverTree2(root);
    sol.printT(root);
    
    return 0;
}