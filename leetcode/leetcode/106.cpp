//
//  106.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/14/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
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
    void building(deque<TreeNode*>q, vector<int>& nodes) {
        // build tree from serialization
        if (nodes.empty())
            return;
        if (nodes.front() != 0) {
            TreeNode *left = new TreeNode(nodes.front());
            q.front()->left = left;
            q.push_back(left);
        }
        nodes.erase(nodes.begin());

        if (nodes.empty())
            return;
        if (nodes.front() != 0) {
            TreeNode *right = new TreeNode(nodes.front());
            q.front()->right = right;
            q.push_back(right);
        }
        nodes.erase(nodes.begin());

        q.pop_front();
        building(q, nodes);
    }
public:
    TreeNode* build(vector<int> nodes) {    // build tree from serialization
        TreeNode *root = new TreeNode(nodes.front());
        deque<TreeNode*> q {root};
        nodes.erase(nodes.begin());
        building(q, nodes);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> um;
        for (int i = 0; i < inorder.size(); i++)
            um[inorder[i]] = i;
        return solve(inorder, 0, (int)inorder.size()-1, postorder, 0, (int)postorder.size()-1, um);
    }
    TreeNode* solve(vector<int>& inorder, int a, int b, vector<int>& postorder, int c, int d, unordered_map<int,int>& um) {
        if (a > b)
            return NULL;
        TreeNode* root = new TreeNode(postorder[d]);
        int index = um[postorder[d]];
        root->left = solve(inorder, a, index-1, postorder, c, c+index-a-1, um);
        root->right = solve(inorder, index+1, b, postorder, c+index-a, d-1, um);
        return root;
    }
    void printT(TreeNode* root) {
        deque<TreeNode*> q {root};
        while (!q.empty()) {
            if (q.front()) {
                cout << q.front()->val << ' ';
                q.push_back(q.front()->left);
                q.push_back(q.front()->right);
            }
            q.pop_front();
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 106 Construct Binary Tree from Inorder and Postorder Traversal, C++ ...\n\n";
    Solution sol;

    vector<int> inorder {4,2,5,1,6,3,7};
    vector<int> postorder {4,5,2,6,7,3,1};

    TreeNode *root = sol.buildTree(inorder, postorder);
    sol.printT(root);
    
    return 0;
}