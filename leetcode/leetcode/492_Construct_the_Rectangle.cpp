//
//  492_Construct_the_Rectangle.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/7/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> r;
        for (int W = (int)sqrt(area); W > 0; W--) {
            if (area % W == 0) {
                r.push_back(area/W);
                r.push_back(W);
                break;
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 492. Construct the Rectangle, C++ ...\n\n";
    Solution sol;

    int area = 4;
    vector<int> r = sol.constructRectangle(area);

    for (int a: r) {
        cout << a << ' ';
    }

    return 0;
}
