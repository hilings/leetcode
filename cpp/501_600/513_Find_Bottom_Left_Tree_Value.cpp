//
//  513_Find_Bottom_Left_Tree_Value.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/29/18.
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

    int findBottomLeftValue(TreeNode* root) {
        deque<TreeNode*> q {root, NULL};
        int r = root->val;
        while (!q.empty()) {
            if (q[0] != NULL) {
                if (q[0]->left) {
                    q.push_back(q[0]->left);
                }
                if (q[0]->right) {
                    q.push_back(q[0]->right);
                }
                q.pop_front();
            } else {
                q.pop_front();  // row separator
                if (!q.empty()) {
                    q.push_back(NULL);
                    r = q[0]->val;
                }
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 513. Find Bottom Left Tree Value, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        //2,1,3   // 1
        1,2,3,4,-1,5,6,-1,-1,7  //
    };

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    int r = sol.findBottomLeftValue(root);
    cout << r << '\n';

    return 0;
}
