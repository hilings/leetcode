//
//  640_Solve_the_Equation.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/23/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        string::size_type pos = equation.find('=');
        string s = equation.substr(0, pos) + (equation[pos+1] != '-' ? "-" : "");
        for (string::size_type i = pos+1; i < equation.size(); i++) {   // reverse sign
            s += (isdigit(equation[i]) || equation[i] == 'x') ? equation[i] : (equation[i] == '+' ? '-' : '+');
        }
        printf("s = %s\n", s.c_str());
        int a = 0, b = 0;   // ax+b=0
        for (string::size_type i = 0; i < s.size(); i = pos) {
            pos = s.find_first_of("+-", i+1);
            string cur = s.substr(i, pos-i);
            printf("cur = %s\n", cur.c_str());
            if (cur.back() == 'x') {
                string coe = cur.substr(0, cur.size()-1);
                if (coe == "" || coe == "+" || coe == "-") {
                    coe += "1";
                }
                a += stoi(coe);
            } else {
                b += stoi(cur);
            }
        }
        printf("a = %d, b = %d\n", a, b);

        if (a != 0) {
            return "x=" + to_string(-b/a);
        } else if (b == 0) {
            return "Infinite solutions";
        }
        return "No solution";
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 640. Solve the Equation, C++ ...\n\n";
    Solution sol;

    string equation = "x+5-3+x=6+x-2";  // x=2
    equation = "x=x";   // Infinite solutions
    equation = "2x=x";  // x=0
    equation = "2x+3x-6x=x+2";  // x=-1
    //equation = "x=x+2"; // No solution
    
    string r = sol.solveEquation(equation);
    cout << r << '\n';

    return 0;
}
