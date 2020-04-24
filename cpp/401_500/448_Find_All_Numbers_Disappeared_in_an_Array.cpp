//
//  448_Find_All_Numbers_Disappeared_in_an_Array.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/21/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> r;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i])-1;
            nums[index] = -abs(nums[index]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                r.push_back(i+1);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 448. Find All Numbers Disappeared in an Array, C++ ...\n\n";
    Solution sol;

    vector<int> nums {4,3,2,7,8,2,3,1};
    vector<int> r = sol.findDisappearedNumbers(nums);
    for (int a: r) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}
