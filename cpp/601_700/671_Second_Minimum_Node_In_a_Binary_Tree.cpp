//
//  671_Second_Minimum_Node_In_a_Binary_Tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/28/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
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
public:
    TreeNode* build(vector<int> nodes) {
        // build tree from serialization
        if (nodes.empty()) {
            return NULL;
        }
        TreeNode *root = new TreeNode(nodes[0]);
        deque<TreeNode*> q {root};
        int i = 1, NaN = -1;   // flag of NULL
        while (i < nodes.size()) {
            if (nodes[i] != NaN) {
                TreeNode* left = new TreeNode(nodes[i]);
                q.front()->left = left;
                q.push_back(left);
            }
            i++;
            if (i < nodes.size() && nodes[i] != NaN) {
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
        if (!root) {
            cout << "#\n";
            return;
        }
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
                v.push_back(INT_MIN);
            q.pop_front();
        }
        while (v.back() == INT_MIN)
            v.pop_back();
        for (auto a: v) {
            if (a != INT_MIN)
                cout << a;
            else
                cout << '#';
            cout << ' ';
        }
        cout << '\n';
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root) {
            return -1;
        }
        int min2 = INT_MAX;
        dfs(root, root->val, min2);
        return min2 == INT_MAX ? -1 : min2;
    }
    void dfs(TreeNode* root, int min1, int& min2) {
        if (!root || root->val >= min2) {
            return;
        }
        if (root->val == min1) {
            dfs(root->left, min1, min2);
            dfs(root->right, min1, min2);
        } else if (root->val < min2) {
            min2 = root->val;
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 671. Second Minimum Node In a Binary Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        2,2,5,-1,-1,5,7 // 5
        //2,2,2   // -1
    };

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    int r = sol.findSecondMinimumValue(root);
    cout << r << '\n';

    return 0;
}
