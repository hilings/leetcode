//
//  697_Degree_of_an_Array.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/7/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxCount = 0, z = INT_MAX;
        unordered_map<int,pair<int,int>> um;
        for (int i = 0; i < nums.size(); i++) {
            if (um.find(nums[i]) == um.end()) {
                um[nums[i]] = pair<int,int> (0, i);
            }
            um[nums[i]].first++;
            if (um[nums[i]].first > maxCount) {
                maxCount = um[nums[i]].first;
                z = i-um[nums[i]].second+1;
            } else if (um[nums[i]].first == maxCount) {
                z = min(z, i-um[nums[i]].second+1);
            }
        }
        return z;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 697. Degree of an Array, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1, 2, 2, 3, 1   // 2
        1,2,2,3,1,4,2   // 6
    };

    int z = sol.findShortestSubArray(nums);
    cout << z << '\n';

    return 0;
}
