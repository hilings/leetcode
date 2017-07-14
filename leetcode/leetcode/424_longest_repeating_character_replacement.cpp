//
//  424_longest_repeating_character_replacement.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/13/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> vc (26, 0);
        int i = 0;
        for (int j = 0, most = 0; j < s.size(); j++) {
            most = max(most, ++vc[s[j]-'A']);	// most frequent char so far
            if (j+1-i - most > k) {	// number of chars needed to change > k
                vc[s[i++]-'A']--;	// slide window to right by 1
            }
        }
        return (int)s.size() - i;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 424. Longest Repeating Character Replacement, C++ ...\n\n";
    Solution sol;

    string s = "ABAAABBAAA";
    int k = 2;
    int r = sol.characterReplacement(s, k);
    cout << r << '\n';
    
    return 0;
}
