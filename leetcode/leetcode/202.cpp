//
//  202.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/24/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;
        while (us.find(n) == us.end()) {
            us.insert(n);
            int sum = 0;
            while (n > 0) {
                sum += pow(n%10, 2);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }

    bool isHappy2(int n) {
        while (n != 1 && n != 4) {
            int sum = 0;
            while (n > 0) {
                sum += pow(n%10, 2);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 202. Happy Number, C++ ...\n\n";
    Solution sol;
    
    int n = 19;
    
    bool r = sol.isHappy2(n);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}