//
//  402_remove_k_digits.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/22/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        printf("%s, %d = ", num.c_str(), k);
        for (int i = 0, j; i < k && !num.empty(); i++) {
            for (j = 0; j+1 < num.size() && num[j] <= num[j+1]; j++) {;}
            num.erase(j,1);
            while (num[0] == '0') {
                num.erase(0,1);
            }
        }
        return num.empty() ? "0" : num;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 402. Remove K Digits, C++ ...\n\n";
    Solution sol;

    string num = "1432219";
    int k = 3;
    cout << sol.removeKdigits(num, k) << '\n';

    cout << sol.removeKdigits("10200", 1) << '\n';
    cout << sol.removeKdigits("100", 3) << '\n';
    cout << sol.removeKdigits("112", 1) << '\n';
    cout << sol.removeKdigits("178", 1) << '\n';
    
    return 0;
}
