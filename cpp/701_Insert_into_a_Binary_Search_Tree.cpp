//
//  701_Insert_into_a_Binary_Search_Tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/6/19.
//  Copyright © 2019 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *build(vector<int> nodes)
    {
        // build tree from serialization
        if (nodes.empty())
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(nodes[0]);
        deque<TreeNode *> q{root};
        int i = 1, NaN = -1; // flag of NULL
        while (i < nodes.size())
        {
            if (nodes[i] != NaN)
            {
                TreeNode *left = new TreeNode(nodes[i]);
                q.front()->left = left;
                q.push_back(left);
            }
            i++;
            if (i < nodes.size() && nodes[i] != NaN)
            {
                TreeNode *right = new TreeNode(nodes[i]);
                q.front()->right = right;
                q.push_back(right);
            }
            i++;
            q.pop_front();
        }
        return root;
    }

    void printT(TreeNode *root)
    {
        // print serialized tree
        if (!root)
        {
            cout << "#\n";
            return;
        }
        deque<TreeNode *> q;
        q.push_back(root);
        vector<int> v;
        while (!q.empty())
        {
            TreeNode *p = q.front();
            if (p)
            {
                v.push_back(p->val);
                q.push_back(p->left);
                q.push_back(p->right);
            }
            else
                v.push_back(INT_MIN);
            q.pop_front();
        }
        while (v.back() == INT_MIN)
            v.pop_back();
        for (auto a : v)
        {
            if (a != INT_MIN)
                cout << a;
            else
                cout << '#';
            cout << ' ';
        }
        cout << '\n';
    }

    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *p = root;
        while ((val < p->val && p->left) || (val >= p->val && p->right))
        {
            p = val < p->val ? p->left : p->right;
        }
        if (val < p->val)
        {
            p->left = new TreeNode(val);
        }
        else
        {
            p->right = new TreeNode(val);
        }
        return root;
    }
};

int main(int arg, char *argv[])
{
    // insert code here...
    cout << "LeetCode 701. Insert into a Binary Search Tree, C++ ...\n\n";
    Solution sol;

    vector<int> nodes{4, 2, 7, 1, 3};
    TreeNode *root = sol.build(nodes);
    sol.printT(root);

    int val = 5;
    TreeNode *r = sol.insertIntoBST(root, val);
    sol.printT(r);

    return 0;
}
