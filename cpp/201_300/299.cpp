//
//  299.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/31/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string getHint0(string secret, string guess) {
        int n = (int)secret.size(), a = 0, b = 0;
        unordered_map<char,int> um;
        for (int i = 0; i < n; i++) {
            char c = secret[i];
            if (c == guess[i])
                a++;
            else
                um[c] = um.find(c) == um.end() ? 1 : um[c]+1;
        }
        for (int i = 0; i < n; i++) {
            char c = guess[i];
            if (secret[i] == c || um.find(c) == um.end())
                continue;
            if (um[c] > 0)
                b++;
            um[c]--;
        }
        return to_string(a)+"A"+to_string(b)+"B";
    }

    string getHint(string secret, string guess) {
        vector<int> v (10, 0);
        int n = (int)secret.size(), a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            char c = secret[i];
            if (c == guess[i])
                a++;
            else
                v[c-'0']++;
        }
        for (int i = 0; i < n; i++) {
            char c = guess[i];
            if (secret[i] == c || v[c-'0'] == 0)
                continue;
            b++;
            v[c-'0']--;
        }
        return to_string(a)+"A"+to_string(b)+"B";
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 299. Bulls and Cows, C++ ...\n\n";
    Solution sol;

    string secret = "1807";
    string guess  = "7810";	// 1A3B
    
    secret = "1123";
    guess  = "0111";	// 1A1B
    
    secret = "1122";
    guess  = "1222";	// 3A0B
    
    string r0 = sol.getHint0(secret, guess);
    cout << r0 << '\n';
    
    string r = sol.getHint(secret, guess);
    cout << r << '\n';
    
    return 0;
}