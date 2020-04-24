//
//  718_Maximum_Length_of_Repeated_Subarray.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/9/20.
//  Copyright © 2020 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = (int)A.size(), n = (int)B.size(), r = 0;
        vector<vector<int>> dp (m, vector<int> (n, 0));

        dp[0][0] = A[0] == B[0] ? 1 : 0;
        for (int j = 1; j < n; j++) {
            dp[0][j] = A[0] == B[j] ? 1 : 0;
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = A[i] == B[0] ? 1 : 0;
            for (int j = 1; j < n; j++) {
                dp[i][j] = A[i] == B[j] ? dp[i-1][j-1] + 1 : 0;
                r = max(r, dp[i][j]);
            }
        }
        return r;
    }

    int findLength2(vector<int>& A, vector<int>& B) {
        int m = (int)A.size(), n = (int)B.size(), r = 0;
        vector<int> dp (n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = n-1; j >= 0; j--) {
                dp[j] = A[i] == B[j] ? (j >= 1 ? dp[j-1] + 1 : 1) : 0;
                r = max(r, dp[j]);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 718. Maximum Length of Repeated Subarray, C++ ...\n\n";
    Solution sol;

//    vector<int> A {1,2,3,2,1};
//    vector<int> B {3,2,1,4,7};

    vector<int> A {0,1,1,1,1};
    vector<int> B {1,0,1,0,1};


    int r = sol.findLength(A, B);
    cout << r << '\n';

    r = sol.findLength2(A, B);
    cout << r << '\n';

    return 0;
}

