//
//  219.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/4/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 219. Contains Duplicate II, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,2,3,4,5,6,7};
    int k = 3;

    bool r = sol.containsNearbyDuplicate(nums, k);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}