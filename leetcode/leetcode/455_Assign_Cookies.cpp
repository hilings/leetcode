//
//  455_Assign_Cookies.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/26/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        for (int j = 0; i < g.size() && j < s.size(); j++) {
            if (s[j] < g[i]) {
                continue;
            }
            i++;
        }
        return i;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 455. Assign Cookies, C++ ...\n\n";
    Solution sol;

    vector<int> g {1, 2, 3};
    vector<int> s {1, 2, 3};
    int r = sol.findContentChildren(g, s);
    cout << r << '\n';

    return 0;
}
