//
//  662_Maximum_Width_of_Binary_Tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/26/18.
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

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        deque<TreeNode*> q {root};
        int r = 1;
        while (!q.empty()) {
            deque<TreeNode*> level;
            while (!q.empty()) {
                TreeNode* cur = q.front();
                q.pop_front();
                if (cur) {
                    level.push_back(cur->left);
                    level.push_back(cur->right);
                } else {
                    level.push_back(NULL);
                    level.push_back(NULL);
                }
            }
            while (!level.empty() && level.front() == NULL) {
                level.pop_front();
            }
            while (!level.empty() && level.back() == NULL) {
                level.pop_back();
            }
            r = max(r, (int)level.size());
            q = level;
        }
        return r;
    }

    int widthOfBinaryTree2(TreeNode* root) {
        vector<pair<int,int>> v;    // maintain the index of leftmost and rightmost node for each level
        int r = 0;
        dfs(root, 0, 1, v, r);  // root index start from 1
        return r;
    }
    void dfs(TreeNode* root, int level, int index, vector<pair<int,int>>& v, int& r) {
        if (!root) {
            return;
        }
        if (level == v.size()) {
            v.push_back(pair<int,int> (index, index));
        } else {
            v[level].second = index;
        }
        r = max(r, v[level].second - v[level].first + 1);
        dfs(root->left, level+1, index*2, v, r);    // index of left  child = index*2
        dfs(root->right, level+1, index*2+1, v, r); // index of right child = index*2+1
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 662. Maximum Width of Binary Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        //1,3,2,5,3,-1,9  // 4
        // 1,3,-1,5,3  // 2
        //1,3,2,5 // 2
        1,3,2,5,-1,-1,9,6,-1,-1,7   // 8
    };
    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    int r = sol.widthOfBinaryTree(root);
    cout << r << '\n';

    int r2 = sol.widthOfBinaryTree2(root);
    cout << r2 << '\n';

    return 0;
}
