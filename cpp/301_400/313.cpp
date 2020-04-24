//
//  313.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/29/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = (int)primes.size();
        vector<int> uglies {1};
        vector<int> indices (k, 0);
        for (int i = 1; i < n; i++) {
            int next = INT_MAX;
            for (int j = 0; j < k; j++) {
                next = min(next, primes[j] * uglies[indices[j]]);
            }
            for (int j = 0; j < k; j++) {
                if (primes[j] * uglies[indices[j]] == next)
                    indices[j]++;
            }
            uglies.push_back(next);
        }
        for (int i = 0; i < uglies.size(); i++) {
            cout << i+1 << ": " << uglies[i] << '\n';;
        }
        return uglies[n-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 313. Super Ugly Number, C++ ...\n\n";
    Solution sol;

    int n = 12;
    vector<int> primes {
        2,7,13,19	//1,2,4,7,8,13,14,16,19,26,28,32
    };
    
    int r = sol.nthSuperUglyNumber(n, primes);
    cout << r << '\n';
    
    return 0;
}