//
//  470_Implement_Rand10()_Using_Rand7().cpp
//  leetcode
//
//  Created by Hang Zhang on 9/15/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand7() {
        return rand() % 7 + 1;
    }
    int rand10_0() {
        while (true) {
            int n1 = rand7(), n2 = rand7();
            if (n1 <= 6 && n2 <= 5) {   // p = 30/49
                return 5 * ((n1-1)/3) + n2;
            }
        }
        return 0;
    }
    int rand10() {  // 7 -> 49 -> 40 -> 10
        int r = 40;
        while (r >= 40) {   // p = 40/49
            r = 7 * (rand7() - 1)  + rand7() - 1;
        }
        return r % 10 + 1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 470. Implement Rand10() Using Rand7(), C++ ...\n\n";
    Solution sol;

    vector<int> stats_0 (11, 0);
    vector<int> stats (11, 0);
    int n = 1000;

    for (int i = 0; i < n; i++) {
        stats_0[sol.rand10_0()]++;
        stats[sol.rand10()]++;
    }

    for (int i = 1; i <= 10; i++) {
        printf("%d : %d\n", i, abs(stats_0[i]-n/10));
    }
    cout << '\n';

    for (int i = 1; i <= 10; i++) {
        printf("%d : %d\n", i, abs(stats[i]-n/10));
    }
    cout << '\n';

    return 0;
}
