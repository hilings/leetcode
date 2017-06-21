//
//  394_decode_string.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/15/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string r = "";
        for (size_t i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                size_t p = s.find('[', i+1), q = p+1, k = stoi(s.substr(i, p-i));
                for (int n = 1; n > 0; q++) {
                    if (isdigit(s[q]) || isalpha(s[q])) {
                        continue;
                    }
                    n += s[q] == '[' ? 1 : -1;
                }
                q--;	// closing ]
                for (int j = 0; j < k; j++) {
                    r += decodeString(s.substr(p+1, q-p-1));
                }
                i = q;
            } else if (isalpha(s[i])) {
                r += s[i];
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 394. Decode String, C++ ...\n\n";
    Solution sol;

    string s = "3[a]2[bc]";
    string r = sol.decodeString(s);
    cout << r << '\n';
    
    s = "3[a2[c]]";	// accaccacc;
    cout << sol.decodeString(s) << '\n';
    
    s = "2[abc]3[cd]ef";	// abcabccdcdcdef
    cout << sol.decodeString(s) << '\n';
    
    return 0;
}
