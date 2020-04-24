//
//  275.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex0(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int n = (int)citations.size(), i = 0, j = n-1;
        while (i < j) {
            int m = (i+j) / 2;
            if (citations[m] == n-m)
                return n-m;
            if (citations[m] < n-m)
                i = m+1;
            else
                j = m;
        }
        return citations[i] == 0 ? 0 : n-i;
    }
    int hIndex(vector<int>& citations) {
        int n = (int)citations.size(), i = 0, j = n-1;
        while (i <= j) {
            int m = (i+j) / 2;
            if (citations[m] >= n-m)
                j = m-1;
            else
                i = m+1;
        }
        return n-i;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 275. H-Index II, C++ ...\n\n";
    Solution sol;
    
    vector<int> citations {
        //0,1,3,5,6	// 3
        //0,1	// 1
        //100	// 1
        0	// 0
    };
    
    int r = sol.hIndex(citations);
    cout << r << '\n';
    
    return 0;
}