//
//  567_Permutation_in_String.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/12/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> v1 (26, 0), v2 (26, 0);
        for (int i = 0; i < s1.size(); i++) {
            v1[s1[i]-'a']++;
        }
        for (int i = 0; i < s1.size()-1; i++) {
            v2[s2[i]-'a']++;
        }
        for (size_t i = s1.size()-1, j = 0; i < s2.size(); i++, j++) {
            v2[s2[i]-'a']++;
            if (v1 == v2) {
                return true;
            }
            v2[s2[j]-'a']--;
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 567. Permutation in String, C++ ...\n\n";
    Solution sol;

    string s1 = "ab";
    string s2 = "eidbaooo";

    bool r = sol.checkInclusion(s1, s2);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
