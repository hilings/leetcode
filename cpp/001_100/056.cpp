//
//  056.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/9/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
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

void show(Interval a) {
    cout << "[" << a.start << ", " << a.end << "]\n";
}

bool cmp (Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> v;
        if (intervals.empty())
            return v;
        sort(intervals.begin(), intervals.end(), cmp);

        while (intervals.size() >= 2) {
            int index;
            for (index = (int)intervals.size()-2; index >= 0; index--) {
                if (intervals.back().start <= intervals[index].end)
                    break;
            }
            if (index < 0) {
                v.push_back(intervals.back());
                intervals.pop_back();
            } else {
                int lower = intervals[index].start;
                int upper = max(intervals[index].end, intervals.back().end);
                for (int i = (int)intervals.size()-1; i >= index; i--) {
                    intervals.pop_back();
                }
                intervals.push_back(Interval(lower, upper));
            }
        }

        v.push_back(intervals.front());
        return v;
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 056 Merge Intervals, C++ ...\n\n";

    vector<Interval> intervals {
        ///*
        Interval(2,6),
        Interval(1,3),
        Interval(8,10),
        Interval(15,18)
         //*/

        /*
        Interval(1,4),
        Interval(2,3)
         */

        /*
        Interval(2,3),
        Interval(4,5),
        Interval(6,7),
        Interval(8,9),
        Interval(1,10)
         */
    };

    //return [1,6],[8,10],[15,18]
    for (int i = 0; i < intervals.size(); i++) {
        //show(intervals[i]);
    }

    Solution sol;
    vector<Interval> r = sol.merge(intervals);
    for (int i = 0; i < r.size(); i++) {
        show(r[i]);
    }

    return 0;
}