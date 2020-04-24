//
//  532_K-diff_Pairs_in_an_Array.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/8/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        unordered_set<int> us, found;
        for (int a: nums) {
            if (us.find(a+k) != us.end()) {
                found.insert(a);
            }
            if (us.find(a-k) != us.end()) {
                found.insert(a-k);
            }
            us.insert(a);
        }
        return (int)found.size();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 532. K-diff Pairs in an Array, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //3, 1, 4, 1, 5
        //1, 2, 3, 4, 5   // 1
        1, 3, 1, 5, 4   // 1
    };
    int k = 2;
    k = 4;
    k = 0;

    int r = sol.findPairs(nums, k);
    cout << r << '\n';
    
    return 0;
}
