//
//  087.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/8/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {	//DP
        int len = (int)s1.size();
        bool m[len+1][len][len];
        for (size_t i = 0; i < len; i++)
            for (size_t j = 0; j < len; j++)
                m[1][i][j] = s1[i] == s2[j];

        for (int l = 2; l <= len; l++) {
            for (size_t i = 0; i <= len-l; i++) {
                for (size_t j = 0; j <= len-l; j++) {
                    m[l][i][j] = false;
                    for (size_t k = 1; k < l && !m[l][i][j]; k++) {
                        m[l][i][j] |= (m[k][i][j] && m[l-k][i+k][j+k]) || (m[k][i+l-k][j] && m[l-k][i][j+k]);
                    }
                }
            }
        }
        return m[len][0][0];
    }

    bool isScrambler(string s1, string s2) {	//recursive
        if (s1.size() != s2.size())
            return false;
        if (s1 == s2)
            return true;
        int l = (int)s1.size();
        int ab[26] = {0};
        for (size_t i = 0; i < l; i++) {
            ab[s1[i]-'a']++;
            ab[s2[i]-'a']--;
        }
        for (size_t i = 0; i < 26; i++)
            if (ab[i] != 0)
                return false;
        for (int k = 1; k < l; k++) {
            if (isScrambler(s1.substr(0, k), s2.substr(0, k)) && isScrambler(s1.substr(k), s2.substr(k)))
                return true;
            if (isScrambler(s1.substr(0, k), s2.substr(l-k)) && isScrambler(s1.substr(k), s2.substr(0,l-k)))
                return true;
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 087 Scramble String, C++ ...\n\n";
    Solution sol;
    
    string s1 = "great";
    string s2 = "rgtae";
    s1 = "abcdefghijklmnopq";
    s2 = "efghijklmnopqcadb";
    s1 = "xstjzkfpkggnhjzkpfjoguxvkbuopi";
    s2 = "xbouipkvxugojfpkzjhnggkpfkzjts";
    
    cout << s1 << '\n';
    cout << s2 << "\n\n";
    
    bool r = sol.isScrambler(s1, s2);
    cout << (r ? "true" : "false") << '\n';
    
    
    return 0;
}