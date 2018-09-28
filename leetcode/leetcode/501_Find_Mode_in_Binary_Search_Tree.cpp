
//
//  501_Find_Mode_in_Binary_Search_Tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/13/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
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

    vector<int> findMode(TreeNode* root) {
        vector<int> r;
        unordered_map<int,int> um;
        int count = 0;
        traverse(root, um, count);
        for (auto p: um) {
            if (p.second == count) {
                r.push_back(p.first);
            }
        }
        return r;
    }
    void traverse(TreeNode* root, unordered_map<int,int>& um, int& count) {
        if (!root) {
            return;
        }
        int val = root->val;
        um.find(val) == um.end() ? um[val] = 1 : um[val]++;
        if (um[val] > count) {
            count = um[val];
        }
        traverse(root->left, um, count);
        traverse(root->right, um, count);
    }

    vector<int> findMode2(TreeNode* root) {
        vector<int> r;
        int cur, curCount = 0, modeCount = 0;
        inT(root, cur, curCount, modeCount, 1, r);
        curCount = 0;
        inT(root, cur, curCount, modeCount, 2, r);
        return r;
    }
    void inT(TreeNode* root, int& cur, int& curCount, int& modeCount, int pass, vector<int>& r) {
        if (!root) {
            return;
        }
        inT(root->left, cur, curCount, modeCount, pass, r);

        if (root->val != cur) {
            cur = root->val;
            curCount = 0;
        }
        curCount++;
        if (pass == 1 && curCount > modeCount) {
            modeCount = curCount;
        }
        if (pass == 2 && curCount == modeCount) {
            r.push_back(cur);
        }

        inT(root->right, cur, curCount, modeCount, pass, r);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 501. Find Mode in Binary Search Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes = {1, -1, 2, 2};

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    vector<int> r = sol.findMode(root);
    for (int a: r) {
        cout << a << ' ';
    }
    cout << '\n';

    vector<int> r2 = sol.findMode2(root);
    for (int a: r2) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}
