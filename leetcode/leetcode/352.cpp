//
//  352.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/13/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
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

class SummaryRanges {
    vector<Interval> v;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        cout << "Adding " << val << '\n';
        for (int i = 0; i < v.size(); i++) {
            if (val > v[i].end+1) {
                continue;
            } else if (val < v[i].start-1) {
                v.insert(v.begin()+i, Interval(val, val));
            } else if (val == v[i].start-1) {
                v[i].start = val;
            } else if (val == v[i].end+1) {
                v[i].end = val;
                if (i < v.size()-1 && val == v[i+1].start-1) {
                    v[i+1].start = v[i].start;
                    v.erase(v.begin()+i);
                }
            }
            for (auto p: v) {	cout << "[" << p.start << ", " << p.end << "]\n";	}
            return;
        }
        v.push_back(Interval(val, val));
        for (auto p: v) {	cout << "[" << p.start << ", " << p.end << "]\n";	}
    }

    void addNum2(int val) {
        auto cmp = [](Interval a, Interval b) { return a.start < b.start; };
        auto it = lower_bound(v.begin(), v.end(), Interval(val, val), cmp);
        int start = val, end = val;
        if (it != v.begin() && val <= (it-1)->end+1) {
            it--;
        }
        while (it != v.end() && val >= it->start-1 && val <= it->end+1) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = v.erase(it);
        }
        v.insert(it, Interval(start, end));
    }

    vector<Interval> getIntervals() {
        return v;
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 352. Data Stream as Disjoint Intervals, C++ ...\n\n";

    /**
     * Your SummaryRanges object will be instantiated and called as such:
     SummaryRanges obj = new SummaryRanges();
     */
    SummaryRanges obj;
    //*
    obj.addNum2(1);	// [1,1]
    obj.addNum2(3);	// [1,1],[3,3]
    obj.addNum2(7);	// [1,1],[3,3],[7,7]
    obj.addNum2(2);	// [1,3],[7,7]
    obj.addNum2(6);	// [1,3],[6,7]
    //*/

    /*
     obj.addNum(6);	// [6,6]
     obj.addNum(6);	// [6,6]
     obj.addNum(0);	// [0,0],[6,6]
     obj.addNum(4);	// [0,0],[4,4],[6,6]
     obj.addNum(8);	// [0,0],[4,4],[6,6],[8,8]
     obj.addNum(7);	// [0,0],[4,4],[6,8]
     obj.addNum(6);	// [0,0],[4,4],[6,8]
     obj.addNum(4);	// [0,0],[4,4],[6,8]
     obj.addNum(7);	// [0,0],[4,4],[6,8]
     obj.addNum(5);	// [0,0],[4,8]
     */
    
    vector<Interval> param_2 = obj.getIntervals();
    
    cout << '\n';
    for (Interval a: param_2) {
        cout << "[" << a.start << ", " << a.end << "]\n";
    }
    
    return 0;
}
