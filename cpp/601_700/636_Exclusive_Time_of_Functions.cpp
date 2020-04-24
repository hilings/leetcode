//
//  636_Exclusive_Time_of_Functions.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/23/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> r (n, 0);
        stack<int> stk;
        int prev = 0;
        for (string s: logs) {
            string::size_type pos1 = s.find(':');
            int id = stoi(s.substr(0, pos1));
            string::size_type pos2 = s.find(':', pos1+1);
            bool isStart = s.substr(pos1+1, pos2-pos1-1) == "start";
            int time = stoi(s.substr(pos2+1));
            if (!stk.empty()) {
                r[stk.top()] += (isStart ? time : time+1) - prev;
            }
            if (isStart) {
                stk.push(id);
                prev = time;
            } else {
                stk.pop();
                prev = time+1;  // end time is inclusive
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 636. Exclusive Time of Functions, C++ ...\n\n";
    Solution sol;

    int n = 2;
    vector<string> logs {
        "0:start:0",
        "1:start:2",
        "1:end:5",
        "0:end:6"
    };

    vector<int> r = sol.exclusiveTime(n, logs);
    for (int a: r) {
        cout << a << '\n';
    }

    return 0;
}
