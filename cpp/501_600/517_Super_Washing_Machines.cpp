//
//  517_Super_Washing_Machines.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/2/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0), n = (int)machines.size();
        if (sum % n != 0) {
            return -1;
        }
        int target = sum / n, r = abs(machines[n-1] - target);
        for (int i = 0, cur = 0, next = 0; i < n-1; i++) {
            int k = machines[i] - target;   // positive means giving, negative means receiving
            cur = next > 0 && k > 0 ? next + k : max(abs(next), abs(k));
            r = max(r, cur);
            next = -k;
            machines[i+1] += k;
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 517. Super Washing Machines, C++ ...\n\n";
    Solution sol;

    vector<int> machines {
        //1,0,5   // 3
        //0,3,0   // 2
        //0,2,0   // -1
        9,1,8,8,9   // 4
    };

    int r = sol.findMinMoves(machines);
    cout << r << '\n';

    return 0;
}
