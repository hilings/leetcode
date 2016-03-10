//
//  164.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/7/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxN = 0, mask = 1, maxDiff = 0;
        for (int a: nums)
            maxN = max(maxN, a);
        for (mask = 1; maxN > 0; maxN = maxN >> 1)
            mask = mask << 1;
        radixSort(nums, 0, nums.size()-1, mask>>1);

        //for (int a: nums)	cout << a;

        for (int i = 1; i < nums.size(); i++) {
            maxDiff = max(maxDiff, nums[i] - nums[i-1]);
            //cout << nums[i];
        }
        return maxDiff;
    }
    void radixSort(vector<int>& nums, int begin, int end, int mask) {
        if (begin >= end || mask == 0)
            return;
        int i = begin, j = end;
        while (i <= j) {
            if ((nums[i] & mask) == 0) {
                i++;
            } else {
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                j--;
            }
        }
        radixSort(nums, begin, i-1, mask>>1);
        radixSort(nums, j+1, end, mask>>1);
    }

    int maximumGap0(vector<int>& nums) {
        for (int i = 0; i < 32; i++) {
            vector<int> v0, v1;
            bool done = true;
            for (int a: nums) {
                int b = a >> i;
                if (b > 0)
                    done = false;
                if ((b&1) == 0) {
                    v0.push_back(a);
                } else {
                    v1.push_back(a);
                }
            }
            if (done)
                break;
            v0.insert(v0.end(), v1.begin(), v1.end());
            nums.swap(v0);
        }
        int maxDiff = 0;
        for (int i = 1; i < nums.size(); i++) {
            maxDiff = max(maxDiff, nums[i] - nums[i-1]);
            cout << nums[i];
        }
        return maxDiff;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 164. Maximum Gap, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {3,5,2,4,1};
    int r = sol.maximumGap(nums);
    cout << r << '\n';
    
    return 0;
}