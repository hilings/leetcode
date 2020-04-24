//
//  077.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/5/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printV(vector<int> v) {
    for (auto a: v)
        cout << a << ' ';
    cout << '\n';
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> m;

        vector<int> a;
        for (int i = 1; i <= n; i++)
            a.push_back(i);

        vector<int> v (n-k, 0);
        v.insert(v.end(), k, 1);

        do {
            //printV(v);
            vector<int> t;
            for (size_t i = 0; i < n; i++) {
                if (v[i] == 1)
                    t.push_back(a[i]);
            }
            m.push_back(t);
        } while (next_permutation(v.begin(), v.end()));

        return m;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 077 Combinations, C++ ...\n\n";
    Solution sol;
    
    int n = 4;
    int k = 2;
    
    vector<vector<int>> r = sol.combine(n, k);
    for (auto v: r) {
        cout << "[" << v[0] << "," << v[1] << "]\n";
    }
    
    
    return 0;
}