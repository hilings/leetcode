//
//  404_sum_of_left_leaves.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/28/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
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
                v.push_back(-1);
            q.pop_front();
        }
        while (v.back() == -1)
            v.pop_back();
        for (auto a: v) {
            if (a != -1)
                cout << a;
            else
                cout << '#';
            cout << ' ';
        }
        cout << '\n';
    }

    int sumOfLeftLeaves(TreeNode* root) {
        TreeNode *cur = root;
        stack<TreeNode*> stk;
        int sum = 0;
        while (cur || !stk.empty()) {
            if (cur) {
                cout << cur->val << '\n';
                if (cur->right) {
                    stk.push(cur->right);
                }
                if (cur->left && !cur->left->left && !cur->left->right) {	// left leave
                    sum += cur->left->val;
                    printf("adding %d\n", cur->left->val);
                }
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
            }
        }
        return sum;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 404. Sum of Left Leaves, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {3,9,20,-1,-1,15,7};
    
    TreeNode *root = sol.build(nodes);
    sol.printT(root);
    
    int r = sol.sumOfLeftLeaves(root);
    cout << r << '\n';
    
    return 0;
}
