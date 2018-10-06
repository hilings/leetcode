//
//  528_Random_Pick_with_Weight.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/6/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> accum;
public:
    Solution(vector<int> w) {
        int sum = 0;
        for (int a: w) {
            sum += a;
            accum.push_back(sum);
        }
    }
    int pickIndex() {
        int pos = rand() % accum.back();
        auto index = upper_bound(accum.begin(), accum.end(), pos) - accum.begin();
        return (int)index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 528. Random Pick with Weight, C++ ...\n\n";

    vector<int> w {
        //1,3
        3,14,1,7
    };
    Solution sol (w);

    for (int i = 0; i < 4; i++) {
        printf("%d\n", sol.pickIndex());
    }

    return 0;
}
