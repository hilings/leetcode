//
//  108.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/15/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
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
    TreeNode* solve(vector<int>& nums, int a, int b) {
        if (a > b)
            return NULL;
        int index = (a+b)/2, val = nums[index];
        TreeNode *root = new TreeNode(val);
        root->left = solve(nums, a, index-1);
        root->right = solve(nums, index+1, b);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, (int)nums.size()-1);
    }
    void printT(TreeNode *root) {   // print serialized tree
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
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 108 Convert Sorted Array to Binary Search Tree, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {1,2,3,4,5,6,7};
    TreeNode *root = sol.sortedArrayToBST(nodes);
    
    sol.printT(root);
    
    return 0;
}