//
//  383.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/14/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> counter (26, 0);
        for (char c: magazine) {
            counter[c-'a']++;
        }
        for (char c: ransomNote) {
            if (--counter[c-'a'] < 0)
                return false;
        }
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 383. Ransom Note, C++ ...\n\n";
    Solution sol;

    string ransomNote = "aa";
    string magazine = "aab";
    bool r = sol.canConstruct(ransomNote, magazine);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}
