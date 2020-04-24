//
//  659_Split_Array_into_Consecutive_Subsequences.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/26/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        deque<pair<int,int>> q;
        for (int a: nums) {
            if (q.empty() || q.back().first != a) {
                q.push_back(pair<int,int> (a, 1));
            } else {
                q.back().second++;
            }
        }
        while (!q.empty()) {
            int count = 0;
            for (; count < q.size() && (count == 0 || (q[count].first == q[count-1].first+1 && q[count].second > q[count-1].second)); count++) {
                cout << q[count].first << ' ';
                q[count].second--;
            }
            cout << '\n';
            if (count < 3) {
                return false;
            }
            while (!q.empty() && q.front().second == 0) {
                q.pop_front();
            }
        }
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 659. Split Array into Consecutive Subsequences, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,2,3,3,4,5     // true
        //1,2,3,3,4,4,5,5     // true
        1,2,3,4,4,5
    };

    bool r = sol.isPossible(nums);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
