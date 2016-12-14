//
//  349.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/13/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> r;
        unordered_set<int> us1 (nums1.begin(), nums1.end());
        for (int a: nums2) {
            if (us1.find(a) != us1.end()) {
                r.push_back(a);
                us1.erase(a);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 349. Intersection of Two Arrays, C++ ...\n\n";
    Solution sol;

    vector<int> nums1 {1,2,2,1,3};
    vector<int> nums2 {2,2,3};

    vector<int> r = sol.intersection(nums1, nums2);
    for (int a: r) {
        cout << a << ' ';
    }
    
    return 0;
}
