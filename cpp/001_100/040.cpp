//
//  040.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/16/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v) {
    cout << "[ ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]\n";
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return solve(candidates, target, (int)candidates.size());
    }
    vector<vector<int>> solve(vector<int>& candidates, int target, int limit) {
        vector<vector<int>> v;
        if (target < candidates[0])
            return v;

        for (int i = limit-1; i >= 0; i--) {
            if (candidates[i] == target) {
                vector<int> a (1, target);
                v.push_back(a);
                limit = i;
                break;
            }
        }

        for (int i = limit-1; i >= 0; i--) {
            if (i < limit-1 && candidates[i] == candidates[i+1])
                continue;
            vector<vector<int>> tmp = solve(candidates, target-candidates[i], i);
            for (int j = 0; j < tmp.size(); j++) {
                tmp[j].push_back(candidates[i]);
                v.push_back(tmp[j]);
            }
        }
        return v;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 040 Combination Sum II, C++ ...\n\n";

    //int a[] = {3,1,3,5,1,1};
    //int target = 8;
    //int a[] = {2, 2, 2};
    //int target = 4;
    int a[] = {10,1,2,7,6,1,5};
    int target = 8;
    vector<int> candidates (a, a+sizeof(a)/sizeof(int));

    cout << "candidates = ";
    printVector(candidates);
    cout << "target = " << target << '\n';

    Solution sol;
    vector<vector<int>> v = sol.combinationSum2(candidates, target);
    for (int i = 0; i < v.size(); i++) {
        printVector(v[i]);
    }

    //printVector(candidates);

    return 0;
}