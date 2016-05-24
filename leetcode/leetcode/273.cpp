//
//  273.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    string itow(int d) {
        static unordered_map<int,string> um {
            {1, "One"},
            {2, "Two"},
            {3, "Three"},
            {4, "Four"},
            {5, "Five"},
            {6, "Six"},
            {7, "Seven"},
            {8, "Eight"},
            {9, "Nine"},
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"},
            {20, "Twenty"},
            {30, "Thirty"},
            {40, "Forty"},
            {50, "Fifty"},
            {60, "Sixty"},
            {70, "Seventy"},
            {80, "Eighty"},
            {90, "Ninety"},
            {100, "Hundred"},
            {1000, "Thousand"},
            {1000000, "Million"},
            {1000000000, "Billion"},
            {0, "Zero"}
        };
        return um[d];
    }
public:
    string numberToWords(int num) {
        vector<string> words;
        if (num >= 1000000000) {
            words.push_back(numberToWords(num/1000000000));
            words.push_back(itow(1000000000));
            num %= 1000000000;
        }
        if (num >= 1000000) {
            words.push_back(numberToWords(num/1000000));
            words.push_back(itow(1000000));
            num %= 1000000;
        }
        if (num >= 1000) {
            words.push_back(numberToWords(num/1000));
            words.push_back(itow(1000));
            num %= 1000;
        }
        if (num >= 100) {
            words.push_back(numberToWords(num/100));
            words.push_back(itow(100));
            num %= 100;
        }
        if (num >= 20) {
            words.push_back(itow(num/10*10));
            num %= 10;
        }
        if (num > 0)
            words.push_back(itow(num));
        
        string ret;
        for (string s: words) {
            ret += " " + s;
        }
        return ret.empty() ? "Zero" : ret.substr(1);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 273. Integer to English Words, C++ ...\n\n";
    Solution sol;
    
    int num = 0;
    
    string r = sol.numberToWords(num);
    cout << r << '\n';
    
    return 0;
}