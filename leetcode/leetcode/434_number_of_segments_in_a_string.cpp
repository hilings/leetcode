//
//  434_number_of_segments_in_a_string.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/27/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int count = 0, n = (int)s.size();
        for (int i = 0; i < n; i++) {
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
            if (i == n) {
                break;
            }
            count++;
            while (i+1 < n && s[i+1] != ' ') {
                i++;
            }
        }
        return count;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 434. Number of Segments in a String, C++ ...\n\n";
    Solution sol;
    
    string s = "   Hello, my  name is John  ";
    int r = sol.countSegments(s);
    cout << r << '\n';
    
    return 0;
}
