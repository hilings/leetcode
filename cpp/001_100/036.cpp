//
//  036.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/11/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void printBoard(vector<vector<char>> board) {
    cout << '\n';
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            cout << board[i][j] << ' ';
            if (j%3 == 2)
                cout << "  ";
        }
        cout << '\n';
        if (i%3 == 2)
            cout << '\n';
    }
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> set1, set2, set3;
        for (int i = 0; i < 9; i++) {
            set1.clear();
            set2.clear();
            set3.clear();
            for (int j = 0; j < 9; j++) {
                //cout << "[" << i << ", " << j << "]\n";
                char c = board[i][j];   //  check row
                if (c != '.' && !set1.insert(c).second)
                    return false;

                //cout << "[" << j << ", " << i << "]\n";
                c = board[j][i];    //  check column
                if (c != '.' && !set2.insert(c).second)
                    return false;

                //cout << "[" << i/3*3 + j/3 << ", " << i%3*3 + j%3 << "]\n";
                c = board[i/3*3 + j/3][i%3*3 + j%3];    //  check block
                if (c != '.' && !set3.insert(c).second)
                    return false;
            }
        }
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 036 Valid Sudoku, C++ ...\n\n";

    char c[][10] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
     };

    vector<vector<char>> board;
    for (int i = 0; i < 9; i++) {
        vector<char> v (c[i], c[i]+9);
        board.push_back(v);
    }

    printBoard(board);

    Solution sol;
    bool result = sol.isValidSudoku(board);
    cout << (result ? "true" : "false");

    return 0;
}