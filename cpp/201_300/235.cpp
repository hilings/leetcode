//
//  235.cpp
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


    bool containNode(TreeNode* root, TreeNode* p) {
        if (!root)
            return false;
        return root == p || containNode(root->left, p) || containNode(root->right, p);
    }

    TreeNode* lowestCommonAncestor0(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (containNode(root->left, p) && containNode(root->left, q))
            return lowestCommonAncestor0(root->left, p, q);
        if (containNode(root->right, p) && containNode(root->right, q))
            return lowestCommonAncestor0(root->right, p, q);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 235. Lowest Common Ancestor of a Binary Search Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {2,1};

    TreeNode *root = sol.build(nodes);
    sol.printT(root);

    TreeNode *p = root, *q = root->left;
    
    TreeNode* r0 = sol.lowestCommonAncestor0(root, p, q);
    cout << r0->val << '\n';
    
    TreeNode* r = sol.lowestCommonAncestor(root, p, q);
    cout << r->val << '\n';
    
    return 0;
}