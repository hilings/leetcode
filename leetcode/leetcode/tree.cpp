//
//  tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/28/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
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

    void preTr(TreeNode* root) {    // pre order traversal, recursive
        if (!root)
            return;
        cout << root->val << ' ';
        preTr(root->left);
        preTr(root->right);
    }
    void preTi(TreeNode *root) {    // pre order traversal, iterative
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty()) {
            if (cur) {
                cout << cur->val << ' ';
                if (cur->right)
                    stk.push(cur->right);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
            }
        }
    }

    void inTr(TreeNode* root) { // in order traversal, recursive
        if (!root)
            return;
        inTr(root->left);
        cout << root->val << ' ';
        inTr(root->right);
    }
    void inTi(TreeNode* root) { // in order traversal, iterative
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cout << stk.top()->val << ' ';
                cur = stk.top()->right;
                stk.pop();
            }
        }
    }

    void postTr(TreeNode* root) {   // post order traversal, recursive
        if (!root)
            return;
        postTr(root->left);
        postTr(root->right);
        cout << root->val << ' ';
    }
    void postTi(TreeNode* root) {   // post order traversal, iterative
        stack<TreeNode*> stk;
        TreeNode *cur = root, *prev = NULL;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else if (stk.top()->right && prev != stk.top()->right) {
                cur = stk.top()->right;
            } else {
                cout << stk.top()->val << ' ';
                prev = stk.top();
                stk.pop();
            }
        }
    }

    void traversalByLevel(TreeNode* root) {
        if (!root)
            return;
        deque<TreeNode*> q {root};
        while (!q.empty()) {
            int n = (int)q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                cout << cur->val << ' ';
                if (cur->left)
                    q.push_back(cur->left);
                if (cur->right)
                    q.push_back(cur->right);
                q.pop_front();
            }
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

    cout << "\n\npre order traversal, recursive\n";
    sol.preTr(root);
    cout << "\n\npre order traversal, iterative\n";
    sol.preTi(root);

    cout << "\n\nin order traversal, recursive\n";
    sol.inTr(root);
    cout << "\n\nin order traversal, iterative\n";
    sol.inTi(root);

    cout << "\n\npost order traversal, recursive\n";
    sol.postTr(root);
    cout << "\n\npost order traversal, iterative\n";
    sol.postTi(root);

    cout << "\n\ntraversal by level\n";
    sol.traversalByLevel(root);


    return 0;
}