//
//  374.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/3/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);
int guess(int num) {
    int target = 6;
    if (target < num)
        return -1;
    if (target > num)
        return 1;
    return 0;
};

class Solution {
public:
    int guessNumber(int n) {
        int num = n/2;
        for (int left = 1, right = n, feedback = guess(num); feedback != 0; feedback = guess(num)) {
            cout << "left = " << left << ", right = " << right << ", num = " << num << ", feedback = " << feedback << "\n";
            if (feedback == 1) {
                left = num+1;
            } else {
                right = num-1;
            }
            num = left+(right-left)/2;
        }
        return num;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 374. Guess Number Higher or Lower, C++ ...\n\n";
    Solution sol;
    
    int n = 10;
    int r = sol.guessNumber(n);
    cout << r << '\n';
    
    return 0;
}
