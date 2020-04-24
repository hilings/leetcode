//
//  563_Binary_Tree_Tilt.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/11/18.
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

    int findTilt(TreeNode* root) {
        int r = 0;
        treeSum(root, r);
        return r;
    }
    int treeSum(TreeNode* root, int& r) {
        if (!root) {
            return 0;
        }
        int left = treeSum(root->left, r);
        int right = treeSum(root->right, r);
        r += abs(left - right);
        return root->val + left + right;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 563. Binary Tree Tilt, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        1,2,3
    };

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    int r = sol.findTilt(root);
    cout << r << '\n';
    
    return 0;
}
