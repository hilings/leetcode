//
//  354.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/13/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {	// longest increasing subsequence
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> v;
        for (pair<int,int> p: envelopes) {
            auto it = lower_bound(v.begin(), v.end(), p.second);
            if (it == v.end()) {
                v.insert(it, p.second);
            } else {
                *it = p.second;
            }
        }
        return (int)v.size();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 354. Russian Doll Envelopes, C++ ...\n\n";
    Solution sol;

    vector<pair<int,int>> envelopes {
        /*
         pair<int,int> (5,4),
         pair<int,int> (6,4),
         pair<int,int> (6,7),
         pair<int,int> (2,3)		// 3
         */
        pair<int,int> (1,3),
        pair<int,int> (2,4),
        pair<int,int> (3,1),
        pair<int,int> (4,2),
        pair<int,int> (5,5)
    };
    
    int r = sol.maxEnvelopes(envelopes);
    cout << r << '\n';
    
    return 0;
}
