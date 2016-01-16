//
//  101.cpp
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

    bool solve(TreeNode* left, TreeNode* right) {	//recursive
        return (!left && !right) || (left && right && left->val == right->val && solve(left->left, right->right) && solve(left->right, right->left));
    }
public:
    TreeNode* build(vector<int> nodes) {    // build tree from serialization
        TreeNode *root = new TreeNode(nodes.front());
        deque<TreeNode*> q {root};
        nodes.erase(nodes.begin());
        building(q, nodes);
        return root;
    }

    bool isSymmetric(TreeNode* root) {	// iterative
        if (!root)
            return true;
        deque<TreeNode*> q {root->left, root->right};
        while (!q.empty()) {
            TreeNode *left = q.front();
            q.pop_front();
            TreeNode *right = q.back();
            q.pop_back();
            if (left && right && left->val == right->val) {
                q.push_front(left->right);
                q.push_front(left->left);
                q.push_back(right->left);
                q.push_back(right->right);
            } else if (left == NULL && right == NULL)
                continue;
            else
                return false;
        }
        return true;
    }

    bool isSymmetric2(TreeNode* root) {	//recursive
        return !root || solve(root->left, root->right);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 101 Symmetric Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {1,2,2,3,4,4,3};
    TreeNode *root = sol.build(nodes);

    bool r = sol.isSymmetric2(root);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}