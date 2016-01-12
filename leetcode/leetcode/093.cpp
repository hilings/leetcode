//
//  093.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/8/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        solve(v, s, 4, "");
        return v;
    }
    void solve(vector<string> &v, string s, int set, string solution) {
        if (set > 0) {
            for (int l = 1; l <= 3; l++)
                if (s.size() >= l && valid(s.substr(0,l)))
                    solve(v, s.substr(l), set-1, solution+"."+s.substr(0,l));
        } else if (s.empty())
            v.push_back(solution.substr(1));
    }
    bool valid(string s) {
        return s.size()==1 || (s.size()==2 && s[0]!='0') || (stoi(s)>=100 && stoi(s)<=255);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 093 Restore IP Addresses, C++ ...\n\n";
    Solution sol;

    string s = "25525511135";

    vector<string> r = sol.restoreIpAddresses(s);
    for (auto s: r) {
        cout << s << '\n';
    }

    return 0;
}