//
//  199.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/23/16.
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

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root)
            return ret;
        deque<TreeNode*> q {root};
        while (!q.empty()) {
            size_t n = q.size();
            for (size_t i = 0; i < n; i++) {
                if (i == 0)
                    ret.push_back(q.front()->val);
                if (q.front()->right)
                    q.push_back(q.front()->right);
                if (q.front()->left)
                    q.push_back(q.front()->left);
                q.pop_front();
            }
        }
        return ret;
    }

    vector<int> rightSideView0(TreeNode* root) {
        vector<int> ret;
        if (!root)
            return ret;
        vector<vector<TreeNode*>> nodesByLevel {vector<TreeNode*> {root}};
        for (int i = 0; i < nodesByLevel.size(); i++) {
            cout << "\ni = " << i << '\n';
            for (TreeNode* p: nodesByLevel[i]) {
                cout << p->val << ' ';
                if (ret.size() <= i)
                    ret.push_back(p->val);
                if (nodesByLevel.size() <= i+1)
                    nodesByLevel.push_back(vector<TreeNode*> {});
                if (p->right)
                    nodesByLevel[i+1].push_back(p->right);
                if (p->left)
                    nodesByLevel[i+1].push_back(p->left);
            }
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 199. Binary Tree Right Side View, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {1,2,3,-1,5,-1,4};
    TreeNode* root = sol.build(nodes);
    sol.printT(root);
    
    vector<int> r = sol.rightSideView(root);
    for (int a: r) {
        cout << a << ' ';
    }
    cout << '\n';
    
    return 0;
}