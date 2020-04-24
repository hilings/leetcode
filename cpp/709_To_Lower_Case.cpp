//
//  709_To_Lower_Case.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/2/19.
//  Copyright © 2019 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = 'a' + str[i] - 'A';
            }
        }
        return str;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 709. To Lower Case, C++ ...\n\n";
    Solution sol;

    string str = "Hello";
    string r = sol.toLowerCase(str);
    cout << r << '\n';

    return 0;
}
