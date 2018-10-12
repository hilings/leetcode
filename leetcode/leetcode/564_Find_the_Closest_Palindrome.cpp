//
//  564_Find_the_Closest_Palindrome.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/12/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    string fliper(string left, string::size_type l) {
        if (left == "0") {
            if (l == 0) {   // 1 -> 0
                return "0";
            }
            left = "";  // 10 ~ 19
        }
        if (left.size() < l) {  // 1000
            return left + string(l, '9');
        }
        if (left.size() - l == 2) { // 999
            left.pop_back();
            l++;
        }
        string right = left.substr(0, l);
        reverse(right.begin(), right.end());
        return left + right;
    }
public:
    string nearestPalindromic(string n) {
        string r = "";
        long nn = stol(n), diff = INT_MAX;
        printf("n = %ld\n", nn);

        string::size_type mid = (n.size()+1) / 2, l_right = n.size() - mid;
        string left = n.substr(0, mid), right = n.substr(mid);
        printf("left = %s, right = %s\n\n", left.c_str(), right.c_str());

        string flip = fliper(left, l_right);
        long diff_flip = abs(stol(flip) - nn);
        printf("flip = %s, diff = %ld\n", flip.c_str(), diff_flip);
        if (diff_flip != 0) {
            r = flip;
            diff = diff_flip;
        } else {
            printf("n itself is pa\n");
        }

        string left_down = to_string(stol(left)-1);
        string down = fliper(left_down, l_right);
        long diff_down = abs(stol(down)-nn);
        printf("down = %s, diff = %ld\n", down.c_str(), diff_down);
        if (diff_down <= diff) {
            r = down;
            diff = diff_down;
        }

        string left_up = to_string(stol(left)+1);
        string up = fliper(left_up, l_right);
        long diff_up = abs(stol(up)-nn);
        printf("up = %s, diff = %ld\n", up.c_str(), diff_up);
        if (diff_up < diff) {
            r = up;
            diff = diff_up;
        }

        return r;
    }

    string nearestPalindromic2(string n) {
        long nn = stol(n), diff = INT_MAX;

        string::size_type mid = (n.size()+1) / 2, l_right = n.size() - mid;
        string left = n.substr(0, mid);

        vector<string> cand {
            fliper(to_string(stol(left)+1), l_right),
            fliper(left, l_right),
            fliper(to_string(stol(left)-1), l_right)
        };
        string r = "";
        for (string s: cand) {
            //printf("cand = %s\n", s.c_str());
            long d = abs(stol(s) - nn);
            //printf("diff = %d, d = %d\n", diff, d);
            if (d != 0 && d <= diff) {
                diff = d;
                r = s;
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 564. Find the Closest Palindrome, C++ ...\n\n";
    Solution sol;

    string n = "123";   // 121
    n = "1001"; // 999
    //n = "998";  // 999
    //n = "10000";    // 9999
    n = "1000";
    n = "1";  // 0
    n = "1213"; // 1221
    n = "1805170081";   // 1805115081


    string r = sol.nearestPalindromic(n);
    cout << r << '\n';

    string r2 = sol.nearestPalindromic2(n);
    cout << r2 << '\n';

    return 0;
}
