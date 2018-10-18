//
//  606_Construct_String_from_Binary_Tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/18/18.
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

    string tree2str(TreeNode* t) {
        string r = "";
        if (!t) {
            return r;
        }
        r += to_string(t->val);
        if (t->left) {
            r += "(" + tree2str(t->left) + ")";
        }
        if (t->right) {
            r += t->left ? "" : "()";
            r += "(" + tree2str(t->right) + ")";
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 606. Construct String from Binary Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        //1,2,3,4 // 1(2(4))(3)
        1,2,3,-1,4  // 1(2()(4))(3)
    };

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    string r = sol.tree2str(root);
    cout << r << '\n';

    return 0;
}
