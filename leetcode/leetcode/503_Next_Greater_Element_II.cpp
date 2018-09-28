//
//  503_Next_Greater_Element_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/27/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> r (n, -1);
        stack<int> stk;
        for (int i = 2*n-1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums[i%n]) {
                stk.pop();
            }
            r[i%n] = stk.empty() ? -1 : stk.top();
            stk.push(nums[i%n]);
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 503. Next Greater Element II, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1, 2, 1 // 2, -1, 2
        1,2,1,3 // 2,3,3,-1
    };

    vector<int> r = sol.nextGreaterElements(nums);
    for (int a: r) {
        cout << a << ' ';
    }

    return 0;
}
