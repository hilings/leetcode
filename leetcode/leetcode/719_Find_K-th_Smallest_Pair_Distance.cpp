//
//  719_Find_K-th_Smallest_Pair_Distance.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/14/20.
//  Copyright © 2020 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> diff;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                diff.push_back(abs(nums[i]-nums[j]));
            }
        }
        sort(diff.begin(), diff.end());
        return diff[k-1];
    }

    int smallestDistancePair2(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();
        while (low < high) {
            int mid = (low + high) / 2, count = 0;
            // count how many pairs that distance <= mid
            for (int left = 0, right = 1; right < nums.size(); right++) {
                while (nums[right] - nums[left] > mid) {
                    left++;
                }
                count += right - left;
            }
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 719. Find K-th Smallest Pair Distance, C++ ...\n\n";
    Solution sol;

    vector<int> nums{1,2,4,8,16};
    int k = 4;

    int r = sol.smallestDistancePair(nums, k);
    cout << r << '\n';

    r = sol.smallestDistancePair2(nums, k);
    cout << r << '\n';

    return 0;
}
