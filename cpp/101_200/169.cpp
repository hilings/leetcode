//
//  169.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/9/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++) {
            count += maj == nums[i] ? 1 : -1;
            if (count == 0) {
                maj = nums[i];
                count = 1;
            }
        }
        return maj;
    }

    int majorityElement0(vector<int>& nums) {
        unordered_map<int,int> um;
        for (int a: nums) {
            if (um.find(a) == um.end()) {
                um[a] = 1;
            } else {
                um[a]++;
            }
            if (um[a] > nums.size()/2)
                return a;
        }
        return nums[0];
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 169. Majority Element, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {1,2,3,2,2};
    int r = sol.majorityElement(nums);
    cout << r << '\n';
    
    return 0;
}