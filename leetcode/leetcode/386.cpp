//
//  386.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/20/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder0(int n) {
        vector<int> r;
        vector<int> stack {1};
        while (!stack.empty()) {
            if (stack.back() <= n) {
                r.push_back(stack.back());	// write 1
                if (stack.back() % 10 == 9) {
                    stack.pop_back();	// pop 9, no later use
                } else {
                    stack.back()++;		// prepare 2 next later use
                }
                stack.push_back(r.back()*10);	// push 10 for next around
            } else {
                stack.pop_back();	// pop if too big
            }
        }
        return r;
    }

    vector<int> lexicalOrder(int n) {	// no need stack but just one variable
        vector<int> r;
        int cur = 1;
        while (cur > 0) {
            if (cur <= n) {
                r.push_back(cur);	// write 1
                cur *= 10;			// push 10
            } else {
                cur /= 10;	// pop if too big
                while (cur % 10 == 9) {	// pop all if 9
                    cur /= 10;
                }
                if (cur == 0) {	// break if stack empty
                    break;
                }
                cur++;	// next digit
            }
        }
        return r;
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 386. Lexicographical Numbers, C++ ...\n\n";
    Solution sol;
    
    int n = 13;
    
    vector<int> r0 = sol.lexicalOrder0(n);
    for (int _i: r0) {
        cout << _i << '\n';
    }
    
    cout << '\n';
    
    vector<int> r = sol.lexicalOrder(n);
    for (int _i: r) {
        cout << _i << '\n';
    }
    
    return 0;
}
