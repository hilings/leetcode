//
//  042.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/18/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int)height.size();
        if (n == 0)
            return 0;
        int lhigh[n], rhigh[n];
        lhigh[0] = height[0];
        rhigh[n-1] = height[n-1];
        for (int i = 1, j = n-1-i; i < n; i++,j--) {
            lhigh[i] = max(height[i], lhigh[i-1]);
            rhigh[j] = max(height[j], rhigh[j+1]);
        }
        int sum = 0;
        for (int i = 1; i < n-1; i++) {
            int roof = min(lhigh[i], rhigh[i]);
            if (height[i] < roof)
                sum += roof - height[i];
        }
        return sum;
    }

};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 042 Trapping Rain Water, C++ ...\n\n";
    
    //int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};  //6
    //int a[] = {0,7,1,4,6};    //7
    //int a[] = {5,2,1,2,1,5};    //14
    //int a[] = {9,6,8,8,5,6,3};    //3
    int a[] = {2,6,3,8,2,7,2,5,0};   //11
    //int a[] = {};
    vector<int> height (a, a + sizeof(a)/sizeof(int));
    
    Solution sol;
    int sum = sol.trap(height);
    cout << "sum = " << sum << '\n';
    
    return 0;
}