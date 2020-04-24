//
//  645_Set_Mismatch.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/24/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {  // sort by swapping
        vector<int> r;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]); // swap to where it belongs
            }
            if (nums[i] != i+1) {   // if still out of position
                r = vector<int> {nums[i], i+1}; // this one is duplicated, and index indicates the temporary missing
            }
        }
        return r;
    }

    vector<int> findErrorNums2(vector<int>& nums) { // flip sign
        vector<int> r (2, 0);
        for (int& a: nums) {
            if (nums[abs(a)-1] < 0) {   // flipped already, means duplicated
                r[0] = abs(a);
            } else {
                nums[abs(a)-1] = -nums[abs(a)-1];   // flip it
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {  // never flipped, means missing
                r[1] = i+1;
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 645. Set Mismatch, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,2,2,4 // 2,3
        8,7,3,5,3,6,1,4 // 3,2
    };

    vector<int> r = sol.findErrorNums(nums);
    for (int a: r) {
        cout << a << ' ';
    }
    cout << '\n';

    vector<int> r2 = sol.findErrorNums2(nums);
    for (int a: r2) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}
