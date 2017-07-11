//
//  419_battleships_in_a_board.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/11/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.' || (i-1>=0 && board[i-1][j] == 'X')) {
                    continue;
                }
                count++;
                while (j+1 < board[0].size() && board[i][j+1] == 'X') {
                    j++;
                }
            }
        }
        return count;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 419. Battleships in a Board, C++ ...\n\n";
    Solution sol;

    vector<vector<char>> board {
        {'X', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'}
    };
    
    int r = sol.countBattleships(board);
    cout << r << '\n';
    
    return 0;
}
