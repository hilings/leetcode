//
//  395_longest_substring_with_at_least_k_repeating_characters.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/16/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        printf("%s, %d\n", s.c_str(), k);
        int count[26] = { };
        for (char c: s) {
            count[c-'a']++;
        }

        string ng = "";
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) {
                continue;
            }
            //printf("%c: %d\n", 'a'+i, count[i]);
            if (count[i] < k) {
                ng += 'a'+i;
            }
        }
        if (ng == "") {
            return (int)s.size();
        }
        //printf("ng: %s\n", ng.c_str());

        int len = 0;
        for (size_t i = 0; i < s.size(); i++) {
            size_t pos = s.find_first_of(ng, i);
            if (pos == i) {
                continue;
            }
            if (pos == string::npos) {
                pos = s.size();
            }
            string str = s.substr(i, pos-i);
            len = max(len, longestSubstring(str, k));
            i = pos;
        }
        return len;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 395. Longest Substring with At Least K Repeating Characters, C++ ...\n\n";
    Solution sol;

    string s = "aaabb";
    int k = 3;
    printf("%s, %d = %d\n\n", s.c_str(), k, sol.longestSubstring(s, k));
    
    s = "ababbc"; k = 2;
    printf("%s, %d = %d\n\n", s.c_str(), k, sol.longestSubstring(s, k));
    
    s = "ababacb"; k = 3;
    printf("%s, %d = %d\n\n", s.c_str(), k, sol.longestSubstring(s, k));
    
    return 0;
}
