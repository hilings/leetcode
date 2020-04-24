//
//  623_Add_One_Row_to_Tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/21/18.
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

    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newroot = new TreeNode(v);
            newroot->left = root;
            return newroot;
        } else if (d == 2) {
            TreeNode* newleft = new TreeNode(v);
            newleft->left = root->left;
            root->left = newleft;

            TreeNode* newright = new TreeNode(v);
            newright->right = root->right;
            root->right = newright;
        } else {
            if (root->left) {
                root->left = addOneRow(root->left, v, d-1);
            }
            if (root->right) {
                root->right = addOneRow(root->right, v, d-1);
            }
        }
        return root;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 623. Add One Row to Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        //4,2,6,3,1,5
        4,2,-1,3,1
    };
    int v = 1;
    int d = 2;
    d = 3;

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    TreeNode* r = sol.addOneRow(root, v, d);
    sol.printT(r);

    return 0;
}
