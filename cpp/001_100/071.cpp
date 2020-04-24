//
//  071.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/23/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        size_t i = 0;
        while (i < path.size()) {
            size_t j = path.find_first_of('/', i+1);
            if (j == string::npos)
                j = path.size();
            string tmp = path.substr(i+1, j-i-1);
            if (tmp != "." && tmp != "" && tmp != "..")
                v.push_back(tmp);
            else if (tmp == ".." && !v.empty())
                v.pop_back();
            i = j;
        }
        if (v.empty())
            return "/";
        string s = "";
        for (int i = 0; i < v.size(); i++)
            s += "/" + v[i];
        return s;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 071 Simplify Path, C++ ...\n\n";
    Solution sol;
    
    string path = "/";
    string r = sol.simplifyPath(path);
    cout << "^" << r << "$\n";
    
    return 0;
}