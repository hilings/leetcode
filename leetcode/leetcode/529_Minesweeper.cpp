//
//  529_Minesweeper.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/6/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        expand(board, click[0], click[1]);
        return board;
    }
    void expand(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
        } else if (board[row][col] == 'E') {
            int c = count(board, row, col);
            if (c >= 1) {
                board[row][col] = '0' + c;
            } else {
                board[row][col] = 'B';
                for (int i = max(row-1, 0); i <= min(row+1, (int)board.size()-1); i++) {
                    for (int j = max(col-1, 0); j <= min(col+1, (int)board[0].size()-1); j++) {
                        expand(board, i, j);
                    }
                }
            }
        }
    }

    int count(vector<vector<char>>& board, int row, int col) {
        int r = 0;
        for (int i = max(row-1, 0); i <= min(row+1, (int)board.size()-1); i++) {
            for (int j = max(col-1, 0); j <= min(col+1, (int)board[0].size()-1); j++) {
                if (board[i][j] == 'M') {
                    r++;
                }
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 529. Minesweeper, C++ ...\n\n";
    Solution sol;

    vector<vector<char>> board {
        /*
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}
         */

        {'B', '1', 'E', '1', 'B'},
        {'B', '1', 'M', '1', 'B'},
        {'B', '1', '1', '1', 'B'},
        {'B', 'B', 'B', 'B', 'B'}

    };
    vector<int> click {
        //3,0
        1,2
    };
    for (auto v: board) {
        for (char c: v) {
            cout << c << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    vector<vector<char>> expected {
        /*
        {'B', '1', 'E', '1', 'B'},
        {'B', '1', 'M', '1', 'B'},
        {'B', '1', '1', '1', 'B'},
        {'B', 'B', 'B', 'B', 'B'}
         */
        {'B', '1', 'E', '1', 'B'},
        {'B', '1', 'X', '1', 'B'},
        {'B', '1', '1', '1', 'B'},
        {'B', 'B', 'B', 'B', 'B'}
    };
    for (auto v: expected) {
        for (char c: v) {
            cout << c << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    vector<vector<char>> r = sol.updateBoard(board, click);
    for (auto v: r) {
        for (char c: v) {
            cout << c << ' ';
        }
        cout << '\n';
    }

    return 0;
}
