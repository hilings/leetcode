//
//  20181107_grab2_dominator.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/7/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dominator(vector<int>& v) {
        int cur = v[0], count = 1;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] == cur) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                cur = v[i];
                count = 1;
            }
        }
        count = 0;
        for (int a: v) {
            if (a == cur) {
                count++;
            }
        }
        return count > v.size()/2 ? cur : -1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 000 XXX, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        3,2,3,4,3,3,3,-1  //
        //1,2,3,4,4,4,4
    };

    int z = sol.dominator(nums);
    cout << z << '\n';

    return 0;
}

