//
//  103.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/14/16.
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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if (!root)
            return v;
        TreeNode *end = new TreeNode(0);
        deque<TreeNode*> q {root, end};
        bool forward = true;
        while (!q.empty()) {
            vector<int> tv;
            while (q.front() != end) {
                if (forward)
                    tv.push_back(q.front()->val);
                else
                    tv.insert(tv.begin(), q.front()->val);
                if (q.front()->left)
                    q.push_back(q.front()->left);
                if (q.front()->right)
                    q.push_back(q.front()->right);
                q.pop_front();
            }
            q.pop_front();	// end
            v.push_back(tv);
            if (q.empty())
                break;
            else {
                q.push_back(end);
                forward = !forward;
            }
        }
        return v;
    }

};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 103 Binary Tree Zigzag Level Order Traversal, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {3,9,20,0,0,15,7};
    TreeNode *root = sol.build(nodes);
    
    vector<vector<int>> r = sol.zigzagLevelOrder(root);
    
    for (auto v: r) {
        cout << "[ ";
        for (auto a: v) {
            cout << a << ' ';
        }
        cout << "]\n";
    }
    
    return 0;
}