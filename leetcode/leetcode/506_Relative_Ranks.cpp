//
//  506_Relative_Ranks.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/27/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> sorted (nums);
        sort(sorted.begin(), sorted.end());
        vector<string> r;
        for (int a: nums) {
            auto index = sorted.end() - lower_bound(sorted.begin(), sorted.end(), a);
            string s;
            switch (index) {
                case 1:
                    s = "Gold Medal";
                    break;
                case 2:
                    s = "Silver Medal";
                    break;
                case 3:
                    s = "Bronze Medal";
                    break;
                default:
                    s = to_string(index);
            }
            r.push_back(s);
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 506. Relative Ranks, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        5,4,3,2,1
    };

    vector<string> r = sol.findRelativeRanks(nums);
    for (auto s: r) {
        cout << s << '\n';
    }

    return 0;
}

