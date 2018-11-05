//
//  684_Redundant_Connection.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/31/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> r;
        vector<unordered_set<int>> v;
        for (vector<int> e: edges) {
            int i, j;
            for (i = 0; i < v.size() && v[i].find(e[0]) == v[i].end(); i++);
            for (j = 0; j < v.size() && v[j].find(e[1]) == v[j].end(); j++);
            if (i == v.size() && j == v.size()) {
                v.push_back(unordered_set<int> {e[0], e[1]});
            } else if (i < v.size() && j == v.size()) {
                v[i].insert(e[1]);
            } else if (i == v.size() && j < v.size()) {
                v[j].insert(e[0]);
            } else if (i != j) {
                v[i].insert(v[j].begin(), v[j].end());
                swap(v[j], v.back());
                v.pop_back();
            } else {
                r = e;
                break;
            }
        }
        return r;
    }

    vector<int> findRedundantConnection2(vector<vector<int>>& edges) {      // union find
        vector<int> r;
        vector<int> parent (edges.size()+1, 0); // number of nodes == edges.size()
        iota(parent.begin(), parent.end(), 0);  // fill parent with 0 through n
        for (vector<int>& e: edges) {
            int pu = parent[e[0]], pv = parent[e[1]];
            for (; pu != parent[pu]; pu = parent[pu]);
            for (; pv != parent[pv]; pv = parent[pv]);
            if (pu == pv) { // connecting two nodes in same set, causing cycle
                r = e;
                break;
            } else {    // connecting two separated sets
                parent[pv] = pu;
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 684. Redundant Connection, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> edges {
        //{1,2}, {1,3}, {2,3}     // 2,3
        //{1,2}, {2,3}, {3,4}, {1,4}, {1,5}   // 1,4
        {3,4},{1,2},{2,4},{3,5},{2,5}   // 2,5
    };

    vector<int> r = sol.findRedundantConnection(edges);
    for (int a: r) {
        cout << a << ' ';
    }
    cout << '\n';

    vector<int> r2 = sol.findRedundantConnection2(edges);
    for (int a: r2) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}
