//
//  502_IPO.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/14/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        auto cmpMin = [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmpMin)> minC(cmpMin);    // all projects, min capital on top
        priority_queue<int> maxP;   // store affordable projects, max profit on top

        for (int i = 0; i < Capital.size(); i++) {
            if (Profits[i] <= 0) {
                continue;
            }
            if (Capital[i] <= W) {
                maxP.push(Profits[i]);
                printf("pushing doable (%d)\n", Profits[i]);
            } else {
                minC.push(pair<int,int> (Profits[i], Capital[i]));
                printf("pushing optional (%d, %d)\n", Profits[i], Capital[i]);
            }
        }

        while (k > 0 && !maxP.empty()) {
            W += maxP.top();
            printf("doing %d\n", maxP.top());
            maxP.pop();
            k--;
            while (!minC.empty() && minC.top().second <= W) {
                maxP.push(minC.top().first);
                printf("moving (%d, %d)\n", minC.top().first, minC.top().second);
                minC.pop();
            }
        }
        return W;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 502. IPO, C++ ...\n\n";
    Solution sol;

    int k = 2;
    int W = 0;
    vector<int> Profits {
        1,2,3
    };
    vector<int> Capitals {
        0,1,1
    };

    int r = sol.findMaximizedCapital(k, W, Profits, Capitals);
    cout << r << '\n';

    return 0;
}
