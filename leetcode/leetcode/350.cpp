//
//  350.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/13/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> um;
        for (int a: nums1) {
            um[a] = um.find(a) == um.end() ? 1 : um[a]+1;
        }
        vector<int> r;
        for (int a: nums2) {
            if (um.find(a) != um.end()) {
                r.push_back(a);
                if (--um[a] == 0) {
                    um.erase(a);
                }
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 350. Intersection of Two Arrays II, C++ ...\n\n";
    Solution sol;

    vector<int> nums1 {1,2,2,1};
    vector<int> nums2 {2,2};
    
    vector<int> r = sol.intersect(nums1, nums2);
    for (int a: r) {
        cout << a << ' ';
    }
    
    return 0;
}
