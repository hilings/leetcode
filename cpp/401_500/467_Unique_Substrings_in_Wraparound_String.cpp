//
//  467_Unique_Substrings_in_Wraparound_String.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/30/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString0(string p) {
        unordered_set<string> us;
        for (int i = 0, j; i < p.size(); i=j) {
            for (j = i+1; j < p.size() && (p[j]-p[j-1]+26)%26 == 1; j++);
            string s = p.substr(i, j-i);
            cout << s << '\n';
            for (int l = 1; l <= s.size(); l++) {
                for (int k = 0; k+l <= s.size(); k++) {
                    us.insert(s.substr(k, l));
                }
            }
        }
        cout << '\n';
        for (string s: us) {
            cout << s << '\n';
        }
        return (int)us.size();
    }

    int findSubstringInWraproundString(string p) {
        vector<int> v (26, 0);  // longest substring length ends with char
        int r = 0;
        for (int i = 0, l = 0; i < p.size(); i++) {
            int c = p[i] - 'a';
            if (i > 0 && c != (p[i-1]-'a'+1)%26) {
                l = 0;
            }
            if (++l > v[c]) {
                r += l - v[c];
                v[c] = l;
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 467. Unique Substrings in Wraparound String, C++ ...\n\n";
    Solution sol;

    string p = "zabdabc";

    int r0 = sol.findSubstringInWraproundString0(p);
    cout << r0 << '\n';

    int r = sol.findSubstringInWraproundString(p);
    cout << r << '\n';

    return 0;
}
