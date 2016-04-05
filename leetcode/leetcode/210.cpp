//
//  210.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/4/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> pres (numCourses, 0), reachables;
        for (pair<int,int> p: prerequisites) {
            pres[p.first]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (pres[i] == 0)
                reachables.push_back(i);
        }
        int pos = (int)prerequisites.size()-1;
        for (int i = 0; i < reachables.size(); i++) {
            for (int j = pos; j >= 0; j--) {
                if (prerequisites[j].second == reachables[i]) {
                    if (--pres[prerequisites[j].first] == 0)
                        reachables.push_back(prerequisites[j].first);
                    if (j != pos)
                        swap(prerequisites[j], prerequisites[pos]);
                    pos--;
                }
            }
        }
        return reachables.size() == numCourses ? reachables : vector<int> {};
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 210. Course Schedule II, C++ ...\n\n";
    Solution sol;

    int numCourses = 4;
    vector<pair<int,int>> prerequisites {
        pair<int,int> (1,0),
        pair<int,int> (2,0),
        pair<int,int> (3,1),
        pair<int,int> (3,2)
    };

    vector<int> r = sol.findOrder(numCourses, prerequisites);
    for (auto a: r) {
        cout << a << ' ';
    }
    cout << '\n';
    
    return 0;
}