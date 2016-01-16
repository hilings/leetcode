//
//  110.cpp
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
    int heightT(TreeNode* root) {
        return root ? 1 + max(heightT(root->left), heightT(root->right)) : 0;
    }
public:
    TreeNode* build(vector<int> nodes) {    // build tree from serialization
        TreeNode *root = new TreeNode(nodes.front());
        deque<TreeNode*> q {root};
        nodes.erase(nodes.begin());
        building(q, nodes);
        return root;
    }
    bool isBalanced(TreeNode* root) {
        return !root || ((abs(heightT(root->left) - heightT(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right));
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 110 Balanced Binary Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {1,2,3,4,5,6,7};
    TreeNode *root = sol.build(nodes);

    bool r = sol.isBalanced(root);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}