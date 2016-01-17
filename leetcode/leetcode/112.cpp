//
//  112.cpp
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
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        if (root->left)
            root->left->val += root->val;
        if (root->right)
            root->right->val += root->val;
        return (!root->left && !root->right && root->val == sum) || hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 112 Path Sum, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {5,4,8,11,0,13,4,7,2,0,0,0,1};
    TreeNode *root = sol.build(nodes);

    int sum = 22;

    bool r = sol.hasPathSum(root, sum);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}