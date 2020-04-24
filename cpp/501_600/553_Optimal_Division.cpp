//
//  553_Optimal_Division.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/10/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) {
            return to_string(nums[0]);
        }
        if (n == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        string r = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for (int i = 2; i < n; i++) {
            r += "/" + to_string(nums[i]);
        }
        r += ")";
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 553. Optimal Division, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        1000,100,10,2   // "1000/(100/10/2)"
    };

    string r = sol.optimalDivision(nums);
    cout << r << '\n';

    return 0;
}
