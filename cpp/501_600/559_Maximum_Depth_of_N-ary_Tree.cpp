//
//  559_Maximum_Depth_of_N-ary_Tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/11/18.
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
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        int h = 0;
        for (auto n: root->children) {
            h = max(h, maxDepth(n));
        }
        return h+1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 559. Maximum Depth of N-ary Tree, C++ ...\n\n";
    Solution sol;

    Node* n5 = new Node(5, {});
    Node* n6 = new Node(6, {});
    Node* n3 = new Node(3, {n5, n6});
    Node* n2 = new Node(2, {});
    Node* n4 = new Node(4, {});
    Node* n1 = new Node(1, {n3, n2, n4});

    int r = sol.maxDepth(n1);
    cout << r << '\n';

    return 0;
}
