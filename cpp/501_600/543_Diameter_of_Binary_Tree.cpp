//
//  543_Diameter_of_Binary_Tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/9/18.
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

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int r = 0;
        height(root, r);
        return r;
    }
    int height(TreeNode* root, int& r) {
        int left = root->left ? height(root->left, r)+1 : 0;
        int right = root->right ? height(root->right, r)+1 : 0;
        r = max(r, left + right);
        return max(left, right);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 543. Diameter of Binary Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        1,2,3,4,5
    };

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    int r = sol.diameterOfBinaryTree(root);
    cout << r << '\n';

    return 0;
}
