//
//  436_find_right_interval.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/9/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int,int> m;
        for (int i = 0; i < intervals.size(); i++) {
            m[intervals[i].start] = i;
        }
        vector<int> v;
        for (int i = 0; i < intervals.size(); i++) {
            auto it = m.lower_bound(intervals[i].end);
            v.push_back(it == m.end() ? -1 : it->second);
        }
        return v;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 436. Find Right Interval, C++ ...\n\n";
    Solution sol;

    vector<Interval> intervals {
        /*
        Interval(3,4),
        Interval(2,3),
        Interval(1,2)   // -1, 0, 1
         */

        Interval(1,4),
        Interval(2,3),
        Interval(3,4)   // -1, 2, -1
    };
    vector<int> r = sol.findRightInterval(intervals);
    for (auto a: r) {
        cout << a << ' ';
    }

    return 0;
}
