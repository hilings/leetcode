//
//  016.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/22/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int l = (int)num.size();
        if (l < 3)
            return 0;
        sort(num.begin(), num.end());
        int diff = numeric_limits<int>::max();
        int sum = 0;
        for (int i = 0; i < l - 2; i++) {
            if (i-1 >= 0 && num[i] == num[i-1])
                continue;
            int j = i + 1;
            int k = l - 1;
            while (j < k) {
                int t = num[i] + num[j] + num[k];
                int d = abs(t - target);
                if (d < diff) {
                    diff = d;
                    sum = t;
                }
                if (t < target) {
                    j++;
                } else if (t > target) {
                    k--;
                } else {
                    return sum;
                }
            }
        }
        return sum;
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 016 3Sum Closest, C++ ... ...\n";
    
    int a[] = {-1, 2, 1, -4};
    vector<int> num;
    num.assign(a, a+sizeof(a)/sizeof(int));
    int target = 1;
    
    Solution sol;
    cout << sol.threeSumClosest(num, target);
    
    return 0;
}