//
//  590_N-ary_Tree_Postorder_Traversal.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/14/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 // Definition for a Node.
 */
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    void dfs(vector<int>& r, Node* root) {
        if (!root) {
            return;
        }
        for (auto child: root->children) {
            dfs(r, child);
        }
        r.push_back(root->val);
    }
public:
    vector<int> postorder0(Node* root) {
        vector<int> r;
        dfs(r, root);
        return r;
    }

    vector<int> postorder(Node* root) {
        vector<int> r;
        if (!root) {
            return r;
        }
        vector<Node*> v {root};
        Node* prev = NULL;
        while (!v.empty()) {
            Node* cur = v.back();
            if (cur->children.empty() || (prev && prev == cur->children.back())) {
                r.push_back(cur->val);
                v.pop_back();
                prev = cur;
            } else {
                v.insert(v.end(), cur->children.rbegin(), cur->children.rend());
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 590. N-ary Tree Postorder Traversal, C++ ...\n\n";
    Solution sol;

    Node* n5 = new Node(5, {});
    Node* n6 = new Node(6, {});
    Node* n3 = new Node(3, {n5, n6});
    Node* n2 = new Node(2, {});
    Node* n4 = new Node(4, {});
    Node* n1 = new Node(1, {n3, n2, n4});

    vector<int> r0 = sol.postorder0(n1);
    for (int a: r0) {
        cout << a << ' ';
    }
    cout << '\n';

    vector<int> r = sol.postorder(n1);
    for (int a: r) {
        cout << a << ' ';
    }
    cout << '\n';

    
    return 0;
}
