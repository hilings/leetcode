//
//  289.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/25/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void next(vector<vector<int>>& board, int row, int col) {
        int m = (int)board.size(), n = (int)board[0].size(), count = 0;
        for (int i = row-1; i <= row+1; i++) {
            for (int j = col-1; j <= col+1; j++) {
                if (i < 0 || i == m || j < 0 || j == n || (i == row && j == col))
                    continue;
                if (board[i][j] & 1)
                    count++;
            }
        }
        if (board[row][col] == 0 && count == 3)
            board[row][col] = 2;
        if (board[row][col] == 1 && (count < 2 || count > 3))
            board[row][col] = 3;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = (int)board.size(), n = (int)board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                next(board, i, j);
            }
        }
        for (int i = 0; i < m; i++) {	// refresh
            for (int j = 0; j < n; j++) {
                if (board[i][j] >= 2)
                    board[i][j] = 3 - board[i][j];
            }
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 289. Game of Life, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> board {
        vector<int> {0,0,1,1},
        vector<int> {1,1,0,0},
        vector<int> {0,1,1,1},
        vector<int> {1,1,0,1}
    };
    
    sol.gameOfLife(board);
    
    for (vector<int> v: board) {
        for (int a: v) {
            cout << a << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    
    return 0;
}