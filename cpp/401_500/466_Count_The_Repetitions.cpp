//
//  466_Count_The_Repetitions.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/28/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unordered_set<char> us;
        for (char c: s2) {
            us.insert(c);
        }
        string s = "";
        for (char c: s1) {  // remove char not in s2
            if (us.find(c) != us.end()) {
                s += c;
            }
        }

        int count = 0;
        vector<int> vc (s2.size()+1, 0);    // kth scan => count of matches, actually need no more than s2.size()+1
        vector<int> vi (s2.size()+1, 0);    // index => kth scan when pattern begins, need no more than s2.size()+1
        for (int k = 1, j = 0; k <= n1; k++) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == s2[j]) {
                    j++;
                    if (j == s2.size()) {
                        count++;
                        j = 0;
                    }
                }
            }
            if (vi[j] != 0) {
                int k0 = vi[j]; // where pattern begins
                int l = k - k0; // pattern length
                int c1 = vc[k0];    // before pattern begins
                int c2 = (n1-k0) / l * (count - vc[k0]);    // where pattern repeats
                int c3 = vc[k0 + (n1-k0) % l] - vc[k0];     // after pattern ends
                return (c1+c2+c3) / n2;
            }
            vc[k] = count;
            vi[j] = k;
        }
        return count / n2;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 466. Count The Repetitions, C++ ...\n\n";
    Solution sol;

    string s1 = "acb";
    int n1 = 4;
    string s2 = "ab";
    int n2 = 2;

    s1 = "aaa";
    n1 = 20;
    s2 = "aaaaa";
    n2 = 1;
    int r = sol.getMaxRepetitions(s1, n1, s2, n2);
    cout << r << '\n';

    return 0;
}
