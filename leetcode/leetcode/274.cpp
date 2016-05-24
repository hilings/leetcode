//
//  274.cpp
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
        sort(citations.begin(), citations.end());
        int n = (int)citations.size();
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n-i)
                return n-i;
        }
        return 0;
    }
    int hIndex(vector<int>& citations) {
        int n = (int)citations.size();
        vector<int> buckets (n+1, 0);
        for (int a: citations) {
            if (a >= n)
                buckets[n]++;
            else
                buckets[a]++;
        }
        int count = 0;
        for (int i = n; i >= 0; i--) {
            count += buckets[i];
            if (count >= i)
                return i;
        }
        return 0;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 274. H-Index, C++ ...\n\n";
    Solution sol;
    
    vector<int> citations {
        3,0,6,1,5	// 3
        //0,1	// 1
    };
    
    int r = sol.hIndex(citations);
    cout << r << '\n';
    
    return 0;
}