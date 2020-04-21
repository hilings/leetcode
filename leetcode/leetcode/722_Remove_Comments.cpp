//
//  722_Remove_Comments.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/18/20.
//  Copyright © 2020 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<string> removeComments(vector<string> &source) {
        vector<string> r;

        bool block = false;
        string buffer = "";
        for (int i = 0; i < source.size();) {
            string line = source[i];
            if (line == "") { // skip empty line
                i++;
            } else if (block) {
                size_t pos = line.find("*/");                  // search for "*/"
                if (pos != string::npos) {                     // block closing
                    source[i] = buffer + line.substr(pos + 2); // concat with buffer
                    buffer = "";
                    block = false;
                } else { // just another line in block
                    i++;
                }
            } else {
                size_t pos1 = line.find("//"), pos2 = line.find("/*");               // search for "// or /*"
                if (pos1 != string::npos && (pos2 == string::npos || pos1 < pos2)) { // detect "//"
                    source[i] = line.substr(0, pos1);
                } else if (pos2 != string::npos && (pos1 == string::npos || pos2 < pos1)) { // detect "/*"
                    size_t pos3 = line.find("*/", pos2 + 2);                                // search for "*/"
                    if (pos3 != string::npos) {                                             // block finishes in one line
                        source[i] = line.substr(0, pos2) + line.substr(pos3 + 2);
                    } else { // block has multiple lines
                        block = true;
                        if (pos2 > 0) {
                            buffer = line.substr(0, pos2);
                        }
                        i++;
                    }
                } else { // just a normal line
                    r.push_back(line);
                    i++;
                }
            }
        }

        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 722. Remove Comments, C++ ...\n\n";
    Solution sol;

    vector<string> source{
        // "/*Test program */",
        // "int main()",
        // "{ ",
        // "  // variable declaration ",
        // "int a, b, c;",
        // "/* This is a test",
        // "   multiline  ",
        // "   comment for ",
        // "   testing */",
        // "a = b + c;",
        // "}"

        "a/*comment",
        "line",
        "more_comment*/b"

    };

    vector<string> r = sol.removeComments(source);
    cout << "====\n";
    for (auto s : r) {
        cout << "\"" << s << "\"\n";
    }
    cout << "====\n";

    return 0;
}
