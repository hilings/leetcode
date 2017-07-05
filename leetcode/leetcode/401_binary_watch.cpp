//
//  401_binary_watch.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/22/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> r;
        for (int bh = 0; bh <= min(4, num); bh++) {	// bit for hour
            vector<int> hours;
            for (int h = 0; h <= 11; h++) {
                if (countBit(h) == bh) {
                    hours.push_back(h);
                }
            }
            for (int m = 0, bm = num - bh; m <= 59; m++) {
                if (countBit(m) == bm) {	// bit for minute
                    for (int h: hours) {
                        r.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                    }
                }
            }
        }
        return r;
    }

    int countBit(int n) {
        int count = 0;
        while (n > 0) {
            count += n&1;
            n = n >> 1;
        }
        return count;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 401. Binary Watch, C++ ...\n\n";
    Solution sol;
    
    int num = 1;
    vector<string> r = sol.readBinaryWatch(num);
    for (string s: r) {
        cout << s << '\n';
    }
    
    return 0;
}
