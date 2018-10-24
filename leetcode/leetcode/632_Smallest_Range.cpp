//
//  632_Smallest_Range.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/23/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto cmp = [&nums] (const pair<int,int>& a, const pair<int,int>& b) {
            return nums[a.first][a.second] > nums[b.first][b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq (cmp);    // highest on top

        int left = INT_MAX, right = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);
            pq.push(pair<int,int> (i, 0));  // first integer of each list
        }
        vector<int> r {left, right};

        while (true) {
            pair<int,int> cur = pq.top();
            pq.pop();
            cur.second++;
            if (cur.second < nums[cur.first].size()) {
                pq.push(cur);
            } else {
                break;
            }
            left = nums[pq.top().first][pq.top().second];
            right = max(right, nums[cur.first][cur.second]);
            printf("[%d, %d] ? [%d, %d]\n", r[0], r[1], left, right);
            if (right - left < r[1] - r[0]) {
                r = vector<int> {left, right};
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 632. Smallest Range, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> nums {
        /*
        {4,10,15,24,26},
        {0,9,12,20},
        {5,18,22,30}    // [20,24]
         */

        {1,2,3},
        {1,2,3},
        {1,2,3} // [1,1]

    };

    vector<int> r = sol.smallestRange(nums);
    printf("[%d, %d]\n", r[0], r[1]);

    return 0;
}
