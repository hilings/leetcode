//
//  668_Kth_Smallest_Number_in_Multiplication_Table.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/28/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthNumber0(int m, int n, int k) {   // brute force
        vector<int> v;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cout << i*j << ' ';
                v.push_back(i*j);
            }
            cout << '\n';

        }
        sort(v.begin(), v.end());
        return v[k-1];
    }

    int findKthNumber(int m, int n, int k) {    // binary search
        int low = 1, high = m*n;
        while (low < high) {
            int mid = (low+high) / 2, count = 0;
            for (int i = 1; i <= m; i++) {
                count += min(mid/i, n);
            }
            if (count < k) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 668. Kth Smallest Number in Multiplication Table, C++ ...\n\n";
    Solution sol;

    int m = 3;
    int n = 3;
    int k = 5;

    int r0 = sol.findKthNumber0(m, n, k);
    cout << r0 << '\n';

    int r = sol.findKthNumber(m, n, k);
    cout << r << '\n';

    return 0;
}
