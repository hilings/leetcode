//
//  129.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/16/16.
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

void printV(vector<int> v) {
    for (auto a: v) {
        cout << a << ' ';
    }
    cout << '\n';
}

class Solution {
    void building(deque<TreeNode*>q, vector<int>& nodes) {
        // build tree from serialization
        if (nodes.empty())
            return;
        if (nodes.front() != 0) {
            TreeNode *left = new TreeNode(nodes.front());
            q.front()->left = left;
            q.push_back(left);
        }
        nodes.erase(nodes.begin());

        if (nodes.empty())
            return;
        if (nodes.front() != 0) {
            TreeNode *right = new TreeNode(nodes.front());
            q.front()->right = right;
            q.push_back(right);
        }
        nodes.erase(nodes.begin());

        q.pop_front();
        building(q, nodes);
    }
public:
    TreeNode* build(vector<int> nodes) {
    // build tree from serialization
        TreeNode *root = new TreeNode(nodes.front());
        deque<TreeNode*> q {root};
        nodes.erase(nodes.begin());
        building(q, nodes);
        return root;
    }

    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        deque<TreeNode*> q {root};
        int sum = 0;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop_front();
            cout << cur->val << '\n';

            if (!cur->left && !cur->right)
                sum += cur->val;
            if (cur->left) {
                cur->left->val += 10*cur->val;
                q.push_back(cur->left);
            }
            if (cur->right) {
                cur->right->val += 10*cur->val;
                q.push_back(cur->right);
            }
        }
        return sum;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 129 Sum Root to Leaf Numbers, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {1,2,3};
    TreeNode *root = sol.build(nodes);

    int r = sol.sumNumbers(root);
    cout << r << '\n';

    return 0;
}