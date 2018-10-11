//
//  560_Subarray_Sum_Equals_K.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/11/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um {{0,1}};
        int sum = 0, r = 0;
        for (int a: nums) {
            sum += a;
            if (um.find(sum-k) != um.end()) {
                r += um[sum-k];
            }
            um[sum] = um.find(sum) != um.end() ? um[sum]+1 : 1;
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 560. Subarray Sum Equals K, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,1,1   // 2
        //1   // 0
        0,0,0,0,0,0,0,0,0,0
    };
    int k = 2;
    k = 0;

    int r = sol.subarraySum(nums, k);
    cout << r << '\n';

    return 0;
}

