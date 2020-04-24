//
//  496_Next_Greater_Element_I.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/8/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int,int> um;
        stack<int> stk;
        for (int i = (int)nums.size()-1; i >= 0; i--) {
            while (!stk.empty() && stk.top() < nums[i]) {
                stk.pop();
            }
            um[nums[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums[i]);
        }
        vector<int> r;
        for (int a: findNums) {
            r.push_back(um[a]);
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 496. Next Greater Element I, C++ ...\n\n";
    Solution sol;

    vector<int> findNums {4,1,2};
    vector<int> nums {1,3,4,2}; // -1,3,-1

    vector<int> r = sol.nextGreaterElement(findNums, nums);
    for (int a: r) {
        cout << a << ' ';
    }

    return 0;
}
