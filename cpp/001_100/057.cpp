//
//  057.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/14/15.
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

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int index_start = (int)intervals.size(), index_end = (int)intervals.size()-1;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval.start <= intervals[i].end) {
                newInterval.start = min(intervals[i].start, newInterval.start);
                index_start = i;
                break;
            }
        }
        for (int i = index_start; i < intervals.size(); i++) {
            if (newInterval.end < intervals[i].start) {
                index_end = i-1;
                break;
            } else if (newInterval.end <= intervals[i].end) {
                newInterval.end = intervals[i].end;
                index_end = i;
                break;
            }
        }
        intervals.erase(intervals.begin()+index_start, intervals.begin()+index_end+1);
        intervals.insert(intervals.begin()+index_start, newInterval);
        return intervals;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 057 Insert Interval, C++ ...\n\n";

    vector<Interval> intervals {
        /*
         Interval(1,3),
         Interval(6,9)	//[1,5],[6,9]
         */
        /*
         Interval(1,2),
         Interval(3,5),
         Interval(6,7),
         Interval(8,10),
         Interval(12,16)		//[1,2],[3,10],[12,16]
         */
        ///*
        Interval(1,5)	//[0,0],[1,5]
        //*/
    };
    //Interval newInterval (2,5);
    //Interval newInterval (4,9);
    Interval newInterval (0,0);
    for (int i = 0; i < intervals.size(); i++) {
        //show(intervals[i]);
    }
    //show(newInterval);

    Solution sol;
    vector<Interval> r = sol.insert(intervals, newInterval);
    for (int i = 0; i < r.size(); i++) {
        show(intervals[i]);
    }
    vector<int> a = {1, 2, 3, 4, 5};
    a.erase(a.begin()+a.size(), a.begin()+a.size());
    for (int i = 0; i < a.size(); i++) {
        //cout << a[i];
    }

    return 0;
}