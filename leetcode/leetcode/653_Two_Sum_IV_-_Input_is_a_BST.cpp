//
//  653_Two_Sum_IV_-_Input_is_a_BST.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/26/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
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

    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> um;
        return dfs(root, um, k);
    }
    bool dfs(TreeNode* root, unordered_map<int,int>& um, int k) {
        if (!root) {
            return false;
        }
        if (um.find(k - root->val) != um.end()) {
            printf("found %d + %d = %d\n", root->val, k - root->val, k);
            return true;
        }
        printf("marking %d\n", root->val);
        um[root->val] = um.find(root->val) != um.end() ? um[root->val]+1 : 1;
        return dfs(root->left, um, k) || dfs(root->right, um, k);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 653. Two Sum IV - Input is a BST, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        5,3,6,2,4,-1,7

    };
    int k = 9;
    k = 14;

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    bool r = sol.findTarget(root, k);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
