//
//  173.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/14/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

/**
 * Definition for binary tree with next pointer.
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
        if (nodes.front() != -1) {
            TreeNode *left = new TreeNode(nodes.front());
            q.front()->left = left;
            q.push_back(left);
        }
        nodes.erase(nodes.begin());

        if (nodes.empty())
            return;
        if (nodes.front() != -1) {
            TreeNode *right = new TreeNode(nodes.front());
            q.front()->right = right;
            q.push_back(right);
        }
        nodes.erase(nodes.begin());

        q.pop_front();
        building(q, nodes);
    }
public:
    TreeNode* build(vector<int> nodes) {
        // build tree from serialization
        TreeNode *root = new TreeNode(nodes.front());
        deque<TreeNode*> q {root};
        nodes.erase(nodes.begin());
        building(q, nodes);
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

};
class BSTIterator {
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode *root) {
        TreeNode *p = root;
        while (p) {
            stk.push(p);
            p = p->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        int ret = stk.top()->val;
        TreeNode *p = stk.top()->right;
        stk.pop();
        while (p) {
            stk.push(p);
            p = p->left;
        }
        return ret;
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 173. Binary Search Tree Iterator, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {4,2,6,1,3,5,7};

    TreeNode *root = sol.build(nodes);
    sol.printT(root);
    
    /**
     * Your BSTIterator will be called like this:
     */
    BSTIterator i = BSTIterator(root);
    while (i.hasNext())
        cout << i.next();
    
    return 0;
}