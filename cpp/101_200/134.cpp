//
//  134.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/22/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = (int)gas.size(), dpt = 0, dst = 0, tank = 0;
        while (dst - dpt < N) {
            if (tank >= 0) {
                tank += gas[dst%N] - cost[dst%N];
                dst++;
            } else {
                dpt--;
                tank += gas[N+dpt] - cost[N+dpt];
            }
        }
        return tank >= 0 ? (N+dpt) % N : -1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 134 Gas Station, C++ ...\n\n";
    Solution sol;

    //vector<int> gas {1,2,4};
    //vector<int> cost {2,3,1};
    vector<int> gas {4};
    vector<int> cost {5};
    
    int r = sol.canCompleteCircuit(gas, cost);
    cout << r << '\n';
    
    return 0;
}
