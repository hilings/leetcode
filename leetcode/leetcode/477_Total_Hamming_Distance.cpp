//
//  477_Total_Hamming_Distance.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/3/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int r = 0, n = (int)nums.size();
        for (int i = 0; i < 31; i++) {
            int c1 = 0;
            for (int a: nums) {
                if (a & (1<<i)) {
                    c1++;
                }
            }
            r += c1 * (n-c1);
        }
        return r;
    }
    
    int totalHammingDistance2(vector<int>& nums) {
        vector<int> v0 (31, 0), v1 (31, 0);
        for (int a: nums) {
            for (int i = 0; i < 31; i++) {
                a&(1<<i) ? v1[i]++ : v0[i]++;
            }
        }
        int r = 0;
        for (int i = 0; i < 31; i++) {
            r += v0[i] * v1[i];
        }
        return r;
    }
    void pb(int a) {
        for (int i = 30; i >= 0; i--) {
            cout << (a & (1<<i) ? 1 : 0);
        }
        cout << '\n';
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 477. Total Hamming Distance, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //4, 14, 2    // 6
        1337,7331   // 7
    };

    int r = sol.totalHammingDistance(nums);
    cout << r << '\n';

    int r2 = sol.totalHammingDistance2(nums);
    cout << r2 << '\n';

    return 0;
}
