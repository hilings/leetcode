//
//  009.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/14/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long int shade = 1;
        while (x >= shade * 10) {
            shade *= 10;
        }
        
        while (shade >= 10 && (x % 10) == (x / shade)) {
            x %= shade;
            x /= 10;
            shade /= 100;
        }
        return shade < 10;
    }
    
    bool isPalindrome2(int x) {
        if (x < 0)
            return false;
        int y = x;
        long int z = 0;
        while (y != 0) {
            z = z * 10 + y % 10;
            y /= 10;
        }
        if (z > numeric_limits<int>::max())
            return false;
        return (int)z == x;
    }
};



int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 009 Palindrome Number, C++ ... ...\n";
    
    int x = 1874994781;
    x = 10;
    Solution sol;
    printf("%s", sol.isPalindrome(x) ? "True" : "False");
    return 0;
}
