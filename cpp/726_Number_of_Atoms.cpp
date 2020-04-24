//
//  726_Number_of_Atoms.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/20/20.
//  Copyright © 2020 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

class Solution {
    void helper(map<string, int> &om, string s, int multiplier) {
        for (int i = 0; i < s.size();) {
            if (isupper(s[i])) {
                string name = parseName(s, i);
                string countStr = parseCount(s, i + name.size());
                int count = countStr == "" ? 1 : stoi(countStr);
                om[name] += count * multiplier;
                i += name.size() + countStr.size();
            } else if (s[i] == '(') {
                int index_closing = closingP(s, i);
                string countStr = parseCount(s, index_closing + 1);
                int count = countStr == "" ? 1 : stoi(countStr);
                helper(om, s.substr(i + 1, index_closing - i - 1), count * multiplier);
                i = index_closing + 1 + countStr.size();
            }
        }
    }

    string parseName(string &s, int index) { // index starts from first upper char
        int tail = index;
        for (; tail + 1 < s.size() && islower(s[tail + 1]); tail++) {
        }
        return s.substr(index, tail - index + 1);
    }

    string parseCount(string &s, int index) { // index starts after a name or closing parentheis, which possibly be a digit
        if (index >= s.size() || !isdigit(s[index])) {
            return "";
        }
        int tail = index;
        for (; tail + 1 < s.size() && isdigit(s[tail + 1]); tail++) {
        }
        return s.substr(index, tail - index + 1);
    }

    int closingP(string &s, int opening) { // find index of closing parenthesis
        for (int i = opening, count = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                count--;
                if (count == 0) {
                    return i;
                }
            }
        }
        return -1;
    }

  public:
    string countOfAtoms(string formula) {
        map<string, int> om;
        helper(om, formula, 1);

        string r = "";
        for (auto p : om) {
            r += p.first;
            if (p.second > 1) {
                r += to_string(p.second);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 726. Number of Atoms, C++ ...\n\n";
    Solution sol;

    string formula = "H2O";    // H2O
    formula = "Mg(OH)2";       // H2MgO2
    formula = "K4(ON(SO3)2)2"; // K4N2O14S4

    string r = sol.countOfAtoms(formula);
    cout << r << '\n';

    return 0;
}
