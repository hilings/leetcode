//
//  003.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/6/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string longest, tmp;
        int index = 0;
        while (index < s.length()) {
            string cur = s.substr(index, 1);
            if (tmp.find(cur) == string::npos) {
                tmp.append(cur);
            } else if (tmp.substr(0, 1).compare(cur) == 0) {
                tmp = tmp.substr(1).append(cur);
            } else {
                if (tmp.size() > longest.size()) {
                    longest = tmp;
                }
                tmp = tmp.substr(tmp.find(cur) + 1).append(cur);
            }
            index++;
            cout << "tmp = " << tmp << "\n";
        }
        if (tmp.size() > longest.size()) {
            longest = tmp;
        }
        cout << "longest = " << longest << "\n";
        return (int)longest.size();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "LeetCode 003 Longest Substring Without Repeating Characters, C++ ... ...\n";
    
	         // 01234567890123456789
    string s = "epqcrkeyjzbkvkrganbg";
    cout << s << "\n";
    
    Solution sol;
    cout << "\n" << sol.lengthOfLongestSubstring(s) << "\n";

    return 0;
}
