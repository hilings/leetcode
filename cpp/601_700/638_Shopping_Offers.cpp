//
//  638_Shopping_Offers.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/23/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    void dfs0(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int& r, int sum) {
        int n = (int)price.size();
        for (int i = 0; i < special.size(); i++) {
            bool apply = true;
            for (int j = 0; j < n; j++) {
                if (special[i][j] > needs[j]) {
                    apply = false;
                    break;
                }
            }
            if (!apply) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                needs[j] -= special[i][j];
            }
            dfs0(price, special, needs, r, sum+special[i].back());
            for (int j = 0; j < n; j++) {
                needs[j] += special[i][j];
            }
        }
        for (int j = 0; j < n; j++) {
            sum += price[j] * needs[j];
        }
        r = min(r, sum);
    }

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<int,int>& um) {
        int sum = 0, n = (int)needs.size(), state = 1;
        for (int i = 0; i < n; i++) {
            state = state * 10 + needs[i];
        }
        if (um.find(state) != um.end()) {
            return um[state];
        }
        for (int j = 0; j < n; j++) {
            sum += price[j] * needs[j];
        }
        for (int i = 0; i < special.size(); i++) {
            bool apply = true;
            for (int j = 0; j < n; j++) {
                if (special[i][j] > needs[j]) {
                    apply = false;
                    break;
                }
            }
            if (!apply) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                needs[j] -= special[i][j];
            }
            sum = min(sum, special[i].back() + dfs(price, special, needs, um));
            for (int j = 0; j < n; j++) {
                needs[j] += special[i][j];
            }
        }
        um[state] = sum;
        return sum;
    }
public:
    int shoppingOffers0(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int r = INT_MAX;
        dfs0(price, special, needs, r, 0);
        return r;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<int,int> um;
        return dfs(price, special, needs, um);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 638. Shopping Offers, C++ ...\n\n";
    Solution sol;

    vector<int> price {
        //2,5
        2,3,4
    };
    vector<vector<int>> special {
        /*
        {3,0,5},
        {1,2,10}
         */

        {1,1,0,4},
        {2,2,1,9}
    };
    vector<int> needs {
        //3,2   // 14
        1,2,1   // 11
    };

    int r0 = sol.shoppingOffers0(price, special, needs);
    cout << r0 << '\n';

    int r = sol.shoppingOffers(price, special, needs);
    cout << r << '\n';

    return 0;
}
