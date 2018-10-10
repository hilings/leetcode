//
//  547_Friend_Circles.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/10/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = (int)M.size(), r = 0;
        vector<bool> visited (n, false);
        vector<int> tovisit;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            tovisit.push_back(i);
            while (!tovisit.empty()) {  // loop through a circle
                int j = tovisit.back();
                tovisit.pop_back();
                visited[j] = true;
                printf("visiting %d\n", j);
                for (int k = 0; k < n; k++) {
                    if (!visited[k] && M[j][k] == 1) {
                        tovisit.push_back(k);
                    }
                }
            }
            r++;
            printf("above is a circle\n\n");
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 547. Friend Circles, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> M {
        /*
        {1,1,0},
        {1,1,0},
        {0,0,1} // 2
         */

        /*
        {1,1,0},
        {1,1,1},
        {0,1,1} // 1
         */

        {1,0,0,1},
        {0,1,1,0},
        {0,1,1,1},
        {1,0,1,1}
    };

    int r = sol.findCircleNum(M);
    cout << r << '\n';

    return 0;
}
