//
//  100.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/13/16.
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
public:
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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return (!p && !q) || (p && q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 100 Same Tree, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {1,2,3};
    TreeNode* root = sol.build(nodes);
    
    vector<int> nodes2 {1,2,3};
    TreeNode* root2 = sol.build(nodes2);
    
    bool r = sol.isSameTree(root, root2);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}