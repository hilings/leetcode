//
//  587_Erect_the_Fence.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/14/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
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

class Solution {
    int crossProduct(Point& a, Point& b, Point& c) {
        int aby = b.y-a.y, abx = b.x-a.x, acy = c.y-a.y, acx = c.x-a.x;
        return acy * abx - acx * aby;
    }
    int distance(Point& a, Point& b) {
        return (b.y-a.y)*(b.y-a.y) + (b.x-a.x)*(b.x-a.x);
    }
public:
    vector<Point> outerTrees(vector<Point>& points) {
        int n = (int)points.size();
        if (n <= 3) {
            return points;
        }

        int first = 0;
        for (int i = 1; i < n; i++) {
            if (points[i].x < points[first].x) {
                first = i;
            }
        }
        printf("first = (%d, %d)\n", points[first].x, points[first].y);
        unordered_set<int> us {first};

        int cur = first;
        while (true) {  // O(h), where h means number of points on convex hull
            printf("\ncur = (%d, %d)\n", points[cur].x, points[cur].y);
            int next = 0;
            for (int i = 1; i < n; i++) {
                if (i == cur) {
                    continue;
                }
                int cross = crossProduct(points[cur], points[next], points[i]);
                if (cross > 0 ||  // on convex hull
                    (cross == 0 && distance(points[cur], points[i]) > distance(points[cur], points[next])) ) {  // collinear but farther
                    next = i;
                }
            }
            printf("next = (%d, %d)\n", points[next].x, points[next].y);

            for (int i = 0; i < n; i++) {   // collinear points on the path from cur to next
                if (i == cur) {
                    continue;
                }
                if (crossProduct(points[cur], points[next], points[i]) == 0) {
                    us.insert(i);
                }
            }
            cur = next;
            if (cur == first) {
                break;
            }
        }

        vector<Point> r;
        for (int i: us) {
            r.push_back(points[i]);
        }
        return r;
    }

};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 587. Erect the Fence, C++ ...\n\n";
    Solution sol;

    vector<Point> points {
        //*
        Point(1,1),
        Point(2,2),
        Point(2,0),
        Point(2,4),
        Point(3,3),
        Point(4,2) //[1,1],[2,0],[4,2],[3,3],[2,4]
         //*/

        /*
        Point(1,2),
        Point(2,2),
        Point(4,2)  // [1,2],[2,2],[4,2]
         */
    };

    vector<Point> r = sol.outerTrees(points);
    for (auto p: r) {
        printf("(%d, %d)\n", p.x, p.y);
    }

    return 0;
}
