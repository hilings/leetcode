//
//  630_Course_Schedule_III.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/22/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& courses, int& r, int i, int start, int count) {
        if (i == courses.size()) {
            r = max(r, count);
            return;
        }
        if (start+courses[i][0] <= courses[i][1]) {
            dfs(courses, r, i+1, start+courses[i][0], count+1);
        }
        dfs(courses, r, i+1, start, count);
    }
public:
    int scheduleCourse0(vector<vector<int>>& courses) { // brute force
        auto cmp = [] (const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        };
        sort(courses.begin(), courses.end(), cmp);
        int r = 0;
        dfs(courses, r, 0, 0, 0);
        return r;
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        auto cmp = [] (const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        };
        sort(courses.begin(), courses.end(), cmp);
        vector<int> dp {0};
        int r = 0;
        for (auto v: courses) {
            printf("(%d %d)\n", v[0], v[1]);
            dp.insert(dp.end(), max(v[1]-(int)dp.size()+1, 0), 0);
            for (int i = v[1]; i-v[0] >= 0; i--) {
                dp[i] = max(dp[i], dp[i-v[0]]+1);
                r = max(r, dp[i]);
            }

            for (int i = 0; i < dp.size(); i++) {
                printf("%d ", i%10);
            }
            cout << '\n';
            for (int i = 0; i < dp.size(); i++) {
                printf("%d ", dp[i]);
            }
            cout << "\n\n";
        }
        return r;
    }

    int scheduleCourse2(vector<vector<int>>& courses) {
        auto cmp = [] (const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        };
        sort(courses.begin(), courses.end(), cmp);
        int sum = 0;
        multiset<int> ms;   // length of courses taken
        for (auto v: courses) {
            if (sum + v[0] <= v[1]) {
                sum += v[0];
                ms.insert(v[0]);
            } else if (!ms.empty() && *(ms.rbegin()) > v[0]) { // swap out a longer course taken earlier
                sum = sum - *(ms.rbegin()) + v[0];
                ms.erase(--ms.end());
                ms.insert(v[0]);
            }
        }
        return (int)ms.size();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 630. Course Schedule III, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> courses {
        /*
        {100, 200},
        {200, 1300},
        {1000, 1250},
        {2000, 3200}    // 3
         */

        /*
        {5,15},
        {3,19},
        {6,7},
        {2,10},
        {5,16},
        {8,14},
        {10,11},
        {2,19}      // 5
         */

        /*
        {2,5},
        {2,19},
        {1,8},
        {1,3}   // 4
         */

        /*
        {7,17},
        {3,12},
        {10,20},
        {9,10},
        {5,20},
        {10,19},
        {4,18}
         */

        {100,2},
        {32,50}

    };

    //int r0 = sol.scheduleCourse0(courses);
    //cout << r0 << '\n';

    int r = sol.scheduleCourse(courses);
    cout << r << '\n';

    int r2 = sol.scheduleCourse2(courses);
    cout << r2 << '\n';

    return 0;
}
