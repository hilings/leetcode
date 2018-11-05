//
//  682_Baseball_Game.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/31/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        int r = 0;
        for (string s: ops) {
            if (s == "+") {
                int t = v[v.size()-1] + v[v.size()-2];
                r += t;
                v.push_back(t);
            } else if (s == "D") {
                r += v.back()*2;
                v.push_back(v.back()*2);
            } else if (s == "C") {
                r -= v.back();
                v.pop_back();
            } else {
                int t = stoi(s);
                r += t;
                v.push_back(stoi(s));
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 682. Baseball Game, C++ ...\n\n";
    Solution sol;

    vector<string> ops {
        //"5","2","C","D","+"     // 30
        "5","-2","4","C","D","9","+","+"    // 27
    };

    int r = sol.calPoints(ops);
    cout << r << '\n';

    return 0;
}
