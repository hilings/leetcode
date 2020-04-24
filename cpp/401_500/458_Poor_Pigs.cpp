//
//  458_Poor_Pigs.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/15/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        /*
         pigs -> dimensions
         minutesToTest / minutesToDie -> how many tests
         */
        return ceil(log(buckets) / log(minutesToTest/minutesToDie + 1));
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 458. Poor Pigs, C++ ...\n\n";
    Solution sol;

    int buckets = 1000;
    int minutesToDie = 15;
    int minutesToTest = 60;

    int r = sol.poorPigs(buckets, minutesToDie, minutesToTest);
    cout << r << '\n';

    return 0;
}
