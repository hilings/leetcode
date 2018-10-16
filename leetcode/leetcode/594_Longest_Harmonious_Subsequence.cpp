//
//  594_Longest_Harmonious_Subsequence.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/15/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> om;
        for (int a: nums) {
            om[a] = om.find(a) != om.end() ? om[a]+1 : 1;
        }
        int r = 0;
        for (auto it = om.begin(), jt = om.begin(); it != om.end(); jt = it, it++) {
            if (it->first - jt->first == 1) {
                r = max(r, jt->second + it->second);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 594. Longest Harmonious Subsequence, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        1,3,2,2,5,2,3,7 // 5
        //1,1,1,1 // 0
        //1,3,5,7,9,11,13,15,17  // 0
    };

    int r = sol.findLHS(nums);
    cout << r << '\n';

    return 0;
}
