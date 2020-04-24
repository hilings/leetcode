//
//  488_Zuma_Game.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/5/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    string collapse(string board) {
        while (!board.empty()) {
            cout << board << " => ";
            int i, j, size = (int)board.size();
            for (i = 0; i < board.size()-2; i = j) {
                for (j = i+1; j < board.size() && board[j] == board[i]; j++);
                if (j-i >= 3) {
                    board.erase(i, j-i);
                    cout << board << '\n';
                    break;
                }
            }
            if (board.size() == size) {
                break;
            }
        }
        return board;
    }
public:
    int findMinStep(string board, string hand) {
        // Leetcode test case has mistake, skip for now
        cout << collapse(board);
        return 0;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 488. Zuma Game, C++ ...\n\n";
    Solution sol;

    string board = "WWRRBBWW";
    string hand = "WRBRW";
    /*
    board = "RRWWRRBBRR";
    hard = "WB";   // expected -1, which is wrong, should be 2
     */
    int r = sol.findMinStep(board, hand);
    cout << r << '\n';

    return 0;
}
