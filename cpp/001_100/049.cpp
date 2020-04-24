//
//  049.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/6/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void printV(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << '\n';
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;

        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(strs[i]);
        }
        vector<vector<string>> v;
        for (map<string, vector<string>>::iterator it = m.begin(); it != m.end(); it++) {
            sort(it->second.begin(), it->second.end());
            //cout << it->first << ": ";
            //printV(it->second);
            v.push_back(it->second);
        }
        for (int i = 0; i < v.size(); i++) {
            printV(v[i]);
        }

        return v;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 049 Group Anagrams, C++ ...\n\n";

    string words[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = sizeof(words) / sizeof(string);

    vector<string> strs;
    for (int i = 0; i < n; i++) {
        strs.push_back(words[i]);
    }
    printV(strs);

    Solution sol;
    sol.groupAnagrams(strs);

    return 0;
}