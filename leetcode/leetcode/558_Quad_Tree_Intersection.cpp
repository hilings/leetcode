//
//  558_Quad_Tree_Intersection.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/10/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
//#include <vector>
//#include <deque>
//#include <stack>
//#include <algorithm>
//#include <cmath>
using namespace std;

/*
 // Definition for a QuadTree node.
 */

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) { // union, really?
        if (quadTree1->isLeaf && quadTree1->val) {
            return quadTree1;
        }
        if (quadTree1->isLeaf && !quadTree1->val) {
            return quadTree2;
        }
        if (quadTree2->isLeaf && quadTree2->val) {
            return quadTree2;
        }
        if (quadTree2->isLeaf &&! quadTree2->val) {
            return quadTree1;
        }

        Node* tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* tr = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
            tl->val == tr->val && tr->val == bl->val && bl->val == br->val) {
            return new Node(tl->val, true, NULL, NULL, NULL, NULL);
        }
        return new Node(false, false, tl, tr, bl, br);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 558. Quad Tree Intersection, C++ ...\n\n";
    Solution sol;

    Node* a0 = new Node(true, true, NULL, NULL, NULL, NULL);
    Node* a1 = new Node(true, true, NULL, NULL, NULL, NULL);
    Node* a2 = new Node(false, true, NULL, NULL, NULL, NULL);
    Node* a3 = new Node(false, true, NULL, NULL, NULL, NULL);
    Node* quadTree1 = new Node(true, true, a0, a1, a2, a3);

    Node* b0 = new Node(true, true, NULL, NULL, NULL, NULL);
    Node* b10 = new Node(false, false, NULL, NULL, NULL, NULL);
    Node* b11 = new Node(false, false, NULL, NULL, NULL, NULL);
    Node* b12 = new Node(false, true, NULL, NULL, NULL, NULL);
    Node* b13 = new Node(false, true, NULL, NULL, NULL, NULL);
    Node* b1 = new Node(false, false, b10, b11, b12, b13);
    Node* b2 = new Node(true, true, NULL, NULL, NULL, NULL);
    Node* b3 = new Node(false, true, NULL, NULL, NULL, NULL);
    Node* quadTree2 = new Node(true, true, b0, b1, b2, b3);

    Node* r = sol.intersect(quadTree1, quadTree2);


    return 0;
}
