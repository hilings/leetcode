//
//  282.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/23/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    string str;
    int slen;
    long gTarget;

    void solve(vector<string>& ret, string formula, int pos, long total, long prev) {	// addOperators0
        //cout << "formula = \"" << formula << "\", pos = " << pos << ", total = " << total << ", prev = " << prev << '\n';
        if (pos == slen) {
            if (total+prev == gTarget)
                ret.push_back(formula);
            return;
        }
        int end = str[pos] == '0' ? pos+1 : slen;	// leading '0' must be zero
        long value = 0;
        string op = "";
        for (int i = pos; i < end; i++) {
            value = 10*value + str[i]-'0';
            op += str[i];

            if (pos == 0) {
                solve(ret, formula+op, i+1, total, value);
            } else {
                solve(ret, formula+"+"+op, i+1, total+prev, value);
                solve(ret, formula+"-"+op, i+1, total+prev, -value);
                solve(ret, formula+"*"+op, i+1, total, prev*value);
            }
        }
    }

    void dfs(vector<string>& ret, int pos, char* buff, int index, long total, long prev) {	// addOperators
        if (pos == slen) {
            if (total+prev == gTarget) {
                buff[index] = '\0';
                ret.push_back(buff);
            }
            return ;
        }

        long value = 0;
        int len = str[pos] == '0' ? 1 : slen-pos;
        for (int i = 0; i < len; i++) {
            char c = str[pos+i];
            value = 10*value + c-'0';

            buff[index] = '+';
            buff[index+1+i] = c;
            dfs(ret, pos+i+1, buff, index+1+i+1, total+prev, value);

            buff[index] = '-';
            dfs(ret, pos+i+1, buff, index+1+i+1, total+prev, -value);

            buff[index] = '*';
            dfs(ret, pos+i+1, buff, index+1+i+1, total, prev*value);
        }

    }
public:
    vector<string> addOperators0(string num, int target) {
        str = num;
        slen = (int)str.size();
        gTarget = target;

        vector<string> ret;
        solve(ret, "", 0, 0, 0);
        return ret;
    }

    vector<string> addOperators(string num, int target) {
        str = num;
        slen = (int)str.size();
        gTarget = target;

        vector<string> ret;
        char buff[2*slen];

        long value = 0;
        int end = str[0] == '0' ? 1 : slen;	// leading '0' must be zero
        for (int i = 0; i < end; i++) {
            char c = str[i];
            value = 10*value + c-'0';
            buff[i] = c;
            dfs(ret, i+1, buff, i+1, 0, value);
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 282. Expression Add Operators, C++ ...\n\n";
    Solution sol;
    
    string num = "123";
    int target = 6;	// ["1+2+3", "1*2*3"] 
    
    num = "232";
    target = 8;	// ["2*3+2", "2+3*2"]
    
    /*
     num = "105";
     target = 5;	// ["1*0+5","10-5"]
     
     num = "00";
     target = 0;	// ["0+0", "0-0", "0*0"]
     
     num = "3456237490";
     target = 9191;	// []
     
     num = "2147483648";
     target = -2147483648;
     */
    
    vector<string> r0 = sol.addOperators0(num, target);
    for (string s: r0) {
        cout << s << '\n';
    }
    
    cout << '\n';
    
    vector<string> r = sol.addOperators(num, target);
    for (string s: r) {
        cout << s << '\n';
    }
    
    return 0;
}