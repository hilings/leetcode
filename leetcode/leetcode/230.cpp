//
//  230.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/12/16.
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

    int kthSmallest0(TreeNode* root, int k) {
        int nLeft = countNodes(root->left);
        if (nLeft == k-1)
            return root->val;
        else if (nLeft > k-1)
            return kthSmallest0(root->left, k);
        else
            return kthSmallest0(root->right, k-1-nLeft);
    }
    int countNodes(TreeNode* root) {	// kthSmallest0
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                if (--k == 0)
                    return stk.top()->val;
                cur = stk.top()->right;
                stk.pop();
            }
        }
        return 0;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 230. Kth Smallest Element in a BST, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {4,2,6,1,3,5,7};
    
    TreeNode *root = sol.build(nodes);
    sol.printT(root);
    
    int k = 4;
    
    int r = sol.kthSmallest(root, k);
    cout << r << '\n';
    
    return 0;
}