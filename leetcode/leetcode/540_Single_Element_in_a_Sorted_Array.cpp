//
//  540_Single_Element_in_a_Sorted_Array.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/9/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int binarySearch(vector<int>& nums, int i, int j) {
        if (i+1 == j) {
            return nums[i];
        }
        int m = (i+j) / 2;
        if (nums[m] == nums[m-1]) {
            m++;
        }
        return (m-i) % 2 == 1 ? binarySearch(nums, i, m) : binarySearch(nums, m, j);
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        return binarySearch(nums, 0, (int)nums.size());
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 540. Single Element in a Sorted Array, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,1,2,3,3,4,4,8,8   // 2
        3,3,7,7,10,11,11    // 10
    };
    int r = sol.singleNonDuplicate(nums);
    cout <<r << '\n';

    return 0;
}
