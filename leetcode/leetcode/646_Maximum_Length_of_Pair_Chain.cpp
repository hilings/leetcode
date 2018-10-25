//
//  646_Maximum_Length_of_Pair_Chain.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/24/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto cmp = [] (const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        sort(pairs.begin(), pairs.end(), cmp);
        int r = 0, tail = INT_MIN;
        for (auto v: pairs) {
            if (tail < v[0]) {
                r++;
                tail = v[1];
            } else if (v[1] < tail) {
                tail = v[1];
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 646. Maximum Length of Pair Chain, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> pairs {
        {1,2},
        {2,3},
        {3,4}
    };

    int r = sol.findLongestChain(pairs);
    cout << r << '\n';

    return 0;
}
