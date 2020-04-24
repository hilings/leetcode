//
//  363.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;

class Solution {
    int maxSubarrayk(vector<int>& v, int k) {	// with limit k, nlog(n)
        int r = INT_MIN, sofar = 0;

        for (int a: v) {	// quit sooner if max <= k, kadane algorithm, O(n)
            sofar = max(sofar+a, a);
            r = max(r, sofar);
            if (r == k) {
                return r;
            }
        }
        if (r <= k) {
            return r;
        }

        r = INT_MIN;
        sofar = 0;
        set<int> os {0};
        for (int a: v) {
            sofar += a;
            auto it = os.lower_bound(sofar-k);
            if (it != os.end()) {
                r = max(r, sofar - *it);
            }
            os.insert(sofar);
        }
        return r;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {	// with limit k, apply maxSubarrayk, O(col^2*row*log(row))
        int rows = (int)matrix.size(), cols = (int)matrix[0].size(), r = INT_MIN;
        for (int L = 0; L < cols; L++) {
            vector<int> v (rows, 0);
            for (int R = L; R < cols; R++) {
                for (int i = 0; i < rows; i++) {
                    v[i] += matrix[i][R];
                    //cout << v[i] << ' ';
                }
                //cout << '\n';
                r = max(r, maxSubarrayk(v, k));
                if (r == k) {
                    return r;
                }
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 363. Max Sum of Rectangle No Larger Than K, C++ ...\n\n";
    Solution sol;
    
    vector<vector<int>> matrix {
        /*
         vector<int> {1, 0, 1},
         vector<int> {0, -2, 3}	// 2
         */
        
        //*
        vector<int> {2, 2, -1}	// k = 3, 3
        //*/
        
        /*
         vector<int> {2, 1, -3, -4, 5},
         vector<int> {0, 6, 3, 4, 1},
         vector<int> {2, -2, -1, 4, -5},
         vector<int> {-3, 3, 1, 0, 3}
         */
    };
    int k = 3;
    
    int r = sol.maxSumSubmatrix(matrix, k);
    cout << r << '\n';
    
    return 0;
}
