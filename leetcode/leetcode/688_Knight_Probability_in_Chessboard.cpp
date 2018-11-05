//
//  688_Knight_Probability_in_Chessboard.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/5/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<pair<int,int>> moves {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};  // 8 possible moves
        unordered_map<int,double> um {{N*r+c,1.0}};   // position and its probability
        double prob = 1.0;
        for (int i = 0; i < K && !um.empty(); i++) {    // K
            unordered_map<int,double> next;
            prob = 0.0;
            for (pair<int,double> pos_prob: um) {   // N*N
                int x = pos_prob.first / N, y = pos_prob.first % N;
                for (pair<int,int> move: moves) {    // 8
                    int xx = x + move.first, yy = y + move.second, index = N * xx + yy;
                    if (xx >= 0 && xx < N && yy >= 0 && yy < N) {
                        if (next.find(index) == next.end()) {
                            next[index] = 0;
                        }
                        next[index] += pos_prob.second / 8.0;
                        prob += pos_prob.second / 8.0;
                    }
                }
            }
            um = next;
        }
        return prob;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 688. Knight Probability in Chessboard, C++ ...\n\n";
    Solution sol;

    int N = 3;
    int K = 2;
    int r = 0;
    int c = 0;  // 0.0625

    N = 8;
    K = 30;
    r = 6;
    c = 4;  // 0.000190526

    N = 1;
    K = 0;
    r = 0;
    c = 0;  // 1.0

    double prob = sol.knightProbability(N, K, r, c);
    cout << prob << '\n';

    return 0;
}
