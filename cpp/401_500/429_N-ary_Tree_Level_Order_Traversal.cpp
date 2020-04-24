//
//  429_N-ary_Tree_Level_Order_Traversal.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/10/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
 // Definition for a Node.
 */
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> r;
        if (!root) {
            return r;
        }
        deque<Node*> q {root, NULL};
        while (!q.empty()) {
            vector<int> v;
            while (q.front() != NULL) {
                v.push_back(q.front()->val);
                if (!q.front()->children.empty()) {
                    q.insert(q.end(), q.front()->children.begin(), q.front()->children.end());
                }
                q.pop_front();
            }
            q.pop_front();  // NULL the delimiter
            r.push_back(v); // nodes of the level
            if (!q.empty()) {   // if not the last level
                q.push_back(NULL);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 429. N-ary Tree Level Order Traversal, C++ ...\n\n";
    Solution sol;

    Node* n5 = new Node(5, vector<Node*> {});
    Node* n6 = new Node(6, vector<Node*> {});
    Node* n3 = new Node(3, vector<Node*> {n5, n6});
    Node* n2 = new Node(2, vector<Node*> {});
    Node* n4 = new Node(4, vector<Node*> {});
    Node* n1 = new Node(1, vector<Node*> {n3, n2, n4});

    vector<vector<int>> r = sol.levelOrder(n1);
    for (auto v: r) {
        for (int a: v) {
            cout << a << ' ';
        }
        cout << '\n';
    }

    return 0;
}
