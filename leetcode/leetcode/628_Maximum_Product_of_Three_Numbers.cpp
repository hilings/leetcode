//
//  628_Maximum_Product_of_Three_Numbers.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/21/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
        for (int a: nums) {
            if (a >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = a;
            } else if (a >= max2) {
                max3 = max2;
                max2 = a;
            } else if (a >= max3) {
                max3 = a;
            }
            if (a <= min1) {
                min2 = min1;
                min1 = a;
            } else if (a <= min2) {
                min2 = a;
            }
        }
        return max(max1*max2*max3, max1*min1*min2);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 628. Maximum Product of Three Numbers, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,2,3   // 6
        1,2,3,4 // 24
    };

    int r = sol.maximumProduct(nums);
    cout << r << '\n';

    return 0;
}
