//
//  713_Subarray_Product_Less_Than_K.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/14/19.
//  Copyright © 2019 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int r = 0;
        for (int a: nums) {
            unordered_map<int,int> nextum;
            for (auto kv: um) {
                if (kv.first * a < k) {
                    nextum[kv.first*a] = kv.second;
                    r += kv.second;
                }
            }
            if (a < k) {
                nextum[a]++;
                r++;
            }
            um = nextum;
        }
        return r;
    }

    int numSubarrayProductLessThanK2(vector<int>& nums, int k) {
        int r = 0;
        if (k == 0) {
            return r;
        }
        for (int i = 0, j = 0, p = 1; i < nums.size(); i++) {
            p *= nums[i];
            while (j <= i && p >= k) {
                p /= nums[j];
                j++;
            }
            r += i-j+1;
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 713. Subarray Product Less Than K, C++ ...\n\n";
    Solution sol;

    vector<int> nums {10, 5, 2, 6};
    int k = 100;
    int r = sol.numSubarrayProductLessThanK(nums, k);
    cout << r << '\n';

    int r2 = sol.numSubarrayProductLessThanK2(nums, k);
    cout << r2 << '\n';

    return 0;
}
