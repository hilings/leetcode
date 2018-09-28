//
//  457_Circular_Array_Loop.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/13/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) {
            return false;
        }
        for (int start = 0; start < n; start++) {
            if (nums[start] == 0) {
                continue;
            }
            printf("start over from %d\n", start);
            for (int cur = start, direction = 0, step, next; ; cur = next, direction = step > 0 ? 1 : -1) {
                step = nums[cur];
                if (direction != 0 && direction * step < 0) {   // only consider steps in one direction at a time
                    break;
                }
                next = (cur + step % n + n) % n;
                printf("cur = %d, next = %d, direction = %d, nums = %s\n", cur, next, direction, join(nums, " ").c_str());
                nums[cur] = 0;
                if (nums[next] == 0) { // loop detected
                    printf("loop detected\n");
                    if (next != cur && direction != 0) {    // valid loop
                        printf("valid\n");
                        return true;
                    }
                    printf("invalid\n");
                    break;  // invalid loop
                }
            }
        }
        return false;
    }
    string join(vector<int>& vi, string delimiter) {
        string s = "[ ";
        for (int a: vi) {
            s += to_string(a) + delimiter;
        }
        return s + "]";
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 457. Circular Array Loop, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //2, -1, 1, 2, 2  // true
        //-1, 2 // false
        //-2, 1, -1, -2, -2 // false
        //3, 1, 2 // true
        2, -1, 1, -2, -2    // false
    };

    bool r = sol.circularArrayLoop(nums);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
