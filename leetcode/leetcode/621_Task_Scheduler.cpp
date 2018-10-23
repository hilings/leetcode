//
//  621_Task_Scheduler.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/21/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> um;
        /*
         f: frequency of most frequent task(s)
         tie: count of most frequent task(s)
         */
        int f = 0, tie = 0;
        for (char c: tasks) {
            um[c] = um.find(c) != um.end() ? um[c]+1 : 1;
            if (um[c] > f) {
                f = um[c];
                tie = 1;
            } else if (um[c] == f) {
                tie++;
            }
        }
        return max( (f-1)*(n+1) + tie, (int)tasks.size());
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 621. Task Scheduler, C++ ...\n\n";
    Solution sol;

    vector<char> tasks {
        'A','A','A','B','B','B' // 8
        //'A','A','B','B','C','C','D','D' // 8
    };
    int n = 2;

    int r = sol.leastInterval(tasks, n);
    cout << r << '\n';

    return 0;
}
