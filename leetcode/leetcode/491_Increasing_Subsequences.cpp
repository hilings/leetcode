//
//  491_Increasing_Subsequences.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/5/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    void dfs(vector<int>& nums, int pos, vector<vector<int>>& r, vector<int>& seq) {
        if (seq.size() >= 2) {
            r.push_back(seq);
        }
        unordered_set<int> us;
        for (int i = pos; i < nums.size(); i++) {
            if (us.find(nums[i]) != us.end()) {
                continue;
            }
            if (seq.empty() || nums[i] >= seq.back()) {
                seq.push_back(nums[i]);
                us.insert(nums[i]);
                dfs(nums, i+1, r, seq);
                seq.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> r;
        vector<int> seq;
        dfs(nums, 0, r, seq);
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 491. Increasing Subsequences, C++ ...\n\n";
    Solution sol;

    vector<int> nums {4, 6, 7, 7};
    vector<vector<int>> r = sol.findSubsequences(nums);
    for (vector<int> v: r) {
        for (int a: v) {
            cout << a << ' ';
        }
        cout << '\n';
    }

    return 0;
}
