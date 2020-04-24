//
//  410_split_array_largest_sum.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/5/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool isValid(vector<int>& nums, int m, int limit) {
        // is it possible to divide array into m sub-arrays, sum of each sub-array is less than or equal to limit
        int _sum = 0;
        for (int a: nums) {
            if (a > limit) {	// individual item too big
                return false;
            } else if (_sum + a <= limit) {	// include this item
                _sum += a;
            } else {	// another subarray
                m--;
                if (m == 0) {	// have to divide into more than m sub-arrays, because limit is too small
                    return false;
                }
                _sum = a;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int lower = 0, upper = 0;
        for (int a: nums) {
            lower = max(lower, a);
            upper += a;
        }
        while (lower < upper) {
            int mid = lower + (upper - lower) / 2;
            if (isValid(nums, m, mid)) {
                upper = mid;
            } else {
                lower = mid+1;
            }
        }
        return lower;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 410. Split Array Largest Sum, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {7,2,5,10,8};
    int m = 2;
    int r = sol.splitArray(nums, m);
    cout << r << '\n';
    
    return 0;
}
