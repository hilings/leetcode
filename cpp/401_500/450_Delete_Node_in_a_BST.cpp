//
//  450_Delete_Node_in_a_BST.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/22/18.
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

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        }
        //printf("cur = %d\n", root->val);
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (!root->left){
            return root->right;
        } else {
            TreeNode *p = root->left;
            if (!p->right) {
                root->val = p->val;
                root->left = p->left;
            } else {
                TreeNode *q = p->right;
                while (q->right) {
                    p = q;
                    q = q->right;
                }
                root->val = q->val;
                p->right = deleteNode(q, q->val);
            }
        }
        return root;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 450. Delete Node in a BST, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        //5,3,6,2,4,-1,7  //
        //1,-1,2
        //3,2,-1,1
        3,1,4,-1,2
    };
    int key = 3;
    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    root = sol.deleteNode(root, key);
    sol.printT(root);

    return 0;
}
