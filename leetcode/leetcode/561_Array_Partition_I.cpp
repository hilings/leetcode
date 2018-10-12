//
//  561_Array_Partition_I.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/11/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> v (20001, 0);
        for (int a: nums) {
            v[a+10000]++;
        }
        int r = 0, k = 0;
        for (int i = 0; i < 20001; i++) {
            while (v[i]-- > 0) {
                if (k++ % 2 == 0) {
                    r += i-10000;
                }
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 561. Array Partition I, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,4,3,2 // 4
        1,2,3,2 // 3
    };

    int r = sol.arrayPairSum(nums);
    cout << r << '\n';

    return 0;
}
