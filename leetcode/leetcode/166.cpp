//
//  166.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/9/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long n = abs((long)numerator), d = abs((long)denominator), r = n % d;
        string qq = (numerator != 0 && (signbit(numerator) ^ signbit(denominator)) ? "-" : "") + to_string(n/d), rr = "";
        if (r == 0)
            return qq;
        unordered_map<long,int> visited;
        while (r != 0) {
            if (visited.find(r) != visited.end()) {
                rr = rr.substr(0, visited[r]) + "(" + rr.substr(visited[r]) + ")";
                break;
            }
            visited[r] = (int)rr.size();
            r *= 10;
            rr += '0' + r / d;
            r %= d;
        }
        return qq + "." + rr;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 166. Fraction to Recurring Decimal, C++ ...\n\n";
    Solution sol;

    //int numerator = -2147483648, denominator = 1;
    //string expected = "-2147483648";
    //int numerator = 1, denominator = 214748364;
    //string expected = "0.00(000000465661289042462740251655654056577585848337359161441621040707904997124914069194026549138227660723878669455195477065427143370461252966751355553982241280310754777158628319049732085502639731402098131932683780538602845887105337854867197032523144157689601770377165713821223802198558308923834223016478952081795603341592860749337303449725)";
    int numerator = -1, denominator = -2147483648;
    string expected = "0.0000000004656612873077392578125";
    
    string r = sol.fractionToDecimal(numerator, denominator);
    cout << r << '\n';
    cout << expected << '\n';
    
    return 0;
}