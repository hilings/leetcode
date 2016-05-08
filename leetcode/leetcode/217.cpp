//
//  217.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/4/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (int a: nums) {
            if (us.find(a) != us.end())
                return true;
            us.insert(a);
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 217. Contains Duplicate, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,2,3};
    bool r = sol.containsDuplicate(nums);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}