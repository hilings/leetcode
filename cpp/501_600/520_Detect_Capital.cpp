//
//  520_Detect_Capital.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/3/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
//#include <vector>
//#include <deque>
//#include <stack>
//#include <algorithm>
//#include <cmath>
using namespace std;

class Solution {
public:
    bool detectCapitalUse0(string word) {
        int n = (int)word.size();
        if (n <= 1) {
            return true;
        }
        if (isupper(word[0])) {
            if (isupper(word[1])) { // case 1, all cap
                for (int i = 2; i < n; i++) {
                    if (islower(word[i])) {
                        return false;
                    }
                }
            } else {    // case 3, first cap only
                for (int i = 2; i < n; i++) {
                    if (isupper(word[i])) {
                        return false;
                    }
                }
            }
        } else {    // case 2, all non-cap
            for (int i = 1; i < n; i++) {
                if (isupper(word[i])) {
                    return false;
                }
            }
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        int n = 0;
        for (char c: word) {
            if (isupper(c)) {
                n++;
            }
        }
        return n == 0 || n == word.size() || (n == 1 && isupper(word[0]));
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 520. Detect Capital, C++ ...\n\n";
    Solution sol;

    string word = "USA";
    word = "leetcode";
    word = "Google";

    bool r0 = sol.detectCapitalUse0(word);
    printf("%s\n", r0 ? "true" : "false");

    bool r = sol.detectCapitalUse(word);
    printf("%s\n", r ? "true" : "false");

    return 0;
}
