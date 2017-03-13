//
//  377.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/9/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> cache;
public:
    int combinationSum4(vector<int>& nums, int target) {	// dp, top-down
        if (cache.empty()) {
            cache.push_back(1);
            cache.insert(cache.end(), target, -1);
        }
        if (cache[target] != -1)
            return cache[target];

        //cout << "target = " << target << '\n';

        int count = 0;
        for (int a: nums) {
            if (a <= target) {
                count += combinationSum4(nums, target-a);
            }
        }
        cache[target] = count;
        return count;
    }

    int combinationSum42(vector<int>& nums, int target) {	// dp, bottom-up
        vector<int> cache2 (target+1, 0);
        cache2[0] = 1;
        for (int k = 1; k <= target; k++) {
            for (int a: nums) {
                if (a <= k) {
                    cache2[k] += cache2[k-a];
                }
            }
            //cout << "target " << i << ": " << cache2.back() << '\n';
        }
        return cache2[target];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 377. Combination Sum IV, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {1,2,3};
    int target = 4;
    
    int r = sol.combinationSum4(nums, target);
    cout << r << '\n';
    
    int r2 = sol.combinationSum42(nums, target);
    cout << r2 << '\n';
    
    return 0;
}
