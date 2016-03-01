//
//  144.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/28/16.
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
public:
    TreeNode* build(vector<int> nodes) {
        // build tree from serialization
        TreeNode *root = new TreeNode(nodes.front());
        deque<TreeNode*> q {root};
        nodes.erase(nodes.begin());
        building(q, nodes);
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
    vector<int> preorderTraversal(TreeNode* root) {
    //  iterative
        vector<int> ret;
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty()) {
            if (cur) {
                ret.push_back(cur->val);
                if (cur->right)
                    stk.push(cur->right);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
            }
        }
        return ret;
    }
    vector<int> preorderTraversal2(TreeNode* root) {
    //  recurrsive
        vector<int> ret;
        if (!root)
            return ret;
        ret.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        ret.insert(ret.end(), left.begin(), left.end());
        vector<int> right = preorderTraversal(root->right);
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 144. Binary Tree Preorder Traversal, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {1,0,2,3};
    //vector<int> nodes {1,2,3,0,0,4,0,0,5};
    TreeNode *root = sol.build(nodes);

    sol.printT(root);

    vector<int> r = sol.preorderTraversal(root);
    for (int a: r) {
        cout << a << '\n';
    }
    
    return 0;
}