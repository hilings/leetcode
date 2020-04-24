//
//  098.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/12/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <limits>
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
    bool solve(TreeNode* root, long int min, long int max) {
        return !root || (root->val > min && root->val < max && solve(root->left, min, root->val) && solve(root->right, root->val, max));
    }
public:
    TreeNode* build(vector<int> nodes) {
        TreeNode *root = new TreeNode(nodes.front());
        deque<TreeNode*> q {root};
        nodes.erase(nodes.begin());
        building(q, nodes);
        return root;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, numeric_limits<long int>::min(), numeric_limits<long int>::max());
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 098 Validate Binary Search Tree, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {1};
    TreeNode *root = sol.build(nodes);
    
    bool r = sol.isValidBST(root);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}