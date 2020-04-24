//
//  204.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/31/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

class Solution {
public:
    // Sieve of Eratosthenes
    int countPrimes0(int n) {
        vector<bool> isP (n, true);
        int count = 0;
        for (int i = 2; i < n; i++) { // go through every possible factor i
            if (isP[i] == false)
                continue;
            count++;
            for (int j = i; j < n; j += i) { // mark all numerator of factor i
                isP[j] = false;
            }
        }
        return count;
    }

    int countPrimes1(int n) {
        if (n <= 2)
            return 0;
        vector<bool> isP (n+1, true);
        int count = 1;
        for (int i = 3; i*i <= n; i += 2) {	// check only possible odd factor i
            if (isP[i] == false)
                continue;
            for (int j = i*i; j < n; j += 2*i)	// mark all odd numerator of i as none-prime
                isP[j] = false;
        }
        for (int i = 3; i < n; i += 2) { // count total prime
            if (isP[i] == true)
                count++;
        }
        return count;
    }

    int countPrimes2(int n) {
        if (n <= 2)
            return 0;
        int count = n/2, m = sqrt(n-1); // consider only odd number, plus 2 but not 1
        //vector<bool> isP (n, true);
        bool *isP = new bool[n];
        memset(isP, true, n);
        for (int i = 3; i <= m; i += 2) { // check only possible odd factor i
            if (isP[i] == false)
                continue;
            for (int j = i*i; j < n; j += 2*i) { // mark all odd numerator of i as none-prime
                if (isP[j] == true) {
                    isP[j] = false;
                    count--;
                }
            }
        }
        delete []isP;
        return count;
    }
    
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 204. Count Primes, C++ ...\n\n";
    Solution sol;
    
    int n = 9;
    n = 1500000;	// 114155
    
    int r = sol.countPrimes0(n);
    cout << r << '\n';
    
    r = sol.countPrimes1(n);
    cout << r << '\n';
    
    r = sol.countPrimes2(n);
    cout << r << '\n';
    
    return 0;
}