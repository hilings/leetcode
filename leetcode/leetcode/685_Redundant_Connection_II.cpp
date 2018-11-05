//
//  685_Redundant_Connection_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/1/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> r {0,0};
        vector<int> parent (edges.size()+1, 0), can1, can2; // number of nodes == edges.size()
        for (vector<int>& e: edges) {
            if (parent[e[1]] != 0) {     // node e[1] has two parents, so edges from its two parents are candidates to remove
                can1 = vector<int> {parent[e[1]], e[1]};
                can2 = e;
                e[1] = 0;   // remove can2 for now, and try union find
            } else {
                parent[e[1]] = e[0];
            }
        }
        iota(parent.begin(), parent.end(), 0);  // fill parent with 0 through n
        for (vector<int>& e: edges) {
            int pu = parent[e[0]], pv = parent[e[1]];
            for (; pu != parent[pu]; pu = parent[pu]);
            for (; pv != parent[pv]; pv = parent[pv]);
            if (pu == pv) { // detecting cycle, because this e or can1
                return can1.empty() ? e : can1;
            } else {    // connecting two separated sets
                parent[pv] = pu;
            }
        }
        return can2;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 685. Redundant Connection II, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> edges {
        //{1,2}, {1,3}, {2,3}     // 2,3
        {1,2}, {2,3}, {3,4}, {4,1}, {1,5}   // 4,1
    };

    vector<int> r = sol.findRedundantDirectedConnection(edges);
    printf("%d %d\n", r[0], r[1]);

    return 0;
}
