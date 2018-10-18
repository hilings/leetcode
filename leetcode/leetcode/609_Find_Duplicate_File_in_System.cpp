//
//  609_Find_Duplicate_File_in_System.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/18/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> um;
        for (string s: paths) {
            string::size_type pos = s.find(' ');
            string dir = s.substr(0, pos);
            printf("\ndir = %s\n", dir.c_str());
            for (string::size_type i = pos+1; i < s.size(); i = pos+1) {
                pos = s.find(' ', i);
                if (pos == string::npos) {
                    pos = s.size();
                }
                string file = s.substr(i, pos-i);

                string::size_type p = file.find('(');
                string name = file.substr(0, p);
                string content = file.substr(p+1, file.size()-1-p-1);
                printf("name = %s, content = %s\n", name.c_str(), content.c_str());

                string path = dir + "/" + name;
                if (um.find(content) != um.end()) {
                    um[content].push_back(path);
                } else {
                    um[content] = vector<string> {path};
                }
            }
        }
        vector<vector<string>> r;
        for (auto p: um) {
            if (p.second.size() >= 2) {
                r.push_back(p.second);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 609. Find Duplicate File in System, C++ ...\n\n";
    Solution sol;

    vector<string> paths {
        /*
        "root/a 1.txt(abcd) 2.txt(efgh)",
        "root/c 3.txt(abcd)",
        "root/c/d 4.txt(efgh)",
        "root 4.txt(efgh)"
         */
        /*
         ["root/a/2.txt","root/c/d/4.txt","root/4.txt"],
         ["root/a/1.txt","root/c/3.txt"]
         */

        "root/a 1.txt(abcd) 2.txt(efsfgh)",
        "root/c 3.txt(abdfcd)",
        "root/c/d 4.txt(efggdfh)"
        /*
         []
         */
    };

    vector<vector<string>> r = sol.findDuplicate(paths);
    for (auto v: r) {
        for (string s: v) {
            cout << s << ' ';
        }
        cout << '\n';
    }
    return 0;
}
