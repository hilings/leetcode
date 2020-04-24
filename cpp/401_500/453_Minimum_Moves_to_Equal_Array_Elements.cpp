//
//  453_Minimum_Moves_to_Equal_Array_Elements.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/23/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int r = 0, min = nums[0];
        for (int a: nums) {
            if (a < min) {
                min = a;
            }
        }
        for (int a: nums) {
            r += a - min;
        }
        return r;
    }
    int minMoves2(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0) - (int)nums.size() * (*min_element(nums.begin(), nums.end()));
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 453. Minimum Moves to Equal Array Elements, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,2,3};

    int r = sol.minMoves(nums);
    cout << r << '\n';

    int r2 = sol.minMoves(nums);
    cout << r2 << '\n';

    return 0;
}
