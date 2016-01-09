//
//  081.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/6/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size()-1;
        while (left <= right) {
            while (left < right && nums[right] == nums[left])
                right--;
            int mid = (left + right) / 2;
            if (target < nums[mid])
                (nums[left] <= nums[mid] ^ nums[left] <= target) ? left = mid+1 : right = mid-1;
            else if (target > nums[mid])
                (nums[mid] <= nums[right] ^ target <= nums[right]) ? right = mid-1 : left = mid+1;
            else
                return true;
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 081 Search in Rotated Sorted Array II, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,1,3,1};
    int target = 3;
    cout << "target = " << target << '\n';
    
    bool r = sol.search(nums, target);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}