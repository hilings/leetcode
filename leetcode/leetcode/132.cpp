//
//  132.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/17/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    //  needed by below 2nd and 3rd solution
    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

public:
    int minCut(string s) {
        int l = s.size();
        vector<vector<bool>> isP (l, vector<bool> (l, false));
        vector<int> ret;
        for (int i = 0; i < l; i++) {
            ret.push_back(i);
            if (s[0] == s[i] && (i <= 2 || isP[1][i-1])) {
                isP[0][i] = true;
                ret[i] = 0;
                continue;
            }
            for (int j = 1; j <= i; j++) {
                if (s[j] == s[i] && (i-j <= 2 || isP[j+1][i-1])) {
                    isP[j][i] = true;
                    ret[i] = min(ret[i], ret[j-1]+1);
                }
            }
        }
        return ret[l-1];
    }

    //  extend from s[i] to both sides
    //  update ret[i+j+1] which is minCut for substring s[:i+j]
    int minCut2(string s) {
        int l = s.size();
        vector<int> ret (l+1, INT_MAX);     //  minCut for substring s[:i)
        ret[0] = -1;
        for (int i = 0; i < l; i++) {
            for (int j = 0; i-j>=0 && i+j<l && s[i-j] == s[i+j]; j++)
                ret[i+j+1] = min(ret[i+j+1], 1+ret[i-j]);
            for (int j = 0; i-j-1>=0 && i+j<l && s[i-j-1] == s[i+j]; j++)
                ret[i+j+1] = min(ret[i+j+1], 1+ret[i-j-1]);
        }
        return ret[l];
    }

    //  idea is the same with the below third solution
    //  but parse from opposite direction
    //  it's slow for test case "aaabbaaaaaaa"
    //  seems DP
    //  and it's DP is kinda fake
    int minCut3(string s) {
        int l = s.size();
        if (l == 0)
            return 0;
        vector<int> ret (l, INT_MIN);
        return solve3(s, l-1, ret);
    }
    int solve3(string& s, int pos, vector<int>& ret) {
        //	update minCut for substring s[:pos]
        if (pos == -1)
            return -1;
        if (ret[pos] != INT_MIN)
            return ret[pos];
        int tmp = INT_MAX;
        for (int i = 0; i <= pos; i++) {
            if (isPalindrome(s, i, pos)) {
                tmp = min(tmp, 1+solve3(s, i-1, ret));
                if (tmp <= 1)
                    break;
            }
        }
        ret[pos] = tmp;
        return ret[pos];
    }

    //  idea is the same with the above second solution
    //  but parse from opposite direction
    //  it's fast by coincidence for test case "aaabbaaaaaaa"
    //  it will be slow for test case "aaaaaaabbaaa"
    //  and it's DP is kinda fake
    int minCut4(string s) {
        int l = s.size();
        if (l == 0)
            return 0;
        vector<int> ret(l, INT_MIN);
        return solve4(s, 0, ret);
    }
    int solve4(string &s, int pos, vector<int>& ret) {
        //	update minCut for substring s[pos:]
        if (pos == s.size())
            return -1;
        if (ret[pos] != INT_MIN)
            return ret[pos];
        int count = INT_MAX;
        for (int i = s.size()-1; i >= pos; i--) {
            if (isPalindrome(s, pos, i)) {
                count = min(count, solve4(s, i+1, ret));
                if (count < 1)
                    break;
            }
        }
        ret[pos] = count + 1;
        return ret[pos];
    }

};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 132 Palindrome Partitioning II, C++ ...\n\n";
    Solution sol;

    string s = "abaa";
    s = "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi";	//75
    //s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";	//1
    
    
    int r = sol.minCut2(s);
    cout << r << '\n';
    
    return 0;
}