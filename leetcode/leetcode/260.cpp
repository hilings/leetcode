//
//  260.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> singleNumber0(vector<int>& nums) {
        unordered_set<int> us;
        for (int a: nums) {
            if (us.find(a) == us.end())
                us.insert(a);
            else
                us.erase(a);
        }
        vector<int> ret;
        for (int a: us) {
            ret.push_back(a);
        }
        return ret;
    }

    vector<int> singleNumber(vector<int>& nums) {
        int mask = 0;
        for (int a: nums) {
            mask ^= a;
        }
        mask = mask & ~(mask-1);
        cout << mask << '\n';
        vector<int> ret (2, 0);
        for (int a: nums) {
            if (a & mask)
                ret[0] ^= a;
            else
                ret[1] ^= a;
        }

        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 260. Single Number III, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {1,2,1,3,2,5};
    
    vector<int> r = sol.singleNumber(nums);
    for (int a: r) {
        cout << a << ' ';
    }
    
    return 0;
}