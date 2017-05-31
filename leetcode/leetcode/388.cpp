//
//  388.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/28/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//


#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <numeric>
using namespace std;

string myconcat(string x, string y) {
    return x + y + "\\";
};

class Solution {
public:
    int lengthLongestPath(string input) {
        input += '\n';
        int r = 0;
        vector<string> stk;
        for (size_t i = 0; i < input.size(); i++) {
            int layer = 0;
            while (input[i] == '\t') {
                layer++;
                i++;
                cout << '\t';
            }
            while (stk.size() > layer) {    // pop layer
                stk.pop_back();
            }

            size_t index = input.find_first_of("\n", i);
            string word = input.substr(i, index-i);
            cout << word << '\n';

            if (word.find(".") != string::npos) {  // file
                string path = "";
                path = accumulate(stk.begin(), stk.end(), path, myconcat) + word;
                cout << path << '\n';
                r = max(r, (int)path.size());
            } else {    // folder
                stk.push_back(word);
            }
            i = index;
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 388. Longest Absolute File Path, C++ ...\n\n";
    Solution sol;

    string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    int r = sol.lengthLongestPath(input);
    cout << r << '\n';
    
    return 0;
}
