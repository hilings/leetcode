//
//  423_reconstruct_original_digits_from_english.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/13/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> vc (26,0);
        vector<int> vn (10,0);
        for (char c: s) {
            vc[c-'a']++;
        }
        vn[0] = vc['z'-'a'];	// z
        vn[2] = vc['w'-'a'];	// w
        vn[4] = vc['u'-'a'];	// u
        vn[6] = vc['x'-'a'];	// x
        vn[8] = vc['g'-'a'];	// g
        vn[3] = vc['h'-'a'] - vn[8];	// h
        vn[5] = vc['f'-'a'] - vn[4];	// f
        vn[7] = vc['v'-'a'] - vn[5];	// v
        vn[1] = vc['o'-'a'] - vn[0] - vn[2] - vn[4];	// o
        vn[9] = vc['i'-'a'] - vn[5] - vn[6] - vn[8];	// i

        string r = "";
        for (int i = 0; i <= 9; i++) {
            r.insert(r.end(), vn[i], '0'+i);
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 423. Reconstruct Original Digits from English, C++ ...\n\n";
    Solution sol;

    string s = "owoztneoer";	// 012
    //s = "fviefuro";	// 45
    s = "nnei";	// 9
    string r = sol.originalDigits(s);
    cout << r << '\n';
    
    return 0;
}
