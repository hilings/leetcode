//
//  539_Minimum_Time_Difference.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/9/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> bitmap (24*60, false);
        int first = 24*60, last = -1;
        for (string t: timePoints) {
            int c = (int)t.find(':'), h = stoi(t.substr(0, c)), m = stoi(t.substr(c+1)), i = 60*h+m;
            if (bitmap[i]) {
                return 0;
            }
            bitmap[i] = true;
            first = min(first, i);
            last = max(last, i);
        }
        int r = first+60*24-last;
        for (int i = first, prev = first; i < 60*24; i++) {
            if (!bitmap[i] || prev == i) {
                continue;
            }
            r = min(r, i-prev);
            prev = i;
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 539. Minimum Time Difference, C++ ...\n\n";
    Solution sol;

    vector<string> timePoints {
        //"23:59","00:00" // 1
        "01:01","02:01","03:00" // 59
    };

    int r = sol.findMinDifference(timePoints);
    cout << r << '\n';

    return 0;
}
