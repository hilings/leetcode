//
//  011.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/19/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v) {
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << '\n';
    }
    cout << '\n';
}

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = (int)height.size() - 1;
        int maxA = 0;
        while (i < j) {
            maxA = max(maxA, (j-i) * min(height[i], height[j]));
            height[i] < height[j] ? i++ : j--;
        }
        return maxA;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 011 Container With Most Water, C++ ... ...\n";
    
    int a[] = {1, 3, 1, 2};
    vector<int> v;
    v.assign(a, a+sizeof(a)/sizeof(int));
    printVector(v);
    
    Solution sol;
    cout << sol.maxArea(v);
    
    return 0;
}