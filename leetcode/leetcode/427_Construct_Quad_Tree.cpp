//
//  427_Construct_Quad_Tree.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/9/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
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
    Node* construct0(vector<vector<int>>& grid) {
        Node* r = NULL;
        int N = (int)grid.size();
        //printf("N = %d\n", N);
        if (N == 0) {
        } else if (N == 1) {
            r = new Node(grid[0][0] == 1, true, NULL, NULL, NULL, NULL);
        } else {
            vector<vector<int>> gridTopLeft;
            vector<vector<int>> gridTopRight;
            vector<vector<int>> gridBottomLeft;
            vector<vector<int>> gridBottomRight;
            for (int i = 0; i < N/2; i++) {
                gridTopLeft.push_back(vector<int> (grid[i].begin(), grid[i].begin()+N/2));
                gridTopRight.push_back(vector<int> (grid[i].begin()+N/2, grid[i].end()));
                gridBottomLeft.push_back(vector<int> (grid[N/2+i].begin(), grid[N/2+i].begin()+N/2));
                gridBottomRight.push_back(vector<int> (grid[N/2+i].begin()+N/2, grid[N/2+i].end()));
            }

            Node* topLeft = construct0(gridTopLeft);
            Node* topRight = construct0(gridTopRight);
            Node* bottomLeft = construct0(gridBottomLeft);
            Node* bottomRight = construct0(gridBottomRight);

            bool isLeaf = topLeft->isLeaf &&
                            topRight->isLeaf &&
                            bottomLeft->isLeaf &&
                            bottomRight->isLeaf &&
                            topLeft->val == topRight->val &&
                            topRight->val == bottomLeft->val &&
                            bottomLeft->val == bottomRight->val;
            bool val = isLeaf ? topLeft->val : false;

            r = new Node(val, isLeaf,
                         isLeaf ? NULL : topLeft,
                         isLeaf ? NULL : topRight,
                         isLeaf ? NULL : bottomLeft,
                         isLeaf ? NULL : bottomRight);
        }
        return r;
    }

    Node* construct(vector<vector<int>>& grid) {
        Node* r = makeNode(grid, 0, 0, (int)grid.size());
        return r;
    }

    Node* makeNode(vector<vector<int>>& grid, int row, int col, int N) {
        Node* r = NULL;
        if (N == 0) {
            return r;
        } else if (N == 1){
            r = new Node(grid[row][col] == 1, true, NULL, NULL, NULL, NULL);
        } else {
            Node* topLeft = makeNode(grid, row, col, N/2);
            Node* topRight = makeNode(grid, row, col+N/2, N/2);
            Node* bottomLeft = makeNode(grid, row+N/2, col, N/2);
            Node* bottomRight = makeNode(grid, row+N/2, col+N/2, N/2);
            bool isLeaf = topLeft->isLeaf &&
                        topRight->isLeaf &&
                        bottomLeft->isLeaf &&
                        bottomRight->isLeaf &&
                        topLeft->val == topRight->val &&
                        topRight->val == bottomLeft->val &&
                        bottomLeft->val == bottomRight->val;
            bool val = isLeaf ? topLeft->val : false;
            if (isLeaf) {
                delete topLeft;
                topLeft = NULL;
                delete topRight;
                topRight = NULL;
                delete bottomLeft;
                bottomLeft = NULL;
                delete bottomRight;
                bottomRight = NULL;
            }

            r = new Node(val, isLeaf, topLeft, topRight, bottomLeft, bottomRight);
        }
        return r;
    }

    void printN(Node* node) {
        if (!node) {
            printf("empty\n");
            return;
        }
        printf("isLeaf = %s, val = %s\n",
                (node->isLeaf ? "true" : "false"),
                (node->val ? "true" : "false"));
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "427. Construct Quad Tree, C++ ...\n\n";
    Solution sol;
    vector<vector<int>> grid {
        //vector<int> {1}

        vector<int> {1,1,1,1,0,0,0,0},
        vector<int> {1,1,1,1,0,0,0,0},
        vector<int> {1,1,1,1,1,1,1,1},
        vector<int> {1,1,1,1,1,1,1,1},
        vector<int> {1,1,1,1,0,0,0,0},
        vector<int> {1,1,1,1,0,0,0,0},
        vector<int> {1,1,1,1,0,0,0,0},
        vector<int> {1,1,1,1,0,0,0,0}
        // */
    };

    Node* r0 = sol.construct0(grid);

    sol.printN(r0);
    /*
    sol.printN(r0->topLeft);
    sol.printN(r0->topRight);
    sol.printN(r0->topRight->topLeft);
    sol.printN(r0->topRight->topRight);
    sol.printN(r0->topRight->bottomLeft);
    sol.printN(r0->topRight->bottomRight);
    sol.printN(r0->bottomLeft);
    sol.printN(r0->bottomRight);
     */

    cout << '\n';

    Node* r = sol.construct(grid);
    sol.printN(r);

    return 0;
}
