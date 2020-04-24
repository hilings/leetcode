//
//  575_Distribute_Candies.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/12/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> us;
        for (int a: candies) {
            us.insert(a);
        }
        return (int)min(us.size(), candies.size()/2);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 575. Distribute Candies, C++ ...\n\n";
    Solution sol;

    vector<int> candies {
        1,1,2,3 // 2
        // 1,1,1,1,1,1,2,2,3,4
    };

    int r = sol.distributeCandies(candies);
    cout << r << '\n';

    return 0;
}
