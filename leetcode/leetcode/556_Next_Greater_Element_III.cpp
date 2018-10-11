//
//  556_Next_Greater_Element_III.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/10/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v (10, 0);
        string s = to_string(n);
        int i;
        v[s.back()-'0']++;
        for (i = (int)s.size()-2; i >= 0; i--) {
            v[s[i]-'0']++;
            if (s[i] < s[i+1]) {
                break;
            }
        }
        if (i < 0) {
            return -1;
        }
        for (int j = s[i]-'0'+1; j <= 9; j++) {
            if (v[j] > 0) {
                s = s.substr(0, i) + to_string(j);
                v[j]--;
                break;
            }
        }
        for (int j = 0; j <= 9; j++) {
            while (v[j] > 0) {
                s += to_string(j);
                v[j]--;
            }
        }
        return stol(s) > INT_MAX ? -1 : stoi(s);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 556. Next Greater Element III, C++ ...\n\n";
    Solution sol;

    int n = 12; // 21
    n = 21; // -1
    n = 1999999999; // -1

    int r = sol.nextGreaterElement(n);
    cout << r << '\n';

    return 0;
}
