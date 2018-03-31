//
//  468_Validate_IP_Address.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/30/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        int dot = 0, colon = 0, digit = 0, af = 0;
        for (char c: IP) {
            if (c == '.') {
                dot++;
            } else if (c == ':') {
                colon++;
            } else if (isdigit(c)) {
                digit++;
            } else if (tolower(c) >= 'a' && tolower(c) <= 'f') {
                af++;
            } else {
                return "Neither";
            }
        }
        if (dot == 3 && colon == 0 && af == 0 && digit >= 4 && digit <= 12 && validV4(IP)) {
            return "IPv4";
        }
        if (dot == 0 && colon == 7 && digit+af >= 8 && digit+af <= 32 && validV6(IP)) {
            return "IPv6";
        }
        return "Neither";
    }

    bool validV4(string s) {
        for (int i = 0, j; i < s.size(); i=j+1) {
            int n = 0, l = 0;
            for (j = i; j < s.size() && s[j] != '.'; j++) {
                n = 10*n + s[j]-'0';
                if (n > 255 || ++l > 3) {
                    return false;
                }
            }
            if (l == 0 || (l == 2 && n < 10) || (l == 3 && n < 100)) {
                return false;
            }
        }
        return true;
    }

    bool validV6(string s) {
        for (int i = 0, j; i < s.size(); i=j+1) {
            int l = 0;
            for (j = i; j < s.size() && s[j] != ':'; j++) {
                if (++l > 4) {
                    return false;
                }
            }
            if (l == 0) {
                return false;
            }
        }
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 468. Validate IP Address, C++ ...\n\n";
    Solution sol;

    string IP = "192.168.1.1";
    IP = "2001:db8:85a3:0:0:8A2E:0370:7334";
    string r = sol.validIPAddress(IP);
    cout <<r << '\n';

    return 0;
}
