//
//  698_Partition_to_K_Equal_Sum_Subsets.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/8/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
    bool dfs(vector<int>& nums, vector<bool>& visited, int k, int index, int sum, int target) {
        if (k == 1) {
            return true;
        }
        if (sum == target) {
            return dfs(nums, visited, k-1, 0, 0, target);
        }
        for (int i = index; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            if (sum + nums[i] <= target) {
                visited[i] = true;
                if (dfs(nums, visited, k, i+1, sum + nums[i], target)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum / k;
        if (sum % k != 0) {
            return false;
        }
        for (int a: nums) {
            if (a > target) {
                return false;
            }
        }
        vector<bool> visited (nums.size(), false);
        return dfs(nums, visited, k, 0, 0, target);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 698. Partition to K Equal Sum Subsets, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //4, 3, 2, 3, 5, 2, 1   // true
        114,96,18,190,207,111,73,471,99,20,1037,700,295,101,39,649  //
    };
    int k = 4;

    bool z = sol.canPartitionKSubsets(nums, k);
    cout << (z ? "true" : "false") << '\n';

    return 0;
}
