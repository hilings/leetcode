//
//  058.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/15/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ns = (int)s.find_last_not_of(' ');
        return ns == -1 ? 0 : ns-(int)s.substr(0, ns).find_last_of(' ');
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 058 Length of Last Word, C++ ...\n\n";

    string s = " asdf asd";

    Solution sol;
    cout << sol.lengthOfLastWord(s);
    
    return 0;
}