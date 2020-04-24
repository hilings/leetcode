//
//  20181107_grab1_2sum.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/7/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solution2(vector<int>& v) {
        int z = INT_MAX;
        sort(v.begin(), v.end());   // O(n*logn)
        for (int i = 0, j = (int)v.size()-1; i <= j; ) {
            int sum = v[i]+v[j];
            z = min(z, abs(sum));
            if (sum > 0) {
                j--;
            } else if (sum < 0) {
                i++;
            } else {
                return 0;
            }
        }
        return z;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 000 XXX, C++ ...\n\n";
    Solution sol;

    vector<int> v {
        // 1, 4, -3 //
        -8, 4, 5, -10, 3    // 3
    };

    int z = sol.solution2(v);
    cout << z << '\n';

    return 0;
}
