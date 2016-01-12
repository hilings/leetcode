//
//  tree.cpp
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

void printV(vector<int> v) {
    for (auto a: v) {
        cout << a << ' ';
    }
    cout << '\n';
}

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

    void inT(vector<int> &v, TreeNode* root) {
    // recursive inorder traverse, into vector
        if (!root)
            return;
        inT(v, root->left);
        v.push_back(root->val);
        inT(v, root->right);
    }

public:
    TreeNode* build(vector<int> nodes) {    // build tree from serialization
        TreeNode *root = new TreeNode(nodes.front());
        deque<TreeNode*> q {root};
        nodes.erase(nodes.begin());
        building(q, nodes);
        return root;
    }

    vector<int> inorderTraversal(TreeNode* root) {
    // recursive inorder traverse, into vector
        vector<int> v;
        inT(v, root);
        return v;
    }

    void printT(TreeNode *root) {   // print serialized tree
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
    cout << "LeetCode 094 Tree Library, C++ ...\n\n";
    Solution sol;

    //vector<int> nodes {1,0,2,3};
    vector<int> nodes {1,2,3,0,0,4,0,0,5};
    TreeNode *root = sol.build(nodes);

    vector<int> r = sol.inorderTraversal(root);
    printV(r);
    
    return 0;
}