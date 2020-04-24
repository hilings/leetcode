//
//  414_third_maximum_number.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/6/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> myset;
        for (int a: nums) {
            if (myset.find(a) == myset.end()) {
                myset.insert(a);
                if (myset.size() > 3) {
                    myset.erase(myset.begin());
                }
            }
        }
        return myset.size() == 3 ? *(myset.begin()) : *(myset.rbegin());
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 414. Third Maximum Number, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,2,3	// 1
        2,2,3,1	// 1
        //2,2,3,2	// 3
    };
    int r = sol.thirdMax(nums);
    cout << r << '\n';
    
    return 0;
}
