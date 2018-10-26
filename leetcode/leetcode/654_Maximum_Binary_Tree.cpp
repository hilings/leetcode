//
//  654_Maximum_Binary_Tree.cpp
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

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, (int)nums.size()-1);
    }
    TreeNode* helper(vector<int>& nums, int i, int j) {
        if (i > j) {
            return NULL;
        }
        int m = i;
        for (int k = i+1; k <= j; k++) {
            if (nums[k] > nums[m]) {
                m = k;
            }
        }
        TreeNode* r = new TreeNode(nums[m]);
        r->left = helper(nums, i, m-1);
        r->right = helper(nums, m+1, j);
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 654. Maximum Binary Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        3,2,1,6,0,5
    };

    TreeNode* r = sol.constructMaximumBinaryTree(nums);
    sol.printT(r);

    return 0;
}
