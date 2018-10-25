//
//  643_Maximum_Average_Subarray_I.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/24/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long mymax = INT_MIN, sum = accumulate(nums.begin(), nums.begin()+k-1, 0);
        for (int i = k-1; i < nums.size(); i++) {
            sum += nums[i];
            mymax = max(mymax, sum);
            sum -= nums[i-k+1];
        }
        return (double)mymax / k;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 643. Maximum Average Subarray I, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        1,12,-5,-6,50,3
    };
    int k = 4;

    double r = sol.findMaxAverage(nums, k);
    cout << r << '\n';

    return 0;
}
