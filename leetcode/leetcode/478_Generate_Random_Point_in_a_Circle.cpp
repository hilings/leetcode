//
//  478_Generate_Random_Point_in_a_Circle.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/16/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
    const double PI = 3.1415926;
    double r, x, y;
    double randf() {    // return float in [0, 1]
        return (double)rand() / RAND_MAX;
    }
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }

    vector<double> randPoint0() {
        double xx = x+r, yy = y+r;
        while ((xx-x)*(xx-x) + (yy-y)*(yy-y) > r*r) {
            xx = x-r + 2*r*(randf());
            yy = y-r + 2*r*(randf());
        }
        return vector<double> {xx, yy};
    }

    vector<double> randPoint() {    // polar coordinates
        double a = 2 * PI * randf(), rr = r * sqrt(randf());    // probability adjusted for circle uniform distribution
        double xx = x + rr * cos(a), yy = y + rr * sin(a);
        return vector<double> {xx, yy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 478. Generate Random Point in a Circle, C++ ...\n\n";

    double radius = 2;
    double x_center = 2;
    double y_center = 2;
    Solution sol(radius, x_center, y_center);

    vector<double> r0 = sol.randPoint0();
    printf("(%f, %f)\n", r0[0], r0[1]);

    vector<double> r = sol.randPoint();
    printf("(%f, %f)\n", r[0], r[1]);

    return 0;
}

