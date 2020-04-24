//
//  017.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/22/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void printVector(vector<string> str) {
        for (int i = 0; i < str.size(); i++) {
            cout << str[i] << ", ";
        }
        cout << '\n';
    }
    
    vector<string> letterCombinations(string digits) {
        string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> v;
        printVector(v);
        
        for (int i = 0; i < digits.size(); i++) {
            int d = digits[i] - '0';
            string letters = map[d];
            int size = (int)v.size();
            if (size == 0) {
                for (int j = 0; j < letters.size(); j++) {
                    v.push_back(string(1,letters[j]));
                }
            } else {
                for (int j = 0; j < letters.size() - 1; j++) {
                    for (int k = 0; k < size; k++) {
                        v.push_back(v[k]);
                    }
                }
                for (int j = 0; j < letters.size(); j++) {
                    for (int k = 0; k < size; k++) {
                        v[j*size+k].push_back(letters[j]);
                    }
                }
            }
        }
        printVector(v);
        return v;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 017 Letter Combinations of a Phone Number, C++ ... ...\n";
    
    string digits = "29";
    
    Solution sol;
    sol.letterCombinations(digits);

    return 0;
}