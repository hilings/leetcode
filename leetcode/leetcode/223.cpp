//
//  223.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/9/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ret = (C-A)*(D-B) + (G-E)*(H-F);
        if (C <= E || G <= A || D <= F || H <= B)	// no overlapping
            return ret;
        return ret - (min(C,G)-max(A,E)) * (min(D,H)-max(B,F));	// overlapping
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 223. Rectangle Area, C++ ...\n\n";
    Solution sol;

    int A = -3;
    int B = 0;
    int C = 3;
    int D = 4;

    int E = 0;
    int F = -1;
    int G = 9;
    int H = 2;

    int r = sol.computeArea(A, B, C, D, E, F, G, H);
    cout << r << '\n';
    
    return 0;
}