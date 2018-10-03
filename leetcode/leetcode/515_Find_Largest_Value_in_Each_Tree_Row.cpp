//
//  515_Find_Largest_Value_in_Each_Tree_Row.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/1/18.
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

    vector<int> largestValues(TreeNode* root) {
        vector<int> r;
        if (!root) {
            return r;
        }
        deque<TreeNode*> q {root, NULL};
        int k = INT_MIN;
        while (!q.empty()) {
            if (q[0]) {
                k = max(k, q[0]->val);
                if (q[0]->left) {
                    q.push_back(q[0]->left);
                }
                if (q[0]->right) {
                    q.push_back(q[0]->right);
                }
                q.pop_front();
            } else {    // row separator
                q.pop_front();
                r.push_back(k);
                if (!q.empty()) {
                    q.push_back(NULL);
                    k = INT_MIN;
                }
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 515. Find Largest Value in Each Tree Row, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        1,3,2,5,3,-1,9
    };

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    vector<int> r = sol.largestValues(root);
    for (int a: r) {
        cout << a << ' ';
    }
    cout << '\n';
    
    return 0;
}
