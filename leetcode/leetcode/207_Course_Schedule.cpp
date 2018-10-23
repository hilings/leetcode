//
//  207.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/3/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish0(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> pres (numCourses, unordered_set<int> {});
        vector<int> reachables;
        for (pair<int,int> p: prerequisites) {
            pres[p.first].insert(p.second);
        }
        for (int i = 0; i < numCourses; i++) {
            if (pres[i].empty())
                reachables.push_back(i);
            /*
            cout << i << ": { ";
            for (int a: pres[i]) {
                cout << a << ' ';
            }
            cout << "}\n";
             */
        }
        for (int i = 0; i < reachables.size(); i++) {
            int cur = reachables[i];
            //cout << cur;
            for (int i = 0; i < numCourses; i++) {
                if (!pres[i].empty() && pres[i].erase(cur) == 1 && pres[i].empty())
                    reachables.push_back(i);
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (!pres[i].empty())
                return false;
        }
        return true;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> pres (numCourses, 0), reachables;
        for (pair<int,int> p: prerequisites) {
            pres[p.first]++;    // number of prerequisites
        }
        for (int i = 0; i < numCourses; i++) {
            if (pres[i] == 0)
                reachables.push_back(i);    // finishable class
        }
        int pos = (int)prerequisites.size()-1;
        for (int i = 0; i < reachables.size(); i++) {
            int cur = reachables[i];
            for (int j = pos; j >= 0; j--) {
                pair<int,int> p = prerequisites[j];
                if (p.second == cur) {
                    if (--pres[p.first] == 0)
                        reachables.push_back(p.first);
                    if (j != pos)
                        swap(prerequisites[j], prerequisites[pos]);
                    pos--;
                }
            }
        }
        return reachables.size() == numCourses;
    }

    bool canFinish2(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> pending (numCourses, 0);
        vector<vector<int>> blocking (numCourses, vector<int> {});
        for (auto p: prerequisites) {
            pending[p.first]++;
            blocking[p.second].push_back(p.first);
        }
        vector<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (pending[i] == 0) {
                q.push_back(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int cur = q.back();
            q.pop_back();
            count++;
            for (int b: blocking[cur]) {
                pending[b]--;
                if (pending[b] == 0) {
                    q.push_back(b);
                }
            }
        }
        return count == numCourses;
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 207. Course Schedule, C++ ...\n\n";
    Solution sol;

    int numCourses = 100;
    vector<pair<int,int>> prerequisites = vector<pair<int,int>> {
        //pair<int,int> (1,0)

        pair<int,int> (6,27),
        pair<int,int> (83,9),
        pair<int,int> (10,95),
        pair<int,int> (48,67),
        pair<int,int> (5,71),
        pair<int,int> (18,72),
        pair<int,int> (7,10),
        pair<int,int> (92,4),
        pair<int,int> (68,84),
        pair<int,int> (6,41),
        pair<int,int> (82,41),
        pair<int,int> (18,54),
        pair<int,int> (0,2),
        pair<int,int> (1,2),
        pair<int,int> (8,65),
        pair<int,int> (47,85),
        pair<int,int> (39,51),
        pair<int,int> (13,78),
        pair<int,int> (77,50),
        pair<int,int> (70,56),
        pair<int,int> (5,61),
        pair<int,int> (26,56),
        pair<int,int> (18,19),
        pair<int,int> (35,49),
        pair<int,int> (79,53),
        pair<int,int> (40,22),
        pair<int,int> (8,19),
        pair<int,int> (60,56),
        pair<int,int> (48,50),
        pair<int,int> (20,70),
        pair<int,int> (35,12),
        pair<int,int> (99,85),
        pair<int,int> (12,75),
        pair<int,int> (2,36),
        pair<int,int> (36,22),
        pair<int,int> (21,15),
        pair<int,int> (98,1),
        pair<int,int> (34,94),
        pair<int,int> (25,41),
        pair<int,int> (65,17),
        pair<int,int> (1,56),
        pair<int,int> (43,96),
        pair<int,int> (74,57),
        pair<int,int> (19,62),
        pair<int,int> (62,78),
        pair<int,int> (50,86),
        pair<int,int> (46,22),
        pair<int,int> (10,13),
        pair<int,int> (47,18),
        pair<int,int> (20,66),
        pair<int,int> (83,66),
        pair<int,int> (51,47),
        pair<int,int> (23,66),
        pair<int,int> (87,42),
        pair<int,int> (25,81),
        pair<int,int> (60,81),
        pair<int,int> (25,93),
        pair<int,int> (35,89),
        pair<int,int> (65,92),
        pair<int,int> (87,39),
        pair<int,int> (12,43),
        pair<int,int> (75,73),
        pair<int,int> (28,96),
        pair<int,int> (47,55),
        pair<int,int> (18,11),
        pair<int,int> (29,58),
        pair<int,int> (78,61),
        pair<int,int> (62,75),
        pair<int,int> (60,77),
        pair<int,int> (13,46),
        pair<int,int> (97,92),
        pair<int,int> (4,64),
        pair<int,int> (91,47),
        pair<int,int> (58,66),
        pair<int,int> (72,74),
        pair<int,int> (28,17),
        pair<int,int> (29,98),
        pair<int,int> (53,66),
        pair<int,int> (37,5),
        pair<int,int> (38,12),
        pair<int,int> (44,98),
        pair<int,int> (24,31),
        pair<int,int> (68,23),
        pair<int,int> (86,52),
        pair<int,int> (79,49),
        pair<int,int> (32,25),
        pair<int,int> (90,18),
        pair<int,int> (16,57),
        pair<int,int> (60,74),
        pair<int,int> (81,73),
        pair<int,int> (26,10),
        pair<int,int> (54,26),
        pair<int,int> (57,58),
        pair<int,int> (46,47),
        pair<int,int> (66,54),
        pair<int,int> (52,25),
        pair<int,int> (62,91),
        pair<int,int> (6,72),
        pair<int,int> (81,72),
        pair<int,int> (50,35),
        pair<int,int> (59,87),
        pair<int,int> (21,3),
        pair<int,int> (4,92),
        pair<int,int> (70,12),
        pair<int,int> (48,4),
        pair<int,int> (9,23),
        pair<int,int> (52,55),
        pair<int,int> (43,59),
        pair<int,int> (49,26),
        pair<int,int> (25,90),
        pair<int,int> (52,0),
        pair<int,int> (55,8),
        pair<int,int> (7,23),
        pair<int,int> (97,41),
        pair<int,int> (0,40),
        pair<int,int> (69,47),
        pair<int,int> (73,68),
        pair<int,int> (10,6),
        pair<int,int> (47,9),
        pair<int,int> (64,24),
        pair<int,int> (95,93),
        pair<int,int> (79,66),
        pair<int,int> (77,21),
        pair<int,int> (80,69),
        pair<int,int> (85,5),
        pair<int,int> (24,48),
        pair<int,int> (74,31),
        pair<int,int> (80,76),
        pair<int,int> (81,27),
        pair<int,int> (71,94),
        pair<int,int> (47,82),
        pair<int,int> (3,24),
        pair<int,int> (66,61),
        pair<int,int> (52,13),
        pair<int,int> (18,38),
        pair<int,int> (1,35),
        pair<int,int> (32,78),
        pair<int,int> (7,58),
        pair<int,int> (26,58),
        pair<int,int> (64,47),
        pair<int,int> (60,6),
        pair<int,int> (62,5),
        pair<int,int> (5,22),
        pair<int,int> (60,54),
        pair<int,int> (49,40),
        pair<int,int> (11,56),
        pair<int,int> (19,85),
        pair<int,int> (65,58),
        pair<int,int> (88,44),
        pair<int,int> (86,58)   // false
    };

    bool r = sol.canFinish0(numCourses, prerequisites);
    cout << (r ? "true" : "false") << '\n';

    bool r2 = sol.canFinish2(numCourses, prerequisites);
    cout << (r2 ? "true" : "false") << '\n';

    return 0;
}
