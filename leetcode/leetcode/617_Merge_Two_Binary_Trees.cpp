//
//  617_Merge_Two_Binary_Trees.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/19/18.
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

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) {
            return t2;
        }
        if (!t2) {
            return t1;
        }
        TreeNode* r = new TreeNode(t1->val + t2->val);
        r->left = mergeTrees(t1->left, t2->left);
        r->right = mergeTrees(t1->right, t2->right);
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 617. Merge Two Binary Trees, C++ ...\n\n";
    Solution sol;

    TreeNode* t1 = sol.build(vector<int> {
        1,3,2,5
    });
    sol.printT(t1);

    TreeNode* t2 = sol.build(vector<int> {
        2,1,3,-1,4,-1,7
    });
    sol.printT(t2);

    TreeNode* r = sol.mergeTrees(t1, t2);
    sol.printT(r);

    return 0;
}
