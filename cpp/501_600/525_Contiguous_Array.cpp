//
//  525_Contiguous_Array.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/5/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> um ({{0, -1}});
        int r = 0;
        for (int i = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (um.find(sum) != um.end()) {
                r = max(r, i - um[sum]);
            } else {
                um[sum] = i;
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 525. Contiguous Array, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //0,1 // 2
        0,1,2   // 2
    };

    int r = sol.findMaxLength(nums);
    cout << r << '\n';

    return 0;
}
