//
//  730_Count_Different_Palindromic_Subsequences.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/22/20.
//  Copyright © 2020 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
//#include <deque>
//#include <stack>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include <algorithm>
//#include <cmath>
//#include <numeric>
//#include <utility>

using namespace std;

class Solution {
    const int N = 1000000007;
    int mod(long a) {
        return a % N;
    }

  public:
    int countPalindromicSubsequences(string S) {
        long r = 0, l = S.size();
        vector<long> exclusive(l, 0); // exclusive[j] : palindromic subsequence in the range S[j+1...i]
        vector<long> inclusive(l, 0); // inclusive[j] : palindromic subsequence in the range S[j...i] and starts with S[j]

        for (int i = 0; i < l; i++) {
            long count = 1; // new unique palindromic subsequence ending at S[i]
            for (int j = i - 1; j >= 0; j--) {
                if (S[i] == S[j]) {
                    long x = mod(exclusive[j] + 1); // expand towards two ends, and two ends only
                    exclusive[j] = mod(exclusive[j] + count);
                    count = mod(x + N - inclusive[j]); // deduct duplicate
                    inclusive[j] = x;
                } else {
                    exclusive[j] = mod(exclusive[j] + count);
                }
            }
            r = mod(r + count);

            for (int j = 0; j <= i; j++) {
                cout << exclusive[j] << ' ';
            }
            cout << '\n';

            for (int j = 0; j <= i; j++) {
                cout << inclusive[j] << ' ';
            }
            cout << "\n\n";
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 730. Count Different Palindromic Subsequences, C++ ...\n\n";
    Solution sol;

    string S = "bccbb";

    int r = sol.countPalindromicSubsequences(S);
    cout << r << '\n';

    return 0;
}
