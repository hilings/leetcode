//
//  689_Maximum_Sum_of_3_Non-Overlapping_Subarrays.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/5/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays0(vector<int>& nums, int k) {
        vector<int> v (nums.size()-k+1, 0);
        int sum = accumulate(nums.begin(), nums.begin() + k-1, 0);
        for (int i = k-1; i < nums.size(); i++) {   // n
            sum += nums[i];
            v[i-k+1] = sum;
            sum -= nums[i-k+1];
        }
        vector<int> r;
        sum = 0;
        for (int i = 0; i < v.size()-2*k; i++) {
            for (int j = i+k; j < v.size()-k; j++) {
                for (int p = j+k; p < v.size(); p++) {
                    int t = v[i]+v[j]+v[p];
                    if (t > sum) {
                        sum = t;
                        r = vector<int> {i,j,p};
                    }
                }
            }
        }
        return r;
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> sums (n+1, 0), MaxL (n, 0), maxR (n, 0);
        for (int i = 0; i < n; i++) {       // sum[i+1] is the sum through ith item
            sums[i+1] = sums[i] + nums[i];
        }
        for (int i = 0, mymax = 0; i <= n-3*k; i++) {   // max sum on the left until index i
            int t = sums[i+k] - sums[i];    // sum of subarray [i, i+k-1] = sums[i+k] - sums[i];
            if (t > mymax) {
                mymax = t;
                MaxL[i] = i;
            } else {
                MaxL[i] = MaxL[i-1];
            }
        }
        for (int i = n-k, mymax = 0; i >= 2*k; i--) {   // max sum on the right starting index i
            int t = sums[i+k] - sums[i];
            if (t >= mymax) {
                mymax = t;
                maxR[i] = i;
            } else {
                maxR[i] = maxR[i+1];
            }
        }
        vector<int> res;
        for (int i = k, mymax = 0; i <= n-2*k; i++) {
            int l = MaxL[i-k], r = maxR[i+k];
            int t = sums[i+k] - sums[i] + sums[l+k] - sums[l] + sums[r+k] - sums[r];
            if (t > mymax) {
                mymax = t;
                res = vector<int> {l, i, r};
            }
        }
        return res;
    }

    vector<int> maxSumOfThreeSubarrays2(vector<int>& nums, int k) {
        vector<int> index {0, k, 2*k};  // index of each subarray begin
        vector<vector<int>> indexMax {  // index of max sum subarray begin
            {index[0]},
            {index[0], index[1]},
            {index[0], index[1], index[2]}
        };
        vector<int> sums {  // sum of each subarray
            accumulate(nums.begin(), nums.begin()+k, 0),
            accumulate(nums.begin()+k, nums.begin()+2*k, 0),
            accumulate(nums.begin()+2*k, nums.begin()+3*k, 0)
        };
        vector<int> sumsMax {sums[0], sums[0]+sums[1], sums[0]+sums[1]+sums[2]};    // accumualte sum of subarrays
        for (int i = 1; i <= nums.size()-3*k; i++) {
            index = {index[0]+1, index[1]+1, index[2]+1};   // subarray move forward together
            sums = {                                        // sum of current subarray
                sums[0] - nums[index[0]-1] + nums[index[0]-1+k],
                sums[1] - nums[index[1]-1] + nums[index[1]-1+k],
                sums[2] - nums[index[2]-1] + nums[index[2]-1+k]
            };

            if (sums[0] > sumsMax[0]) {     // update max sum of subarray 0
                sumsMax[0] = sums[0];
                indexMax[0] = {index[0]};
            }
            if (sumsMax[0] + sums[1] > sumsMax[1]) {    // update max sum of subarray 0 and 1
                sumsMax[1] = sumsMax[0] + sums[1];
                indexMax[1] = {indexMax[0][0], index[1]};
            }
            if (sumsMax[1] + sums[2] > sumsMax[2]) {    // update max sum of subarray 0, 1 and 2
                sumsMax[2] = sumsMax[1] + sums[2];
                indexMax[2] = {indexMax[1][0], indexMax[1][1], index[2]};
            }
        }
        return indexMax[2];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 689. Maximum Sum of 3 Non-Overlapping Subarrays, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        1,2,1,2,6,7,5,1
    };
    int k = 2;

    vector<int> r0 = sol.maxSumOfThreeSubarrays0(nums, k);
    for (int a: r0) {
        cout << a << ' ';
    }
    cout << '\n';

    vector<int> r = sol.maxSumOfThreeSubarrays(nums, k);
    for (int a: r) {
        cout << a << ' ';
    }
    cout << '\n';

    vector<int> r2 = sol.maxSumOfThreeSubarrays2(nums, k);
    for (int a: r2) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}
