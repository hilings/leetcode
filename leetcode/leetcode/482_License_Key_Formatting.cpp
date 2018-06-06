//
//  482_License_Key_Formatting.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/1/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string r = "";
        for (int i = (int)S.size()-1; i >= 0; i--) {
            if (S[i] == '-') {
                continue;
            }
            r += toupper(S[i]);
            if (r.size() % (K+1) == K) {
                r += '-';
            }
        }
        while (r.back() == '-') {
            r.erase(r.end()-1);
        }
        reverse(r.begin(), r.end());
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 482. License Key Formatting, C++ ...\n\n";
    Solution sol;

    string S = "5F3Z-2e-9-w";   // 5F3Z-2E9W
    S = "2-5g-3-J"; // 2-5G-3J
    int K = 4;
    K = 2;
    string r = sol.licenseKeyFormatting(S, K);
    cout << r << '\n';

    return 0;
}
