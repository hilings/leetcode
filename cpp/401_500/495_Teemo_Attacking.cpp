//
//  495_Teemo_Attacking.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/8/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) {
            return 0;
        }
        int r = duration;
        for (int i = 1; i < timeSeries.size(); i++) {
            int d = timeSeries[i] - timeSeries[i-1];
            r += d < duration ? d : duration;
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 495. Teemo Attacking, C++ ...\n\n";
    Solution sol;

    vector<int> timeSeries {1,4};
    int duration = 2;

    int r = sol.findPoisonedDuration(timeSeries, duration);
    cout << r << '\n';

    return 0;
}
