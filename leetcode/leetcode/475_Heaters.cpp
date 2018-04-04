//
//  475_Heaters.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/3/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int r = 0;
        for (int a: houses) {
            auto i = upper_bound(heaters.begin(), heaters.end(), a) - heaters.begin();
            int k = i == 0 ? heaters[i] - a : (i == heaters.size() ? a - heaters[i-1] : min(a-heaters[i-1], heaters[i]-a));
            r = max(r, k);
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 475. Heaters, C++ ...\n\n";
    Solution sol;

    vector<int> houses {
        1,2,3,4
    };
    vector<int> heaters {
        1,4
    };
    int r = sol.findRadius(houses, heaters);
    cout << r << '\n';

    return 0;
}

