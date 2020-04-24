//
//  236.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/14/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
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

    TreeNode* lowestCommonAncestor0(TreeNode* root, TreeNode* p, TreeNode* q) {	// iterative
        deque<TreeNode*> dq, path_p, path_q;
        TreeNode *cur = root;
        while (cur || !dq.empty()) {
            if (cur) {
                dq.push_back(cur);
                if (cur == p)
                    path_p = dq;
                if (cur == q)
                    path_q = dq;
                if (!path_p.empty() && !path_q.empty())
                    break;
                cur = cur->left;
            } else if (dq.back()->right) {
                cur = dq.back()->right;
            } else {
                TreeNode* tmp = dq.back();
                dq.pop_back();
                while (!dq.empty() && dq.back()->right == tmp) {
                    tmp = dq.back();
                    dq.pop_back();
                }
            }
        }
        for (TreeNode* t: path_p) {
            cout << t->val;
        }
        cout << '\n';
        for (TreeNode* t: path_q) {
            cout << t->val;
        }
        cout << '\n';
        for (int i = min((int)path_p.size(), (int)path_q.size())-1; i > 0; i--) {
            if (path_p[i] == path_q[i])
                return path_p[i];
        }
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {	// recursive
        if (!root)
            return NULL;
        if (root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        return left ? left : right;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 235. Lowest Common Ancestor of a Binary Search Tree, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {3,5,1,6,2,0,8,-1,-1,7,4};
    
    TreeNode *root = sol.build(nodes);
    sol.printT(root);
    
    //TreeNode *p = root->left, *q = root->right;
    TreeNode *p = root->left, *q = root->right;
    
    TreeNode* r0 = sol.lowestCommonAncestor0(root, p, q);
    cout << r0->val << '\n';
    
    TreeNode* r = sol.lowestCommonAncestor(root, p, q);
    cout << r->val << '\n';
    
    return 0;
}