//
//  461_Hamming_Distance.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/27/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int r = 0;
        for (int k = x ^ y; k > 0; k = k >> 1) {
            if ((k & 1) == 1) {
                r++;
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 461. Hamming Distance, C++ ...\n\n";
    Solution sol;

    int x = 1, y = 4;
    int r = sol.hammingDistance(x, y);
    cout << r << '\n';

    return 0;
}
