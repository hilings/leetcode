//
//  324.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/15/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort0(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ret;
        for (int k = 0, i = (n-1)/2, j = n-1; k < n; k++) {
            ret.push_back(nums[k%2==0 ? i-- : j--]);
        }
        nums.swap(ret);
    }

    void wiggleSort(vector<int>& nums) {
        int n = (int)nums.size(), m = n/2;
        nth_element(nums.begin(), nums.begin()+m, nums.end());	// average O(n)
        int L = 0, cur = 0, S = n-1, median = nums[m];
        while (cur <= S) {
            //cout << "L = " << L << ", cur = " << cur << ", S = " << S << '\n';
            if (nums[myIndex(cur,n)] > median) {
                swap(nums[myIndex(cur++,n)], nums[myIndex(L++,n)]);
            } else if (nums[myIndex(cur,n)] < median) {
                swap(nums[myIndex(cur,n)], nums[myIndex(S--,n)]);
            } else {
                cur++;
            }
            /*
             for (int i = 0; i < n; i++) {
             cout << nums[i] << ' ';
             }
             cout << '\n';
             */
        }
    }
    int myIndex(int i, int n) {
        return (1+2*i) % (n|1);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 324. Wiggle Sort II, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,5,1,1,6,4
        //1,3,2,2,3,1
        //1,1,2,1,2,2,1
        4,5,5,6
    };
    
    sol.wiggleSort0(nums);
    for (int a: nums) {
        cout << a << ' ';
    }
    cout << '\n';
    
    sol.wiggleSort(nums);
    for (int a: nums) {
        cout << a << ' ';
    }
    cout << '\n';
    
    return 0;
}