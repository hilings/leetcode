//
//  538_Convert_BST_to_Greater_Tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/8/18.
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

    TreeNode* convertBST(TreeNode* root) {
        if (!root) {
            return root;
        }
        int next = INT_MIN;
        postT(root, next);
        return root;
    }
    void postT(TreeNode* root, int& next) {
        if (root->right) {
            postT(root->right, next);
        }
        if (next != INT_MIN) {
            root->val += next;
        }
        next = root->val;
        if (root->left) {
            postT(root->left, next);
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 538. Convert BST to Greater Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        5, 2, 13
    };

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    TreeNode* r = sol.convertBST(root);
    sol.printT(r);

    return 0;
}
