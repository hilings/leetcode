//
//  152.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/3/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct0(vector<int>& nums) {
        int ret = nums[0], pos = max(nums[0], 0), neg = min(nums[0], 0);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) {
                pos = max(pos*nums[i], nums[i]);
                neg = min(neg, neg*nums[i]);
            } else if (nums[i] < 0 ) {
                int tmp = min(pos*nums[i], nums[i]);
                pos = max(neg*nums[i], nums[i]);
                neg = tmp;
            } else {
                pos = 0;
                neg = 0;
            }
            ret = max(ret, pos);
        }
        return ret;
    }

    int maxProduct(vector<int>& nums) {
        int ret = nums[0], pos = nums[0], neg = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmp = pos;
            pos = max(nums[i], max(pos*nums[i], neg*nums[i]));
            neg = min(nums[i], min(tmp*nums[i], neg*nums[i]));
            ret = max(ret, pos);
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 152. Maximum Product Subarray, C++ ...\n\n";
    Solution sol;
    
    //vector<int> nums {2,3,-2,4};
    //vector<int> nums {-2, 3, -4};
    vector<int> nums {2,-5,-2,-4,3};
    //vector<int> nums {-2};
    
    int r = sol.maxProduct(nums);
    cout << r << '\n';
    
    return 0;
}