//
//  335.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/7/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    void pp(pair<int,int> p) {
        cout << "(" << p.first << "," << p.second << ")\n";
    }
    bool isSelfCrossing0(vector<int>& x) {
        deque<pair<int,int>> points {pair<int,int> (0,0)};
        int direction = 0, new_x = 0, new_y = 0;
        for (int i = 0; i < x.size(); i++) {
            switch (direction) {
                case 0:
                    new_y += x[i];
                    break;
                case 1:
                    new_x -= x[i];
                    break;
                case 2:
                    new_y -= x[i];
                    break;
                case 3:
                    new_x += x[i];
                    break;
            }

            points.push_back(pair<int,int> (new_x, new_y));
            cout << "\npushing (" << new_x << ", " << new_y << ")\n";
            if (i == 4 && new_x == 0 && new_y >= 0)	// special case, meet back in first section
                return true;

            if (points.size() >= 5) {
                cout << "section 2: \n";
                pp(points[points.size()-1]);
                pp(points[points.size()-2]);

                cout << "section 1: \n";
                pp(points[points.size()-4]);
                pp(points[points.size()-5]);

                if (isCrossed(points[points.size()-1], points[points.size()-2], points[points.size()-4], points[points.size()-5], direction)) {
                    return true;
                }
                if (points.size() >= 7) {
                    cout << "\nsection 2: \n";
                    pp(points[points.size()-1]);
                    pp(points[points.size()-2]);

                    cout << "section 0: \n";
                    pp(points[points.size()-6]);
                    pp(points[points.size()-7]);

                    if (isCrossed(points[points.size()-1], points[points.size()-2], points[points.size()-6], points[points.size()-7], direction)) {
                        return true;
                    }
                    points.pop_front();
                }
            }
            direction = (direction+1)%4;
        }
        return false;
    }

    bool isCrossed(pair<int,int> &p22, pair<int,int> &p21, pair<int,int> &p12, pair<int,int> &p11, int &direction) {
        if (direction % 2 == 1) {	// 1, 3 horizontal
            return (p21.first-p11.first)*(p22.first-p11.first) <= 0 && (p21.second-p11.second)*(p21.second-p12.second) <= 0;
        } else {	// 0, 2 vertical
            return (p21.second-p11.second)*(p22.second-p11.second) <= 0 && (p21.first-p11.first)*(p21.first-p12.first) <= 0;
        }
    }

    bool isSelfCrossing(vector<int>& x) {
        for (int i = 3; i < x.size(); i++) {
            if (x[i] >= x[i-2] && x[i-1] <= x[i-3])	// 4th section meet 1th section, and so on
                return true;
            if (i == 4) {	// special case, meet back in first section
                if (x[i-1] == x[i-3] && x[i]+x[i-4] >= x[i-2])
                    return true;
            }
            if (i >= 5) {	// 6th section meet 1th section, and so on
                if (x[i-2] >= x[i-4] && x[i]+x[i-4] >= x[i-2] && x[i-1] <= x[i-3] && x[i-1]+x[i-5] >= x[i-3])
                    return true;
            }
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 335. Self Crossing, C++ ...\n\n";
    Solution sol;
    
    vector<int> x {
        //2,1,1,2	// true
        //1,2,3,4	// false
        //1,1,1,1 // true
        1,1,2,1,1	// true
        //2,2,3,4,4,2,1
    };
    bool r0 = sol.isSelfCrossing0(x);
    cout << (r0 ? "true" : "false") << '\n';
    
    bool r = sol.isSelfCrossing(x);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}
