//
//  traversal.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/27/16.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
    TreeNode* buildT(vector<int> nodes) {    // build full tree
        vector<TreeNode*> v {0};
        for (int a: nodes) {
            v.push_back(new TreeNode(a));
        }
        for (int i = 1; i < v.size(); i++) {
            if (i*2 < v.size())
                v[i]->left = v[i*2];
            if (i*2+1 < v.size())
                v[i]->right = v[i*2+1];
        }
        return v[1];
    }

    void preTr(TreeNode* root) {
        if (!root)
            return;
        cout << root->val << ' ';
        preTr(root->left);
        preTr(root->right);
    }

    void inTr(TreeNode* root) {
        if (!root)
            return;
        inTr(root->left);
        cout << root->val << ' ';
        inTr(root->right);
    }

    void postTr(TreeNode* root) {
        if (!root)
            return;
        postTr(root->left);
        postTr(root->right);
        cout << root->val << ' ';
    }

    void preTi(TreeNode *root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            if (cur) {
                cout << cur->val << ' ';
                if (cur->right)
                    stk.push(cur->right);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
            }
        }
    }
    
    void inTi(TreeNode *root) {
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cout << stk.top()->val << ' ';
                cur = stk.top()->right;
                stk.pop();
            }
        }
    }

    void postTi(TreeNode *root) {
        stack<TreeNode*> stk;
        TreeNode *cur = root, *last = NULL;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else if (stk.top()->right && last != stk.top()->right) {
                cur = stk.top()->right;
            } else {
                cout << stk.top()->val << ' ';
                last = stk.top();
                stk.pop();
            }
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 000 Tree Traversal, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {1,2,3,4,5,6,7};
    TreeNode *root = sol.buildT(nodes);

    cout << "pre order traversal, recursive...\n";
    sol.preTr(root);

    cout << "\n\npre order traversal, iterative...\n";
    sol.preTi(root);


    cout << "\n\nin order traversal, recursive...\n";
    sol.inTr(root);

    cout << "\n\nin order traversal, iterative...\n";
    sol.inTi(root);


    cout << "\n\npost order traversal, recursive...\n";
    sol.postTr(root);

    cout << "\n\npost order traversal, iterative...\n";
    sol.postTi(root);


    return 0;
}
