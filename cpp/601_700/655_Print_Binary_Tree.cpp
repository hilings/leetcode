//
//  655_Print_Binary_Tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/26/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
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

    vector<vector<string>> printTree(TreeNode* root) {
        int m = getH(root), n = (int)pow(2, m) - 1;
        vector<vector<string>> r (m, vector<string> (n, ""));
        helper(r, root, 0, 0, n-1);
        return r;
    }
    int getH(TreeNode* root) {
        return root ? 1 + max(getH(root->left), getH(root->right)) : 0;
    }
    void helper(vector<vector<string>>& r, TreeNode* root, int h, int i, int j) {
        if (!root) {
            return;
        }
        int mid = (i+j) / 2;
        r[h][mid] = to_string(root->val);
        helper(r, root->left, h+1, i, mid-1);
        helper(r, root->right, h+1, mid+1, j);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 655. Print Binary Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        //1,2
        //1,2,3,-1,4
        1,2,5,3,-1,-1,-1,4
    };

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    vector<vector<string>> r = sol.printTree(root);
    for (auto v: r) {
        for (string s: v) {
            cout << (s != "" ? s : "*") << ' ';
        }
        cout << '\n';
    }

    return 0;
}
