//
//  670_Maximum_Swap.cpp
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
    int maximumSwap(int num) {
        vector<int> v;
        for ( ; num > 0; num /= 10) {
            v.push_back(num%10);
        }
        int n = (int)v.size(), swapwith = n;
        for (int i = n-2; i >= 0; i--) {
            if (swapwith == n && v[i] > v[i+1]) {
                swapwith = i;
            }
            if (swapwith != n && v[i] >= v[swapwith]) {
                swapwith = i;
            }
        }
        for (int i = n-1; i >= 0 && swapwith != n; i--) {
            if (v[i] < v[swapwith]) {
                swap(v[i], v[swapwith]);
                break;
            }
        }
        for (int i = n-1; i >= 0; i--) {
            num = num*10 + v[i];
        }
        return num;
    }

    int maximumSwap2(int num) {
        string s = to_string(num);
        int n = (int)s.size(), maxi = n-1, left = n-1, right = n-1;
        for (int i = n-2; i >= 0; i--) {
            if (s[i] < s[maxi]) {
                left = i;
                right = maxi;
            } else if (s[i] > s[maxi]){
                maxi = i;
            }
        }
        swap(s[left], s[right]);
        return stoi(s);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 670. Maximum Swap, C++ ...\n\n";
    Solution sol;

    int num = 2736; // 7236
    num = 9936;     // 9963
    num = 98368;    // 98863

    int r = sol.maximumSwap(num);
    cout << r << '\n';

    int r2 = sol.maximumSwap2(num);
    cout << r2 << '\n';

    return 0;
}
