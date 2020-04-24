//
//  500_Keyboard_Row.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/11/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    int whichRow(char c) {
        c = tolower(c);
        string s1 = "qwertyuiop", s2 = "asdfghjkl";
        if (s1.find(c) != string::npos) {
            return 1;
        } else if (s2.find(c) != string::npos) {
            return 2;
        }
        return 3;
    }
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> r;
        for (string s: words) {
            int row = whichRow(s[0]);
            bool f = true;
            for (char c: s) {
                if (whichRow(c) != row) {
                    f = false;
                    break;
                }
            }
            if (f == true) {
                r.push_back(s);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 500. Keyboard Row, C++ ...\n\n";
    Solution sol;

    vector<string> words {
        "Hello", "Alaska", "Dad", "Peace"
    };

    vector<string> r = sol.findWords(words);
    for (string s: r) {
        cout << s << '\n';
    }

    return 0;
}
