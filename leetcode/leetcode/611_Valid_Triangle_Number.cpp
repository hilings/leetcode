//
//  611_Valid_Triangle_Number.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/19/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int r = 0;
        for (int i = 2; i < nums.size(); i++) {
            for (int j = 0, k = i-1; j < k; ) {
                if (nums[j] + nums[k] > nums[i]) {
                    r += k-j;
                    k--;
                } else {
                    j++;
                }
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 611. Valid Triangle Number, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        2,2,3,4 // 3
    };

    int r = sol.triangleNumber(nums);
    cout << r << '\n';

    return 0;
}
