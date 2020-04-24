//
//  437_path_sum_III.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/13/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
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
public:
    TreeNode* build(vector<int> nodes) {
        // build tree from serialization
        TreeNode *root = new TreeNode(nodes[0]);
        deque<TreeNode*> q {root};
        int i = 1;
        while (i < nodes.size()) {
            if (nodes[i] != -111) {
                TreeNode* left = new TreeNode(nodes[i]);
                q.front()->left = left;
                q.push_back(left);
            }
            i++;
            if (i < nodes.size() && nodes[i] != -111) {
                TreeNode* right = new TreeNode(nodes[i]);
                q.front()->right = right;
                q.push_back(right);
            }
            i++;
            q.pop_front();
        }
        return root;
    }

    void printT(TreeNode *root) {
        // print serialized tree
        deque<TreeNode*> q;
        q.push_back(root);
        vector<int> v;
        while (!q.empty()) {
            TreeNode *p = q.front();
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

    int pathSum(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int helper(TreeNode* root, int sum) {   // path starts from this node
        if (!root) {
            return 0;
        }
        return (root->val == sum ? 1 : 0)
            + helper(root->left, sum - root->val) + helper(root->right, sum - root->val);
    }

    int pathSum2(TreeNode* root, int sum) {
        unordered_map<int,int> m;
        m[0] = 1;
        return helper2(root, 0, sum, m);
    }
    int helper2(TreeNode* root, int sumsofar, int sum, unordered_map<int,int>& m) {
        if (!root) {
            return 0;
        }
        sumsofar += root->val;  // sum from root through current node
        int count = m.find(sumsofar - sum) == m.end() ? 0 : m[sumsofar - sum];  // valid path(s) exist or not
        m[sumsofar] = m.find(sumsofar) == m.end() ? 1 : m[sumsofar] + 1;    // update map of paths so far
        count += helper2(root->left, sumsofar, sum, m) + helper2(root->right, sumsofar, sum, m);    // check paths from now on
        m[sumsofar]--;  // restore on way back up, since it is DFS
        return count;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 437. Path Sum III, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {10,5,-3,3,2,-111,11,3,-2,-111,1};
    int sum = 8;

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    int r = sol.pathSum(root, sum);
    cout << r << '\n';

    int r2 = sol.pathSum2(root, sum);
    cout << r2 << '\n';

    return 0;
}
