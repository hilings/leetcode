//
//  095.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/8/16.
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
    vector<TreeNode*> solve(int a, int b) {
        vector<TreeNode*> v;
        if (a == b)
            v.push_back(new TreeNode(a));
        else if (a > b)
            v.push_back(NULL);
        else {
            for (int i = a; i <= b; i++) {
                vector<TreeNode*> left = solve(a, i-1);
                vector<TreeNode*> right = solve(i+1, b);
                for (auto p: left) {
                    for (auto q: right) {
                        TreeNode *root = new TreeNode(i);
                        root->left = p;
                        root->right = q;
                        v.push_back(root);
                    }
                }
            }
        }
        return v;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*> {};
        return solve(1, n);
    }

    void printT(TreeNode *root) {
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
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 095 Unique Binary Search Trees II, C++ ...\n\n";
    Solution sol;

    int n = 3;

    vector<TreeNode*> r = sol.generateTrees(n);

    for (auto root: r) {
        sol.printT(root);
    }

    return 0;
}