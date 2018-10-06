//
//  523_Continuous_Subarray_Sum.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/5/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (n <= 1) {
            return false;
        }
        if (k == 0) {
            for (int i = 1; i < n; i++) {
                if (nums[i] == 0 && nums[i-1] == 0) {
                    return true;
                }
            }
            return false;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            int a = nums[i] % k;
            for (int j = 0; j < i; j++) {
                int t = (q.front()+a) % k;
                q.pop();
                if (t == 0) {
                    return true;
                } else {
                    q.push(t);
                }
            }
            q.push(a);
        }
        return false;
    }
    bool checkSubarraySum2(vector<int>& nums, int k) {
        unordered_map<int,int> um ({{0, -1}});
        for (int i = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k != 0) {
                sum %= k;
            }
            if (um.find(sum) == um.end()) {
                um[sum] = i;
            } else if (i - um[sum] > 1) {
                return true;
            }
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 523. Continuous Subarray Sum, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //23, 2, 4, 6, 7  //
        0,0 // true
    };
    int k = 6;
    k = -1;

    bool r = sol.checkSubarraySum(nums, k);
    cout << (r ? "true" : "false") << '\n';

    bool r2 = sol.checkSubarraySum2(nums, k);
    cout << (r2 ? "true" : "false") << '\n';

    return 0;
}
