//
//  572_Subtree_of_Another_Tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/12/18.
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

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (isEqual(s, t) || (s->left && isSubtree(s->left, t)) || (s->right && isSubtree(s->right, t)) ) {
            return true;
        }
        return false;
    }
    bool isEqual(TreeNode* s, TreeNode* t) {
        if (!s && !t) {
            return true;
        } else if (s || t) {
            return false;
        }
        return s->val == t->val && isEqual(s->left, t->left) && isEqual(s->right, t->right);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 572. Subtree of Another Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        3,4,5,1,2   // true
        //3,4,5,1,2,-1,-1,-1,-1,0 // false
        //1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,2
    };
    TreeNode* s = sol.build(nodes);
    sol.printT(s);

    vector<int> nodet {
        4,1,2
        //1,-1,1,-1,1,-1,1,-1,1,-1,1,2
    };
    TreeNode* t = sol.build(nodet);
    sol.printT(t);

    bool r = sol.isSubtree(s, t);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
