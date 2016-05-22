//
//  257.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeNode {
    int val;
    TreeNode *left, *right;
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
                v.push_back(-1);
            q.pop_front();
        }
        while (v.back() == -1)
            v.pop_back();
        for (auto a: v) {
            if (a != -1)
                cout << a;
            else
                cout << '#';
            cout << ' ';
        }
        cout << '\n';
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (!root)
            return ret;
        if (!root->left && !root->right)
            ret.push_back(to_string(root->val));
        for (string s: binaryTreePaths(root->left))
            ret.push_back(to_string(root->val)+"->"+s);
        for (string s: binaryTreePaths(root->right))
            ret.push_back(to_string(root->val)+"->"+s);
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 257. Binary Tree Paths, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {1,2,3,-1,5};
    
    TreeNode *root = sol.build(nodes);
    sol.printT(root);
    
    vector<string> r = sol.binaryTreePaths(root);
    for (string s: r) {
        cout << s << '\n';
    }
    
    return 0;
}