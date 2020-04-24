//
//  037.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/12/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
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

char *binaryToStr(int a) {
    char *str = new char[10];
    for (int i = 1; i <= 9; i++)
        str[i-1] = (a >> i & 1) == 1 ? '0'+i : ' ';
    str[9] = '\0';
    return str;
}

class Solution {
private:
    vector<int> candidate;

public:
    void solveSudoku(vector<vector<char>>& board) {
        printBoard(board);
        solve(board, 0);
        printBoard(board);
        return;
    }
    bool solve(vector<vector<char>>& board, int co) {
        if (co == 81)
            return true;
        int i = co / 9, j = co % 9;
        if (board[i][j] != '.')
            return solve(board, co+1);
        
        for (int k = 1; k <= 9; k++)
            if (isValid(board, co, '0'+k)) {
                board[i][j] = '0'+k;
                if (solve(board, co+1))
                    return true;
                else
                    board[i][j] = '.';
            }
        return false;
    }
    bool isValid(vector<vector<char>>& board, int co, char value) {
        int i = co / 9, j = co % 9;
        for (int k = 0; k < 9; k++)
            if (board[i][k] == value || board[k][j] == value || board[i/3*3+k/3][j/3*3+k%3] == value)
                return false;
        return true;
    }


    // like human
    void solveSudoku2(vector<vector<char>>& board) {
        printBoard(board);
        for (int co = 0; co < 81; co++) {
            candidate.push_back(0);
            if (board[co/9][co%9] == '.') {
                for (int d = 1; d <= 9; d++) {
                    if (isValid(board, co, '0'+d))
                        candidate[co] |= 1 << d;
                }
            }
            if (candidate[co] > 0) {
                //printf("%d %d = [%s]\n", i, j, binaryToStr(candidate[co]));
            }
        }

        int u = uniqueCandidate();
        while (u > -1) {
            printf("unique candidate cell: %d %d <- %d\n", u/9, u%9, binaryToInt(candidate[u]));
            int i = u / 9, j = u % 9, d = binaryToInt(candidate[u]);
            board[i][j] = '0'+d;
            for (int k = 0; k < 9; k++) {
                candidate[9*i+k] &= ~(1<<d);
                candidate[9*k+j] &= ~(1<<d);
                candidate[9*(i/3*3+k/3) + (j/3*3+k%3)] &= ~(1<<d);
            }
            u = uniqueCandidate();
        }

        for (int co = 0; co < 81; co++) {
            int i = co / 9, j = co % 9;
            if (candidate[co] > 0) {
                printf("%d %d = [%s]\n", i, j, binaryToStr(candidate[co]));
            }
        }

        solve(board, 0);
        printBoard(board);
        return;
    }
    int uniqueCandidate() {
        for (int co = 0; co < 81; co++) {
            int d = candidate[co];
            if (d == 0)
                continue;
            while ((d & 1) == 0)
                d = d >> 1;
            if (d == 1)
                return co;
        }
        return -1;
    }
    int binaryToInt(int a) {
        for (int i = 1; i <= 9; i++) {
            if ((a>>i) == 1)
                return i;
        }
        return 0;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 037 Sudoku Solver, C++ ...\n\n";
    
    /*
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
     //*/
    
    char c[][10] = {
        "..9748...",
        "7........",
        ".2.1.9...",
        "..7...24.",
        ".64.1.59.",
        ".98...3..",
        "...8.3.2.",
        "........6",
        "...2759.."
    };
    /*
     5 1 9   7 4 8   6 3 2
     7 8 3   6 5 2   4 1 9
     4 2 6   1 3 9   8 7 5
     
     3 5 7   9 8 6   2 4 1
     2 6 4   3 1 7   5 9 8
     1 9 8   5 2 4   3 6 7
     
     9 7 5   8 6 3   1 2 4
     8 3 2   4 9 1   7 5 6
     6 4 1   2 7 5   9 8 3
     */
    
    vector<vector<char>> board;
    for (int i = 0; i < 9; i++) {
        vector<char> v (c[i], c[i]+9);
        board.push_back(v);
    }
    
    Solution sol;
    sol.solveSudoku2(board);
    
    return 0;
}