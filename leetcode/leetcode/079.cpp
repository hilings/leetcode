//
//  079.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/5/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (solve(board, i, j, word))
                    return true;
        return false;
    }

    bool solve(vector<vector<char>>& board, int i, int j, string s) {
        if (s.empty())
            return true;
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] != s[0])
            return false;
        board[i][j] = ' ';
        string ss = s.substr(1);
        if (solve(board, i-1, j, ss) || solve(board, i+1, j, ss) || solve(board, i, j-1, ss) || solve(board, i, j+1, ss))
            return true;
        board[i][j] = s[0];
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 079 Word Search, C++ ...\n\n";
    Solution sol;

    vector<vector<char>> board {
        vector<char> {'A','B','C','E'},
        vector<char> {'S','F','C','S'},
        vector<char> {'A','D','E','E'}
    };
    string word = "ABCCED";
    
    bool r = sol.exist(board, word);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}