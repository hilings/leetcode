//
//  131.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/17/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool isPalindrome(string& s) {
        for (int i = 0, j = (int)s.size()-1; i < j; ) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if (s.empty())
            return ret;
        vector<string> solution;
        solve(s, ret, solution, 0);
        return ret;
    }

    void solve(string& s, vector<vector<string>>& ret, vector<string>& solution, int pos) {
        if (pos == s.size()) {
            ret.push_back(solution);
            return;
        }
        for (int i = pos; i < s.size(); i++) {
            string cur = s.substr(pos, i+1-pos);
            if (isPalindrome(cur)) {
                solution.push_back(cur);
                solve(s, ret, solution, i+1);
                solution.pop_back();
            }
        }
    }

    vector<vector<string>> partition1(string s) {
        vector<vector<string>> ret;
        if (s.empty())
            ret.push_back(vector<string> {});
        for (size_t i = 0; i < s.size(); i++) {
            string cur = s.substr(i);
            if (isPalindrome(cur)) {
                for (vector<string> v: partition1(s.substr(0, i))) {
                    v.push_back(cur);
                    ret.push_back(v);
                }
            }
        }
        return ret;
    }

    vector<vector<string>> partition2(string s) {
        vector<vector<vector<string>>> m;
        size_t l = s.size();
        for (size_t i = 0; i < l; i++) {
            string cur = s.substr(0, i+1);
            cout << i << ": " << cur << "\n";

            vector<vector<string>> cur_result;
            cout << "checking " << cur << '\n';

            if (isPalindrome(cur)) {
                cur_result.push_back(vector<string> {cur});
            }

            for (size_t j = 1; j <= i; j++) {
                string tmp = s.substr(j, i+1-j);
                cout << "checking " << tmp << '\n';
                if (isPalindrome(tmp)) {
                    cout << tmp << " is valid, preparing results...\n";
                    for (auto v: m[j-1]) {
                        v.push_back(tmp);
                        cur_result.push_back(v);
                    }
                }
            }
            m.push_back(cur_result);
            cout << '\n';
        }
        return m[l-1];
    }
    
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 131 Palindrome Partitioning, C++ ...\n\n";
    Solution sol;
    
    string s = "aab";
    s = "ababbbabbaba";
    vector<vector<string>> r = sol.partition1(s);
    for (auto v: r) {
        cout << "[ ";
        for (auto s: v) {
            cout << s << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}