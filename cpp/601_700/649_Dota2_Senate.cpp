//
//  649_Dota2_Senate.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/25/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        vector<queue<int>> q (2, queue<int> {});
        int n = (int)senate.size(), p = 0;
        for (int i = 0; i < senate.size(); i++) {
            p = senate[i] == 'R' ? 0 : 1;   // Radient = 0, Dire = 1
            q[p].push(i);
        }
        while (!q[0].empty() && !q[1].empty()) {
            p = q[0].front() < q[1].front() ? 0 : 1;
            int index = min(q[0].front(), q[1].front());
            q[0].pop();
            q[1].pop();
            q[p].push(index+n);
        }
        return p == 0 ? "Radiant" : "Dire";
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 649. Dota2 Senate, C++ ...\n\n";
    Solution sol;

    string senate = "RD";   // Radiant
    senate = "RDD"; // Dire

    string r = sol.predictPartyVictory(senate);
    cout << r << '\n';

    return 0;
}
