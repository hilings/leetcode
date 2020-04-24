//
//  287.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/25/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {	// like a linked list that has a loop
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }


    int findDuplicate1(vector<int>& nums) {	// binary search
        int n = (int)nums.size(), left = 1, right = n-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid)
                    count++;
            }
            if (count > mid)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }


    int findDuplicate2(vector<int>& nums) {
        // for each bit, the duplicate number will contribute a greater sum than that of 1 ~ n
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i, a = 0, d = 0;
            for (int j = 0; j < (int)nums.size(); j++) {
                if (j & mask)
                    a++;
                if (nums[j] & mask)
                    d++;
            }
            if (d > a)
                ret += mask;
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 287. Find the Duplicate Number, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {
        1,2,3,4,3	// 3
        //2,5,9,6,9,3,8,9,7,1	// 9
    };
    
    
    int r = sol.findDuplicate(nums);
    cout << r << '\n';
    
    int r1 = sol.findDuplicate1(nums);
    cout << r1 << '\n';
    
    int r2 = sol.findDuplicate2(nums);
    cout << r2 << '\n';
    
    return 0;
}