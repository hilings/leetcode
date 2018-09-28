//
//  433_Minimum_Genetic_Mutation.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/12/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    bool diff1(string start, string end) {
        int count = 0;
        for (int i = 0; i < start.size(); i++) {
            if (start[i] != end[i]) {
                count++;
            }
        }
        return count == 1;
    }
    int helper(string start, string end, int sofar, unordered_map<string,bool>& us_bank) {
        printf("%s -> %s, sofar = %d\n", start.c_str(), end.c_str(), sofar);
        if (us_bank.empty() || us_bank.find(end) == us_bank.end()) {
            return -1;
        }
        int r = INT_MAX;
        for (auto p: us_bank) {
            if (p.second && diff1(start, p.first)) {
                if (p.first == end) {
                    return sofar+1;
                }
                us_bank[p.first] = false;
                int t = helper(p.first, end, sofar+1, us_bank);
                r = t == -1 ? r : min(r, t);
                us_bank[p.first] = true;
            }
        }
        return r == INT_MAX ? -1 : r;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,bool> us_bank;
        for (string s: bank) {
            us_bank[s] = true;
        }
        return helper(start, end, 0, us_bank);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 433. Minimum Genetic Mutation, C++ ...\n\n";
    Solution sol;

    string start = "AACCGGTT";
    string end = "AACCGGTA";

    start = "AACCGGTT";
    end = "AAACGGTA";

    start = "AAAAACCC";
    end = "AACCCCCC";

    start = "AB";
    end = "AC";

    start = "AAAACCCC";
    end = "CCCCCCCC";
    /*
     */

    vector<string> bank {
        //"AACCGGTA"    // 1
        //"AACCGGTA", "AACCGCTA", "AAACGGTA"  // 2
        //"AAAACCCC", "AAACCCCC", "AACCCCCC"    // 3
        //"BB", "BC", "AC"  // 1
        "AAAACCCA","AAACCCCA","AACCCCCA","AACCCCCC","ACCCCCCC","CCCCCCCC","AAACCCCC","AACCCCCC"
    };

    int r = sol.minMutation(start, end, bank);
    cout << r << '\n';

    return 0;
}
