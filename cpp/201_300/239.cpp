//
//  239.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/17/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow0(vector<int>& nums, int k) {
        vector<int> ret;
        map<int,int> om;
        for (int i = 0; i < nums.size(); i++) {
            if (om.find(nums[i]) == om.end())
                om[nums[i]] = 0;
            om[nums[i]]++;
            if (i >= k-1) {
                ret.push_back(om.rbegin()->first);
                om[nums[i-k+1]]--;
                if (om[nums[i-k+1]] == 0)
                    om.erase(nums[i-k+1]);
            }
        }
        return ret;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && nums[i] > nums[q.back()])
                q.pop_back();
            q.push_back(i);
            if (i-q.front() >= k)
                q.pop_front();
            if (i >= k-1)
                ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 239. Sliding Window Maximum, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {1,3,-1,-3,5,3,6,7};
    int k = 3;
    
    vector<int> r = sol.maxSlidingWindow(nums, k);
    for (int a: r) {
        cout << a << ' ';
    }
    
    return 0;
}