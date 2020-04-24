//
//  522_Longest_Uncommon_Subsequence_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/3/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool isSubSeq(string s, string sub) {
        int j = 0;
        for (int i = 0; i < s.size() && j < sub.size(); i++) {
            if (s[i] == sub[j]) {
                j++;
            }
        }
        return j == sub.size();
    }
public:
    int findLUSlength0(vector<string>& strs) {
        /*
         check from longer string to shorter:
         1. find a longest string that is unique
         2. find a string that is unique among same length, and not subseq of longer strings
         */
        auto cmp = [] (const string& s1, const string& s2) {
            return s1.size() > s2.size();
        };
        sort(strs.begin(), strs.end(), cmp);    // length descending
        int n = (int)strs.size();
        for (int i = 0; i < n; i++) {
            printf("checking %d: %s\n", i, strs[i].c_str());
            bool flag = true;
            for (int j = 0; j < n && strs[j].size() >= strs[i].size(); j++) {
                if (j == i) {
                    continue;
                }
                printf("\tcomparing with %d: %s\n", j, strs[j].c_str());
                if (strs[j].size() > strs[i].size() && isSubSeq(strs[j], strs[i])) {  // not subseq of longer strings
                    printf("\t%s is a subseq of %s\n", strs[i].c_str(), strs[j].c_str());
                    flag = false;
                    break;
                }
                if (strs[j].size() == strs[i].size() && strs[j] == strs[i]) { // not equal to strings with same length
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << strs[i] << '\n';
                return (int)strs[i].size();
            }
        }
        return -1;
    }
    int findLUSlength(vector<string>& strs) {
        auto cmp = [] (const string& s1, const string& s2) {
            return s1.size() > s2.size();
        };
        sort(strs.begin(), strs.end(), cmp);    // length descending
        int n = (int)strs.size();
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n && strs[j].size() >= strs[i].size(); j++) {
                if (j != i && isSubSeq(strs[j], strs[i])) { // must not be subseq of string longer or same length
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return (int)strs[i].size();
            }
        }
        return -1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 522. Longest Uncommon Subsequence II, C++ ...\n\n";
    Solution sol;

    vector<string> strs {
        //"aba", "cdc", "eae" // 3
        "d", "ab", "ac", "abc", "abc"   // 1
    };

    int r0 = sol.findLUSlength0(strs);
    cout << r0 << '\n';

    int r = sol.findLUSlength(strs);
    cout << r << '\n';

    return 0;
}

