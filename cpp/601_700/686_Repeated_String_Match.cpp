//
//  686_Repeated_String_Match.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/1/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string s = "";
        int r = 0;
        for (; s.size() < B.size(); s += A, r++);
        if (s.find(B) != string::npos) {
            return r;
        }
        if ((s+A).find(B) != string::npos) {
            return r+1;
        }
        return -1;
    }

    int repeatedStringMatch2(string A, string B) {
        for (int i = 0, j; i < A.size(); i++) {
            for (j = 0; j < B.size() && A[(i+j)%A.size()] == B[j]; j++);
            if (j == B.size()) {
                return ceil(float(i+j) / A.size());
            }
        }
        return -1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 686. Repeated String Match, C++ ...\n\n";
    Solution sol;

    string A = "abcd";
    string B = "cdabcdab";

    int r = sol.repeatedStringMatch(A, B);
    cout << r << '\n';

    int r2 = sol.repeatedStringMatch2(A, B);
    cout << r2 << '\n';

    return 0;
}
