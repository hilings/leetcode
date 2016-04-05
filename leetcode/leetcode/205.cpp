//
//  205.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/31/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char m[256] = {0};
        bool visited[256] = {false};
        for (int i = 0; i < s.size(); i++) {
            if ((m[s[i]] != 0 && m[s[i]] != t[i]) || (m[s[i]] == 0 && visited[t[i]]))
                return false;
            m[s[i]] = t[i];
            visited[t[i]] = true;
        }
        return true;
    }

    bool isIsomorphic2(string s, string t) {
        vector<int> ms (256, -1), mt (256, -1);
        for (int i = 0; i < s.size(); i++) {
            if (ms[s[i]] != mt[t[i]])
                return false;
            ms[s[i]] = i;
            mt[t[i]] = i;
        }
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 205. Isomorphic Strings, C++ ...\n\n";
    Solution sol;

    string s = "egg";
    string t = "add";	// true
    //s = "foo", t = "bar"; 	// false
    //s = "paper", t = "title";	// true
    s = "ab", t = "aa";	// true
    //s = "13", t = "42";	// true
    
    bool r = sol.isIsomorphic2(s, t);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}