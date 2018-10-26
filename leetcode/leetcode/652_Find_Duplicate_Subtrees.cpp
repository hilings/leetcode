//
//  652_Find_Duplicate_Subtrees.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/25/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
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

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> r;
        unordered_map<string,int> um;
        preT(root, r, um);
        return r;
    }
    string preT(TreeNode* root, vector<TreeNode*>& r, unordered_map<string,int>& um) {
        if (!root) {
            return "#";
        }
        string s = to_string(root->val) + ',' + preT(root->left, r, um) + ',' + preT(root->right, r, um);
        um[s] = um.find(s) != um.end() ? um[s]+1 : 1;
        if (um[s] == 2) {
            r.push_back(root);
        }
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees2(TreeNode* root) {
        vector<TreeNode*> r;
        unordered_map<string,int> um_id {}; // serial => id
        unordered_map<int,int> um_count;    // id => count
        getId(root, um_id, um_count, r);
        return r;
    }

    int getId(TreeNode* root, unordered_map<string,int>& um_id, unordered_map<int,int>& um_count, vector<TreeNode*>& r) {
        /*
         tree id is based on root val and subtree id
         so duplicate subtree will have same id
         */
        if (!root) {
            return 0;
        }
        string s = to_string(root->val) + ',' + to_string(getId(root->left, um_id, um_count, r)) + ',' + to_string(getId(root->right, um_id, um_count, r));

        if (um_id.find(s) == um_id.end()) {
            um_id[s] = (int)um_id.size();
            um_count[um_id[s]] = 0;
        }
        um_count[um_id[s]]++;
        if (um_count[um_id[s]] == 2) {
            r.push_back(root);
        }
        return um_id[s];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 652. Find Duplicate Subtrees, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        1,2,3,4,-1,2,4,-1,-1,4
    };
    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    vector<TreeNode*> r = sol.findDuplicateSubtrees(root);
    for (TreeNode* p: r) {
        cout << p->val << '\n';
    }
    cout << '\n';

    vector<TreeNode*> r2 = sol.findDuplicateSubtrees2(root);
    for (TreeNode* p: r2) {
        cout << p->val << '\n';
    }

    return 0;
}
