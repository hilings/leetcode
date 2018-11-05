//
//  20181102_airbnb3_slider.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/2/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <deque>
using namespace std;

class Solution {
    vector<vector<int>> target;
    vector<vector<int>> input;
public:
    bool canSolve(vector<vector<int>>& myinput) {
        input = myinput;
        target = vector<vector<int>> {
            {1,2,3},
            {4,5,6},
            {7,8,0}
        };
        return bfs(mtos(input));
    }

    string mtos(vector<vector<int>>& input) {
        string s = "";
        for (auto v: input) {
            for (int a: v) {
                s += to_string(a);
            }
        }
        return s;
    }

    bool dfs0(vector<vector<int>>& input, unordered_set<string>& visited) {
        if (input == target) {
            return true;
        }
        string s = mtos(input);
        cout << s << '\n';

        if (visited.find(s) != visited.end()) {
            cout << "dead end" << '\n';
            return false;
        }
        visited.insert(s);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (input[i][j] != 0) {
                    continue;
                }
                if (i-1 >= 0) {
                    swap(input[i][j], input[i-1][j]);
                    if (visited.find(mtos(input)) == visited.end() && dfs0(input, visited)) {
                        return true;
                    }
                    swap(input[i][j], input[i-1][j]);
                }
                if (i+1 <= 2) {
                    swap(input[i][j], input[i+1][j]);
                    if (visited.find(mtos(input)) == visited.end() && dfs0(input, visited)) {
                        return true;
                    }
                    swap(input[i][j], input[i+1][j]);    //
                }
                if (j-1 >= 0) {
                    swap(input[i][j], input[i][j-1]);
                    if (visited.find(mtos(input)) == visited.end() && dfs0(input, visited)) {
                        return true;
                    }
                    swap(input[i][j], input[i][j-1]);
                }
                if (j+1 <= 2) {
                    swap(input[i][j], input[i][j+1]);
                    if (visited.find(mtos(input)) == visited.end() && dfs0(input, visited)) {
                        return true;
                    }
                    swap(input[i][j], input[i][j+1]);
                }
                return false;
            }
        }
        return false;
    }

    bool bfs(string s) {
        unordered_set<string> visited;
        deque<string> q {s};
        while (!q.empty()) {
            string cur = q.front();
            q.pop_front();
            if (cur == "123456780") {
                return true;
            }
            visited.insert(cur);

            string::size_type pos = cur.find('0');

            if (pos >= 3) {
                string next = cur;
                swap(next[pos], next[pos-3]);
                if (visited.find(next) == visited.end()) {
                    q.push_back(next);
                }
            }
            if (pos <= 5) {
                string next = cur;
                swap(next[pos], next[pos+3]);
                if (visited.find(next) == visited.end()) {
                    q.push_back(next);
                }
            }
            if (pos % 3 != 0) {
                string next = cur;
                swap(next[pos], next[pos-1]);
                if (visited.find(next) == visited.end()) {
                    q.push_back(next);
                }
            }
            if (pos % 3 != 2) {
                string next = cur;
                swap(next[pos], next[pos+1]);
                if (visited.find(next) == visited.end()) {
                    q.push_back(next);
                }
            }
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 000 XXX, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> input{
        {1,2,3},
        {8,0,5},
        {4,7,6}

        /*
        {1,2,3},
        {4,5,0},
        {7,8,6}
         */
    };

    bool r = sol.canSolve(input);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
