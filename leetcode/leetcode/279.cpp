//
//  279.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares0(int n) {
        static unordered_map<int,int> um {{0,0}};
        if (um.find(n) != um.end())
            return um[n];
        //cout << n << '\n';
        int ret = n;
        for (int i = sqrt(n); i > 0; i--) {
            ret = min(ret, 1+numSquares(n-i*i));
            if (ret == 1)
                break;
        }
        um[n] = ret;
        //cout << n << ": " << ret << '\n';
        return ret;
    }

    int numSquares(int n) {
        static vector<int> cache {0};
        if (cache.size() >= n+1)
            return cache[n];
        //cout << n << '\n';
        while (cache.size() < n+1) {
            int tmp = n;
            for (int i = 1; i*i <= n; i++) {
                tmp = min(tmp, 1+numSquares(n-i*i));
            }
            cache.push_back(tmp);
        }
        return cache[n];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 279. Perfect Squares, C++ ...\n\n";
    Solution sol;
    
    int n = 12;
    
    int r = sol.numSquares0(n);
    cout << r << '\n';
    
    return 0;
}