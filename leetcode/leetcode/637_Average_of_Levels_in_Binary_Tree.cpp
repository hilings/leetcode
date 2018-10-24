//
//  637_Average_of_Levels_in_Binary_Tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/23/18.
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

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> r;
        vector<int> count;
        dfs(r, count, root, 0);
        for (int i = 0; i < count.size(); i++) {
            r[i] /= count[i];
        }
        return r;
    }
    void dfs(vector<double>& r, vector<int>& count, TreeNode* root, int level) {
        if (level == r.size()) {
            r.push_back(0);
            count.push_back(0);
        }
        r[level] += root->val;
        count[level]++;
        if (root->left) {
            dfs(r, count, root->left, level+1);
        }
        if (root->right) {
            dfs(r, count, root->right, level+1);
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 637. Average of Levels in Binary Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        3,9,20,-1,-1,15,7
    };
    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    vector<double> r = sol.averageOfLevels(root);
    for (double a: r) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}
