//
//  165.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/7/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int e1 = (int)version1.find_first_of('.'), e2 = (int)version2.find_first_of('.');
        int d1 = stoi(version1.substr(0, e1)), d2 = stoi(version2.substr(0, e2));
        if (d1 < d2)
            return -1;
        else if (d1 > d2)
            return 1;
        else if (e1 == -1 && e2 == -1)
            return 0;
        if (e1 == -1) {
            e1 = (int)version1.size();
            version1 += ".0";
        }
        if (e2 == -1) {
            e2 = (int)version2.size();
            version2 += ".0";
        }
        return compareVersion(version1.substr(e1+1), version2.substr(e2+1));
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 165. Compare Version Numbers, C++ ...\n\n";
    Solution sol;

    string version1 = "1.0";
    string version2 = "1";
    int r = sol.compareVersion(version1, version2);
    cout << r << '\n';
    
    return 0;
}