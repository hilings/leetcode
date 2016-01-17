//
//  111.cpp
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

    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        if (root->left && root->right)
            return 1 + min(minDepth(root->left), minDepth(root->right));
        return root->left ? 1 + minDepth(root->left) : 1 + minDepth(root->right);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 111 Minimum Depth of Binary Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {1,2};
    TreeNode *root = sol.build(nodes);
    
    int r = sol.minDepth(root);
    cout << r << '\n';
    
    return 0;
}