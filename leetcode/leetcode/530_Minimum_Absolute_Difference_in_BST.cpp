//
//  530_Minimum_Absolute_Difference_in_BST.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/6/18.
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
        TreeNode *root = new TreeNode(nodes[0]);
        deque<TreeNode*> q {root};
        int i = 1;
        while (i < nodes.size()) {
            if (nodes[i] != -1) {
                TreeNode* left = new TreeNode(nodes[i]);
                q.front()->left = left;
                q.push_back(left);
            }
            i++;
            if (i < nodes.size() && nodes[i] != -1) {
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

    int getMinimumDifference0(TreeNode* root) {
        int r = INT_MAX;
        if (root->left) {
            TreeNode* p = root->left;
            while(p->right) {
                p = p->right;
            }
            int t = min(root->val - p->val, getMinimumDifference0(root->left));
            r = min(r, t);
        }
        if (root->right) {
            TreeNode* p = root->right;
            while(p->left) {
                p = p->left;
            }
            int t = min(p->val - root->val, getMinimumDifference0(root->right));
            r = min(r, t);
        }
        return r;
    }

    int getMinimumDifference(TreeNode* root) {
        int r = INT_MAX, prev = -1;
        inT(root, r, prev);
        return r;
    }
    void inT(TreeNode* root, int& diff, int& prev) {
        if (root->left) {
            inT(root->left, diff, prev);
        }
        if (prev != -1) {
            diff = min(diff, root->val - prev);
        }
        prev = root->val;
        if (root->right) {
            inT(root->right, diff, prev);
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 530. Minimum Absolute Difference in BST, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        1,-1,3,2
    };

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    int r0 = sol.getMinimumDifference0(root);
    cout << r0 << '\n';

    int r = sol.getMinimumDifference(root);
    cout << r << '\n';

    return 0;
}
