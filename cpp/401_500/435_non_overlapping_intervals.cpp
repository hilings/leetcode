//
//  435.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/9/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        auto cmp = [] (const Interval& a, const Interval& b) {
            return a.end < b.end || (a.end == b.end && a.start < b.start);
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0;
        for (int i = 1, end = intervals[0].end; i < intervals.size(); i++) {
            if (intervals[i].start < end) {
                count++;
            } else {
                end = intervals[i].end;
            }
        }
        return count;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 435. Non-overlapping Intervals, C++ ...\n\n";
    Solution sol;

    vector<Interval> intervals {
        Interval(1,2),
        Interval(2,3),
        Interval(3,4),
        Interval(1,3)
    };
    int r = sol.eraseOverlapIntervals(intervals);
    cout << r << '\n';

    return 0;
}

