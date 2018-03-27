//
//  451_Sort_Characters_By_Frequency.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/22/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> um;
        for (char c: s) {
            um[c]++;
        }
        vector<string> v (s.size()+1, "");
        for (auto p: um) {
            v[p.second] += p.first;
        }
        string r = "";
        for (int i = (int)v.size()-1; i >= 0; i--) {
            for (char c: v[i]) {
                r.append(i, c);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 451. Sort Characters By Frequency, C++ ...\n\n";
    Solution sol;

    string s = "acacac";
    string r = sol.frequencySort(s);
    cout << r << '\n';

    return 0;
}
