//
//  593_Valid_Square.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/15/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> us {
            (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]),
            (p1[0]-p3[0])*(p1[0]-p3[0]) + (p1[1]-p3[1])*(p1[1]-p3[1]),
            (p1[0]-p4[0])*(p1[0]-p4[0]) + (p1[1]-p4[1])*(p1[1]-p4[1]),
            (p2[0]-p3[0])*(p2[0]-p3[0]) + (p2[1]-p3[1])*(p2[1]-p3[1]),
            (p2[0]-p4[0])*(p2[0]-p4[0]) + (p2[1]-p4[1])*(p2[1]-p4[1]),
            (p3[0]-p4[0])*(p3[0]-p4[0]) + (p3[1]-p4[1])*(p3[1]-p4[1])
        };
        return us.size() == 2 && us.find(0) == us.end();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 593. Valid Square, C++ ...\n\n";
    Solution sol;

    vector<int> p1 {0,0};
    vector<int> p2 {1,1};
    vector<int> p3 {1,0};
    vector<int> p4 {0,1};

    bool r = sol.validSquare(p1, p2, p3, p4);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
