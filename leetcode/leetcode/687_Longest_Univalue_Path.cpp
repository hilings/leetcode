//
//  687_Longest_Univalue_Path.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/1/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
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
        if (nodes.empty()) {
            return NULL;
        }
        TreeNode *root = new TreeNode(nodes[0]);
        deque<TreeNode*> q {root};
        int i = 1, NaN = -1;   // flag of NULL
        while (i < nodes.size()) {
            if (nodes[i] != NaN) {
                TreeNode* left = new TreeNode(nodes[i]);
                q.front()->left = left;
                q.push_back(left);
            }
            i++;
            if (i < nodes.size() && nodes[i] != NaN) {
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
        if (!root) {
            cout << "#\n";
            return;
        }
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
                v.push_back(INT_MIN);
            q.pop_front();
        }
        while (v.back() == INT_MIN)
            v.pop_back();
        for (auto a: v) {
            if (a != INT_MIN)
                cout << a;
            else
                cout << '#';
            cout << ' ';
        }
        cout << '\n';
    }

    int longestUnivaluePath0(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max({dfs0(root->left, root->val, 0) + dfs0(root->right, root->val, 0), longestUnivaluePath0(root->left), longestUnivaluePath0(root->right)});
    }

    int dfs0(TreeNode* root, int val, int depth) {   // top down
        if (!root || root->val != val) {
            return depth;
        }
        return max(dfs0(root->left, val, depth+1), dfs0(root->right, val, depth+1));
    }

    int longestUnivaluePath(TreeNode* root) {
        int r = 0;
        dfs(root, r);
        return r;
    }

    int dfs(TreeNode* root, int& r) {  // bottom up
        if (!root) {
            return 0;
        }
        int ll = dfs(root->left, r), rr = dfs(root->right, r);
        int left = root->left && root->left->val == root->val ? ll + 1 : 0;
        int right = root->right && root->right->val == root->val ? rr + 1 : 0;
        r = max(r, left + right);
        return max(left, right);    // longest path from root down
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 687. Longest Univalue Path, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        //5,4,5,1,1,-1,5
        1,4,5,4,4,5     // 2
    };

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    int r = sol.longestUnivaluePath0(root);
    cout << r << '\n';

    int r2 = sol.longestUnivaluePath(root);
    cout << r2 << '\n';

    return 0;
}
