//
//  526_Beautiful_Arrangement.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/6/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    void helper0(vector<vector<int>>& cand, vector<int>& used, int&count) {
        int pos = (int)used.size()+1;
        if (pos == cand.size()) {
            printf("found one: ");
            count++;
            for (int a: used) {
                cout << a << ' ';
            }
            cout << '\n';
            return;
        }
        for (int c: cand[pos]) {
            if (inVector(used, c)) {
                continue;
            }
            used.push_back(c);
            helper0(cand, used, count);
            used.pop_back();
        }
    }
    bool inVector(vector<int>& v, int k) {
        for (int a: v) {
            if (a == k) {
                return true;
            }
        }
        return false;
    }
public:
    int countArrangement0(int N) {
        vector<vector<int>> cand (N+1,vector<int> {});
        for (int pos = 1; pos <= N; pos++) {
            for (int i = 1; i <= N; i++) {
                if (pos % i == 0 || i % pos == 0) {
                    cand[pos].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> used;
        helper0(cand, used, count);
        return count;
    }
    int countArrangement(int N) {
        vector<bool> used (N+1, false);
        int count = 0;
        helper(used, N, count, 1);
        return count;
    }
    void helper(vector<bool>& used, int N, int& count, int pos) {
        if (pos == N+1) {
            count++;
            return;
        }
        for (int k = 1; k <= N; k++) {
            if (used[k] == false && (k % pos == 0 || pos % k == 0)) {
                used[k] = true;
                helper(used, N, count, pos+1);
                used[k] = false;
            }
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 526. Beautiful Arrangement, C++ ...\n\n";
    Solution sol;

    int N = 0;

    int r0 = sol.countArrangement0(N);
    cout << r0 << '\n';

    int r = sol.countArrangement(N);
    cout << r << '\n';

    return 0;
}
