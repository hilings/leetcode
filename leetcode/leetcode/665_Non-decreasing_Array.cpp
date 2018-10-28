    //
//  665_Non-decreasing_Array.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/27/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int max1 = nums[0], max2 = INT_MIN;
        bool e = false;     // if error occurred
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= max1) {  // fine
                max2 = max1;
                max1 = nums[i];
            } else if (e) {     // if error again
                return false;
            } else {
                e = true;       // error once
                max1 = nums[i] >= max2 ? nums[i] : max1;
            }
        }
        return true;
    }

    bool checkPossibility2(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size() && count <= 1; i++) {
            if (nums[i] < nums[i-1]) {
                count++;
                if (i-2 < 0 || nums[i] >= nums[i-2]) {
                    nums[i-1] = nums[i];    // change nums[i-1] to keep max low
                } else {    // nums[i] is less than two numbers, thus has to be changed
                    nums[i] = nums[i-1];
                }
            }
        }
        return count <= 1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 665. Non-decreasing Array, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        4,2,3       // true
        //3,4,2,3     // false
    };

    bool r = sol.checkPossibility(nums);
    cout << (r ? "true" : "false") << '\n';

    bool r2 = sol.checkPossibility2(nums);
    cout << (r2 ? "true" : "false") << '\n';

    return 0;
}
