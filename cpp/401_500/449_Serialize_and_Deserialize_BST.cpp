//
//  449_Serialize_and_Deserialize_BST.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/21/18.
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

class Codec {
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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        string r = to_string(root->val);
        r += root->left ? " " + serialize(root->left) : "";
        r += root->right ? " " + serialize(root->right) : "";
        return r;
    }
    string serialize2(TreeNode* root) {
        if (!root) {
            return "";
        }

        char c[4];
        memcpy(c, &(root->val), sizeof(int)); //burn the int into 4 chars
        string r = "";
        for (int i = 0; i < sizeof(int); i++) {
            r += c[i];
        }

        r += root->left ? serialize2(root->left) : "";
        r += root->right ? serialize2(root->right) : "";
        return r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        string val = "";
        size_t size = data.size(), left = size, right = size;
        for (size_t pos = 0, sp; pos < size; pos = sp+1) {
            sp = data.find_first_of(' ', pos);  // split by ' '
            if (sp == -1) { // reaching end
                sp = size;
            }
            string cur = data.substr(pos, sp-pos);
            if (pos == 0) {    // root
                val = cur;
                root = new TreeNode(stoi(val));
                if (sp != size) {  // otherwise no children
                    left = sp+1;   // begin of left or right
                }
            } else if (stoi(cur) > stoi(val)) {
                right = pos;    // begin of right
                root->right = deserialize(data.substr(right));
                break;
            }
        }
        if (left < right) {
            root->left = deserialize(data.substr(left, right == size ? size-left : right-1-left));
        }
        return root;
    }
    TreeNode* deserialize2(string data) {
        TreeNode* root = NULL;
        int val = 0, size = (int)data.size(), left = sizeof(int), right = size;
        for (int pos = 0; pos < size; pos += sizeof(int)) {
            int cur;
            memcpy(&cur, &data[pos], sizeof(int));

            if (pos == 0) {    // root
                val = cur;
                root = new TreeNode(val);
            } else if (cur > val) {
                right = pos;    // begin of right
                root->right = deserialize2(data.substr(right));
                break;
            }
        }
        if (left < right) {
            root->left = deserialize2(data.substr(left, right-left));
        }
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 449. Serialize and Deserialize BST, C++ ...\n\n";
    Codec sol;

    vector<int> nodes {
        4,2,6,1,3,5,7
    };
    TreeNode* root = sol.build(nodes);
    sol.printT(root);

    string r = sol.serialize(root);
    cout << r << '\n';

    TreeNode* rr = sol.deserialize(r);
    sol.printT(rr);
    cout << '\n';

    string r2 = sol.serialize2(root);
    cout << r2 << '\n';

    TreeNode* rr2 = sol.deserialize2(r2);
    sol.printT(rr2);

    return 0;
}
