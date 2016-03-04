//
//  149.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/1/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/**
 * Definition for a point.
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct Line {
    int a, b, c;
    Line(int ta, int tb, int tc) : a(ta), b(tb), c(tc) {}
    //Line(Point p1, Point p2) : a(), b(), c() {}
};

class Solution {
public:
    void printP(Point& p) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
    void printL(Line& l) {
        cout << "\n[" << l.a << ", " << l.b << ", " << l.c << "]\n";
    }

    int maxPoints(vector<Point>& points) {
        int N = (int)points.size(), ret = 0;
        if (N <= 2)
            return N;
        vector<Line> lines;
        vector<unordered_set<int>> pil;	// Point in Line
        unordered_map<int,unordered_set<int>> dup;	// duplicated Point

        for (int i = 1; i < N; i++) {
            printP(points[i]);
            unordered_set<int> visited;
            for (int j = 0; j < lines.size(); j++) {
                if (lines[j].a * points[i].x + lines[j].b * points[i].y + lines[j].c == 0) {
                    visited.insert(pil[j].begin(), pil[j].end());
                    pil[j].insert(i);
                }
            }
            for (int j = 0; j < i; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    if (dup.find(j) == dup.end())
                        dup[j] = unordered_set<int> {i};
                    else
                        dup[j].insert(i);
                    break;
                }
                if (visited.find(j) != visited.end())
                    continue;
                //cout << "checking ...";
                //printP(points[j]);
                int a = points[j].y - points[i].y;
                int b = points[i].x - points[j].x;
                int c = points[j].x * points[i].y - points[i].x * points[j].y;
                lines.push_back(Line (a, b, c));
                pil.push_back(unordered_set<int> {j, i});
                if (dup.find(j) != dup.end()) {
                    pil.back().insert(dup[j].begin(), dup[j].end());
                    visited.insert(dup[j].begin(), dup[j].end());
                }
            }
        }
        if (lines.empty())
            ret = N;
        for (int i = 0; i < lines.size(); i++) {
            printL(lines[i]);
            for (int it: pil[i]) {
                printP(points[it]);
            }
            ret = max(ret, (int)pil[i].size());
        }

        /*
         for (auto p: dup) {
         printP(points[p.first]);
         for (auto q: p.second) {
         cout << q << ", ";
         }
         cout << '\n';
         }
         */

        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 149. Max Points on a Line, C++ ...\n\n";
    Solution sol;

    vector<Point> points {
        Point(1,1),
        Point(1,1),
        Point(1,1)

        /*
         Point(0, 0),
         Point(0, 1),
         Point(1, 0),
         Point(2, 0)
         */

        /*	25
         Point(40,-23),
         Point(9,138),
         Point(429,115),
         Point(50,-17),
         Point(-3,80),
         Point(-10,33),
         Point(5,-21),
         Point(-3,80),
         Point(-6,-65),
         Point(-18,26),
         Point(-6,-65),
         Point(5,72),
         Point(0,77),
         Point(-9,86),
         Point(10,-2),
         Point(-8,85),
         Point(21,130),
         Point(18,-6),
         Point(-18,26),
         Point(-1,-15),
         Point(10,-2),
         Point(8,69),
         Point(-4,63),
         Point(0,3),
         Point(-4,40),
         Point(-7,84),
         Point(-8,7),
         Point(30,154),
         Point(16,-5),
         Point(6,90),
         Point(18,-6),
         Point(5,77),
         Point(-4,77),
         Point(7,-13),
         Point(-1,-45),
         Point(16,-5),
         Point(-9,86),
         Point(-16,11),
         Point(-7,84),
         Point(1,76),
         Point(3,77),
         Point(10,67),
         Point(1,-37),
         Point(-10,-81),
         Point(4,-11),
         Point(-20,13),
         Point(-10,77),
         Point(6,-17),
         Point(-27,2),
         Point(-10,-81),
         Point(10,-1),
         Point(-9,1),
         Point(-8,43),
         Point(2,2),
         Point(2,-21),
         Point(3,82),
         Point(8,-1),
         Point(10,-1),
         Point(-9,1),
         Point(-12,42),
         Point(16,-5),
         Point(-5,-61),
         Point(20,-7),
         Point(9,-35),
         Point(10,6),
         Point(12,106),
         Point(5,-21),
         Point(-5,82),
         Point(6,71),
         Point(-15,34),
         Point(-10,87),
         Point(-14,-12),
         Point(12,106),
         Point(-5,82),
         Point(-46,-45),
         Point(-4,63),
         Point(16,-5),
         Point(4,1),
         Point(-3,-53),
         Point(0,-17),
         Point(9,98),
         Point(-18,26),
         Point(-9,86),
         Point(2,77),
         Point(-2,-49),
         Point(1,76),
         Point(-3,-38),
         Point(-8,7),
         Point(-17,-37),
         Point(5,72),
         Point(10,-37),
         Point(-4,-57),
         Point(-3,-53),
         Point(3,74),
         Point(-3,-11),
         Point(-8,7),
         Point(1,88),
         Point(-12,42),
         Point(1,-37),
         Point(2,77),
         Point(-6,77),
         Point(5,72),
         Point(-4,-57),
         Point(-18,-33),
         Point(-12,42),
         Point(-9,86),
         Point(2,77),
         Point(-8,77),
         Point(-3,77),
         Point(9,-42),
         Point(16,41),
         Point(-29,-37),
         Point(0,-41),
         Point(-21,18),
         Point(-27,-34),
         Point(0,77),
         Point(3,74),
         Point(-7,-69),
         Point(-21,18),
         Point(27,146),
         Point(-20,13),
         Point(21,130),
         Point(-6,-65),
         Point(14,-4),
         Point(0,3),
         Point(9,-5),
         Point(6,-29),
         Point(-2,73),
         Point(-1,-15),
         Point(1,76),
         Point(-4,77),
         Point(6,-29)
         */
        
    };
    
    int r = sol.maxPoints(points);
    cout << r << '\n';
    
    return 0;
}