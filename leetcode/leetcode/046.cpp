//
//  046.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/29/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printV(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        if (nums.size() == 0)
            return v;
        v.push_back(vector<int> {nums[0]});
        int i;
        for (i = 0; v[i].size() < nums.size(); i++) {
            int k = nums[v[i].size()];
            for (int j = 0; j <= v[i].size(); j++) {
                vector<int> a (v[i]);
                if (j < v[i].size() && k == a[j])
                    continue;
                a.insert(a.begin()+j, k);
                v.push_back(a);
            }
        }
        v.erase(v.begin(), v.begin()+i);
        for (i = 0; i < v.size(); i++) {
            printV(v[i]);
        }
        return v;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 046 Permutations, C++ ...\n\n";

    vector<int> nums {1,2,2};
    //printV(nums);

    Solution sol;
    sol.permute(nums);

    return 0;
}