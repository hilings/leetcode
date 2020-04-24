//
//  524_Longest_Word_in_Dictionary_through_Deleting.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/5/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool isSubseq(string s, string sub) {
        int j = 0;
        for (int i = 0; i < s.size() && j < sub.size(); i++) {
            if (s[i] == sub[j]) {
                j++;
            }
        }
        return j == sub.size();
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        string r = "";
        for (string word: d) {
            if (isSubseq(s, word) && (word.size() > r.size() || (word.size() == r.size() && word < r))) {
                r = word;
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 524. Longest Word in Dictionary through Deleting, C++ ...\n\n";
    Solution sol;

    string s = "apple";
    vector<string> d {
        "ale","apple","monkey","plea"
    };

    string r = sol.findLongestWord(s, d);
    cout << r << '\n';

    return 0;
}
