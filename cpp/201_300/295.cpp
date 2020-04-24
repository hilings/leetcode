//
//  295.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/27/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
    vector<int> v;

    priority_queue<int> ql;
    priority_queue<int, vector<int>, greater<int>> qh;
public:

    // Adds a number into the data structure.
    void addNum0(int num) {
        int index = 0;
        while (index < v.size() && num > v[index])
            index++;
        v.insert(v.begin()+index, num);
    }

    // Returns the median of current data stream
    double findMedian0() {
        int mid = (int)(v.size()-1)/2;
        if (v.size() % 2 == 1)
            return v[mid];
        return (v[mid]+v[mid+1])/2.0;
    }


    // Adds a number into the data structure.
    void addNum(int num) {
        if (ql.size() > qh.size()) {
            ql.push(num);
            qh.push(ql.top());
            ql.pop();
        } else {
            qh.push(num);
            ql.push(qh.top());
            qh.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (ql.size() > qh.size())
            return ql.top();
        return (ql.top()+qh.top())/2.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 295. Find Median from Data Stream, C++ ...\n\n";
    MedianFinder mf;

    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << '\n';   // 1.5
    mf.addNum(3);
    cout << mf.findMedian() << '\n';   // 2

    return 0;
}