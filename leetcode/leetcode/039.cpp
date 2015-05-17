//
//  039.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/16/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return solve(candidates, target, (int)candidates.size()-1);
    }
    vector<vector<int>> solve(vector<int>& candidates, int target, int limit) {
        vector<vector<int>> v;
        if (target < candidates[0])
            return v;

        for (int i = 0; i <= limit; i++) {
            if (candidates[i] == target) {
                vector<int> a (1, target);
                v.push_back(a);
                break;
            }
        }

        for (int i = 0; i <= limit; i++) {
            if (candidates[i] == target)
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
    cout << "LeetCode 039 Combination Sum, C++ ...\n\n";

    int a[] = {1,2,3};
    vector<int> candidates (a, a+sizeof(a)/sizeof(int));
    int target = 6;

    cout << "candidates = ";
    printVector(candidates);
    cout << "target = " << target << '\n';

    Solution sol;
    vector<vector<int>> v = sol.combinationSum(candidates, target);
    for (int i = 0; i < v.size(); i++) {
        printVector(v[i]);
    }

    //printVector(candidates);

    return 0;
}