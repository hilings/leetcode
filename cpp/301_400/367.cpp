//
//  367.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/22/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <climits>

class Solution {
public:
    bool isPerfectSquare(int num) {
        long root = 0;
        for (int step = 1<<15; step > 0 && root*root < num; step = step>>1) {	// log(sizeof(int))
            if ((root+step)*(root+step) <= num) {
                root += step;
                //std::cout << "adding " << step << ", root = " << root << "\n";
            } else {
                //std::cout << "step too big, decrease " << step << " -> " << (step>>1) << "\n";
            }
        }
        return root*root == num;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    std::cout << "LeetCode 367. Valid Perfect Square, C++ ...\n\n";
    Solution sol;

    for (int num = 0; num <= 100; num++) {
        bool r = sol.isPerfectSquare(num);
        std::cout << "num = " << num << ", " << (r ? "true" : "false") << '\n';
    }

    int num = 46340*46340;
    bool r = sol.isPerfectSquare(num);
    std::cout << "num = " << num << ", " << (r ? "true" : "false") << '\n';
    
    return 0;
}
