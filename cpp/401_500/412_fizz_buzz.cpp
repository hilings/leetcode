//
//  412_fizz_buzz.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/6/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> r;
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                r.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                r.push_back("Fizz");
            } else if (i % 5 == 0) {
                r.push_back("Buzz");
            } else {
                r.push_back(to_string(i));
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 412. Fizz Buzz, C++ ...\n\n";
    Solution sol;

    int n = 15;
    vector<string> r = sol.fizzBuzz(n);
    for (string s: r) {
        cout << s << '\n';
    }
    
    return 0;
}
