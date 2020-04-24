//
//  297.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/31/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
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

class Codec {
public:
    TreeNode* build(vector<int> nodes) {
        // build tree from serialization
        TreeNode *root = new TreeNode(nodes[0]);
        deque<TreeNode*> q {root};
        int i = 1;
        while (i < nodes.size()) {
            if (nodes[i] != INT_MIN) {
                TreeNode* left = new TreeNode(nodes[i]);
                q.front()->left = left;
                q.push_back(left);
            }
            i++;
            if (i < nodes.size() && nodes[i] != INT_MIN) {
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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {	// iterative
        if (!root)
            return "";
        deque<TreeNode*> q {root};
        for (int i = 0; i < q.size(); i++) {
            if (!q[i])
                continue;
            q.push_back(q[i]->left);
            q.push_back(q[i]->right);
        }
        while (q.back() == NULL)
            q.pop_back();

        string ret = "";
        for (int i = 0; i < q.size(); i++)
            ret += q[i] ? "," + to_string(q[i]->val) : ",null";

        return ret.substr(1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {	// iterative
        if (data.empty())
            return NULL;
        deque<TreeNode*> q;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ',')
                continue;
            if (isdigit(data[i]) || data[i] == '-') {
                bool negative = false;
                if (data[i] == '-') {
                    negative = true;
                    i++;
                }
                int d = data[i]-'0';
                while (i+1<data.size() && isdigit(data[i+1]))
                    d = 10*d + data[++i]-'0';
                if (negative)
                    d = -d;
                q.push_back(new TreeNode(d));
            } else {
                q.push_back(NULL);
                i += 3;
            }
        }
        int p = 0, c = 1;
        while (c < q.size()) {
            while (!q[p])
                p++;
            q[p]->left = q[c++];
            q[p++]->right = q[c++];
        }
        return q[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 297. Serialize and Deserialize Binary Tree, C++ ...\n\n";
    Codec sol;
    
    vector<int> nodes {1,2,-3,INT_MIN,INT_MIN,4,5};
    TreeNode* root = sol.build(nodes);
    sol.printT(root);
    
    string data = sol.serialize(root);
    cout << data << '\n';
    
    TreeNode* newroot = sol.deserialize(data);
    sol.printT(newroot);
    
    return 0;
}