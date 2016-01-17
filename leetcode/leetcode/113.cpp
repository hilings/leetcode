//
//  113.cpp
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

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> v;
        solve(root, sum, v, vector<int> {0});
        return v;
    }
    void solve(TreeNode* root, int sum, vector<vector<int>>& v, vector<int> solution) {
        if (!root)
            return;
        solution.push_back(root->val);
        solution.front() += root->val;
        if (!root->left && !root->right && solution.front() == sum)
            v.push_back(vector<int> (solution.begin()+1, solution.end()));
        if (root->left)
            solve(root->left, sum, v, solution);
        if (root->right)
            solve(root->right, sum, v, solution);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 113 Path Sum II, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {5,4,8,11,0,13,4,7,2,0,0,5,1};
    TreeNode *root = sol.build(nodes);
    int sum = 22;

    vector<vector<int>> r = sol.pathSum(root, sum);
    for (auto v: r) {
        for (auto a: v) {
            cout << a << ' ';
        }
        cout << '\n';
    }

    return 0;
}