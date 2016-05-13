//
//  229.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/12/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement0(vector<int>& nums) {
        vector<int> ret;
        unordered_map<int,int> um;
        for (int a: nums) {
            um[a] = um.find(a) == um.end() ? 1 : um[a]+1;
        }
        for (pair<int,int> p: um) {
            if (p.second > nums.size()/3)
                ret.push_back(p.first);
        }
        return ret;
    }

    vector<int> majorityElement(vector<int>& nums) {	// 3
        vector<int> ret;
        if (nums.empty())
            return ret;
        int threshold = (int)nums.size()/3, candidate1 = nums[0], candidate2 = nums[0], count1 = 0, count2 = 0;
        for (int a: nums) {
            if (a == candidate1) {
                count1++;
            } else if (a == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = a;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = a;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int a: nums) {
            if (a == candidate1) {
                count1++;
            } else if (a == candidate2) {
                count2++;
            }
        }
        if (count1 > threshold)
            ret.push_back(candidate1);
        if (count2 > threshold)
            ret.push_back(candidate2);
        return ret;
    }

    vector<int> majorityElementk(vector<int>& nums) {	// generalized
        vector<int> ret;
        if (nums.empty())
            return ret;
        int k = 3, threshold = (int)nums.size()/k;
        unordered_map<int,int> um;
        for (int a: nums) {
            if (um.find(a) != um.end()) {
                um[a]++;
            } else if (um.size() < k-1) {
                um[a] = 1;
            } else {
                vector<int> toErase;
                for (pair<int,int> p: um) {
                    um[p.first]--;
                    if (um[p.first] == 0)
                        toErase.push_back(p.first);
                }
                for (int a: toErase) {
                    um.erase(a);
                }
            }
        }
        for (pair<int,int> p: um) {
            if (count(nums.begin(), nums.end(), p.first) > threshold)
                ret.push_back(p.first);
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 229. Majority Element II, C++ ...\n\n";
    Solution sol;
    
    //vector<int> nums {-1,100,2,100,100,4,100};	// 100
    //vector<int> nums {4,2,1,1};	// 1
    //vector<int> nums {1,1,1,3,3,2,2,2};	// 1,2
    vector<int> nums {1,2,1,1,1,3,3,4,3,3,3,4,4,4};	// 3
    
    vector<int> ret = sol.majorityElement(nums);
    for (int a: ret) {
        cout << a << '\n';
    }
    
    return 0;
}