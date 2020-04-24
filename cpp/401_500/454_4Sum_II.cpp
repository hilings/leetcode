//
//  454_4Sum_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/26/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> um;
        for (int a: A) {
            for (int b: B) {
                um[a+b]++;
            }
        }
        int r = 0;
        for (int c: C) {
            for (int d: D) {
                if (um.find(-c-d) != um.end()) {
                    r += um[-c-d];
                }
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 454. 4Sum II, C++ ...\n\n";
    Solution sol;

    vector<int> A {1, 2};
    vector<int> B {-2, -1};
    vector<int> C {-1, 2};
    vector<int> D {0, 2};

    int r = sol.fourSumCount(A, B, C, D);
    cout << r << '\n';

    return 0;
}
