//
//  303.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/16/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
    vector<int> sumi;
public:
    NumArray(vector<int> &nums) {
        sumi.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            sumi.push_back(sumi[i]+nums[i]);
        }
    }

    int sumRange(int i, int j) {
        cout << sumi[j+1] - sumi[i] << '\n';
        return sumi[j+1] - sumi[i];
    }
};



int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 303. Range Sum Query - Immutable, C++ ...\n\n";

    // Your NumArray object will be instantiated and called as such:
    vector<int> nums {-2, 0, 3, -5, 2, -1};

    NumArray numArray(nums);

    numArray.sumRange(0, 2);	// 1
    numArray.sumRange(2, 5);	// -1
    numArray.sumRange(0, 5);	// -3

    numArray.sumRange(0, 1);    // -2
    numArray.sumRange(1, 2);    // 3
    
    return 0;
}