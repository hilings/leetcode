//
//  480_Sliding_Window_Median.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/4/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms (nums.begin(), nums.begin()+k);
        auto it = next(ms.begin(), k/2);
        vector<double> r;
        for (int i = k; i <= nums.size(); i++) {
            double m = k%2 ? *it : ((double)*it + *prev(it))/2;
            r.push_back(m);
            if (i == nums.size()) {
                break;
            }

            ms.insert(nums[i]);
            if (nums[i] < *it) {    // mid move left if new insert smaller
                it--;
            }

            if (nums[i-k] <= *it) {   // mid move right if deleted smaller
                it++;
            }
            ms.erase(ms.lower_bound(nums[i-k]));
        }
        return r;
    }

    vector<double> medianSlidingWindow2(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> medians;
        for (int i=k; ; i++) {

            // Push the current median.
            medians.push_back((double(*mid) + *prev(mid, 1 - k%2)) / 2);

            // If all done, return.
            if (i == nums.size())
                return medians;

            // Insert nums[i].
            window.insert(nums[i]);
            if (nums[i] < *mid)
                mid--;

            // Erase nums[i-k].
            if (nums[i-k] <= *mid)
                mid++;
            window.erase(window.lower_bound(nums[i-k]));
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 480. Sliding Window Median, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,3,-1,-3,5,3,6,7   // 1,-1,-1,3,5,6
        //1,4,2,3 //2.5
        //1,2 // 1.5
        //1,2 // 1,2
        2147483647,2147483647   // 2147483647
    };
    int k =
        //3
        //4
        //2
        //1
        2
    ;

    vector<double> r = sol.medianSlidingWindow(nums, k);
    for (double a: r) {
        cout << a << ' ';
    }
    cout << '\n';

    vector<double> r2 = sol.medianSlidingWindow2(nums, k);
    for (double a: r2) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}
