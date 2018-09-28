//
//  508_Most_Frequent_Subtree_Sum.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/28/18.
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

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> r;
        if (!root) {
            return r;
        }
        unordered_map<int,int> um_v_f;
        int fMost = 0;
        subTreeSum(root, um_v_f, fMost);
        printf("fMost = %d\n", fMost);
        for (auto p: um_v_f) {
            printf("%d : %d\n", p.first, p.second);
            if (p.second == fMost) {
                r.push_back(p.first);
            }
        }
        return r;
    }
    int subTreeSum(TreeNode* root, unordered_map<int,int>& um_v_f, int& fMost) {
        int sum = root->val;
        if (root->left) {
            sum += subTreeSum(root->left, um_v_f, fMost);
        }
        if (root->right) {
            sum += subTreeSum(root->right, um_v_f, fMost);
        }
        cout << sum << '\n';ßœ
        um_v_f[sum] = um_v_f.find(sum) == um_v_f.end() ? 1 : um_v_f[sum]+1;
        if (um_v_f[sum] > fMost) {
            fMost = um_v_f[sum];
        }
        return sum;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 508. Most Frequent Subtree Sum, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {
        //5, 2, -3    // 2, -3, 4
        5, 2, -5    // 2
    };

    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    vector<int> r = sol.findFrequentTreeSum(root);
    for (int a: r) {
        cout << a << '\n';
    }

    return 0;
}
