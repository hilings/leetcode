//
//  128.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/16/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us (nums.begin(), nums.end());
        int longest = 0;
        for (auto a: us) {
            int tmp = 1;
            for (int i = a+1; us.find(i) != us.end(); us.erase(i++))
                tmp++;
            for (int i = a-1; us.find(i) != us.end(); us.erase(i--))
                tmp++;
            longest = max(longest, tmp);
        }
        return longest;
    }

    int longestConsecutive2(vector<int>& nums) {
        unordered_map<int, int> um1, um2;
        int longest = 0;
        for (auto a: nums) {
            cout << a << ": \n";
            if (um1.find(a) != um1.end())
                continue;
            um1[a] = 1;
            um2[a] = 1;

            if (um1.find(a+1) != um1.end())
                um1[a] += um1[a+1];
            if (um2.find(a-1) != um2.end())
                um2[a] += um2[a-1];

            if (um2.find(a-1) != um2.end())
                um1[a-(um2[a]-1)] += um1[a];
            if (um1.find(a+1) != um1.end())
                um2[a+um1[a]-1] += um2[a];

            longest = max(longest, um1[a]+um2[a]-1);
        }
        return longest;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 128 Longest Consecutive Sequence, C++ ...\n\n";
    Solution sol;
    
    //vector<int> nums {100, 4, 200, 1, 2, 3};	//4
    vector<int> nums {0,3,7,2,5,8,4,6,0,1};	//9
    int r = sol.longestConsecutive(nums);
    
    cout << r << '\n';
    
    return 0;
}