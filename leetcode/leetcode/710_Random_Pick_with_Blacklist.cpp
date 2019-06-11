//
//  710_Random_Pick_with_Blacklist.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/11/19.
//  Copyright © 2019 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_set<int> usb;
    unordered_map<int,int> um;
    int size;
public:
    Solution(int N, vector<int>& blacklist) {
        usb = unordered_set<int> (blacklist.begin(), blacklist.end());
        size = N - (int)blacklist.size();
        int next = N-1;
        for (int a: blacklist) {
            if (a >= N - blacklist.size()) {
                continue;
            }
            while (usb.find(next) != usb.end()) {
                next--;
            }
            um[a] = next;
            next--;
        }
    }

    int pick() {
        int index = rand() % size;
        return usb.find(index) != usb.end() ? um[index] : index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 710. Random Pick with Blacklist, C++ ...\n\n";

    int N = 4;
    vector<int> blacklist {0,1};
    Solution sol = Solution(N, blacklist);

    vector<int> count(N, 0);
    for (int i = 0; i < 10; i++) {
        cout << sol.pick() << '\n';
    }

    return 0;
}
