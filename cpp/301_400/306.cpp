//
//  306.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int end1 = 1; end1 <= num.size()-1 && end1 <= 10; end1++) {
            if (num[0] == '0' && end1 > 1)
                break;
            for (int end2 = end1+1; end2 <= num.size() && end2-end1 <= 10; end2++) {
                string s1 = num.substr(0, end1);
                cout << "s1 = " << s1 << '\n';

                string s2 = num.substr(end1, end2-end1);
                cout << "s2 = " << s2 << '\n';
                if (s2[0] == '0' && s2.size() > 1)
                    break;

                string s3 = to_string(stol(s1) + stol(s2));
                int l = (int)num.size() - end2;

                while (true) {
                    cout << "s3 = " << s3 << '\n';
                    if (s3.size() > l || s3 != num.substr(num.size()-l, s3.size()))
                        break;
                    l -= s3.size();
                    if (l == 0)
                        return true;
                    s1 = s2;
                    s2 = s3;
                    s3 = to_string(stol(s1)+stol(s2));
                }
            }
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 306. Additive Number, C++ ...\n\n";
    Solution sol;
    
    string num = "112358";
    num = "199100199";
    num = "111122335588143";
    
    bool r = sol.isAdditiveNumber(num);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}