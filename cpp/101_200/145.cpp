//
//  145.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/29/16.
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
    void building(deque<TreeNode*>q, vector<int>& nodes) {
        // build tree from serialization
        if (nodes.empty())
            return;
        if (nodes.front() != -1) {
            TreeNode *left = new TreeNode(nodes.front());
            q.front()->left = left;
            q.push_back(left);
        }
        nodes.erase(nodes.begin());

        if (nodes.empty())
            return;
        if (nodes.front() != -1) {
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

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        TreeNode *cur = root, *prev = NULL;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else if (stk.top()->right && prev != stk.top()->right) {
                cur = stk.top()->right;
            } else {
                ret.push_back(stk.top()->val);
                prev = stk.top();
                stk.pop();
            }
        }
        return ret;
    }
    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> ret;
        if (!root)
            return ret;
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        ret.insert(ret.end(), left.begin(), left.end());
        ret.insert(ret.end(), right.begin(), right.end());
        ret.push_back(root->val);
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 145. Binary Tree Postorder Traversal, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {1,2,3,4,5,6,7};
    TreeNode *root = sol.build(nodes);
    
    sol.printT(root);
    
    vector<int> r = sol.postorderTraversal(root);
    
    for (int a: r) {
        cout << a << '\n';
    }
    
    return 0;
}