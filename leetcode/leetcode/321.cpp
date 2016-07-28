//
//  321.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/11/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = (int)nums1.size(), n2 = (int)nums2.size(), i = 0;
        vector<vector<int>> dp1 {vector<int> (nums1)};
        while (dp1.size() <= n1) {
            while (i+1 < dp1.back().size() && dp1.back()[i] >= dp1.back()[i+1])
                i++;
            vector<int> tv (dp1.back().begin(), dp1.back().begin()+i);
            tv.insert(tv.end(), dp1.back().begin()+i+1, dp1.back().end());
            dp1.push_back(tv);
            if (i > 0)
                i--;
        }
        reverse(dp1.begin(), dp1.end());
        //*
        for (int i = 0; i <= n1; i++) {
            cout << i << ": ";
            for (int a: dp1[i]) {
                cout << a << ' ';
            }
            cout << '\n';
        }
        //*/

        i = 0;
        vector<vector<int>> dp2 {vector<int> (nums2)};
        while (dp2.size() <= n2) {
            while (i+1 < dp2.back().size() && dp2.back()[i] >= dp2.back()[i+1])
                i++;
            vector<int> tv (dp2.back().begin(), dp2.back().begin()+i);
            tv.insert(tv.end(), dp2.back().begin()+i+1, dp2.back().end());
            dp2.push_back(tv);
            if (i > 0)
                i--;
        }
        reverse(dp2.begin(), dp2.end());
        //*
        for (int i = 0; i <= n2; i++) {
            cout << i << ": ";
            for (int a: dp2[i]) {
                cout << a << ' ';
            }
            cout << '\n';
        }
        //*/

        vector<int> ret (k, 0);
        for (int i = max(0, k-n2); i <= min(k, n1); i++) {
            vector<int> v3;
            myMerge(dp1[i], dp2[k-i], v3);
            for (int j = 0; j < k; j++) {	// update if greater
                if (v3[j] == ret[j])
                    continue;
                if (v3[j] > ret[j])
                    ret.swap(v3);
                break;
            }
        }
        return ret;
    }
    void myMerge(vector<int>& v1, vector<int>& v2, vector<int>& v3) {
        int n1 = (int)v1.size(), n2 = (int)v2.size(), i = 0, j = 0;
        while (i < n1 && j < n2) {
            int k = 0;
            while (i+k < n1 && j+k < n2 && v1[i+k] == v2[j+k])
                k++;
            v3.push_back((i+k < n1 && (j+k == n2 || v1[i+k] > v2[j+k])) ? v1[i++] : v2[j++]);
        }
        v3.insert(v3.end(), v1.begin()+i, v1.end());
        v3.insert(v3.end(), v2.begin()+j, v2.end());
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 321. Create Maximum Number, C++ ...\n\n";
    Solution sol;

    /*
     vector<int> nums1 {3,4,6,5};
     vector<int> nums2 {9,1,2,5,8,3};
     int k = 5;	// 9,8,6,5,3

     vector<int> nums1 {6,7};
     vector<int> nums2 {6,0,4};
     int k = 5;	// 6,7,6,0,4

     vector<int> nums1 {3,9};
     vector<int> nums2 {8,9};
     int k = 3;	// 9,8,9
     */

    /*
     vector<int> nums1 {2,5,6,4,4,0};
     vector<int> nums2 {7,3,8,0,6,5,7,6,2};
     int k = 15;	// 7,3,8,2,5,6,4,4,0,6,5,7,6,2,0

     vector<int> nums1 {1,6,5,4,7,3,9,5,3,7,8,4,1,1,4};
     vector<int> nums2 {4,3,1,3,5,9};
     int k = 21;	// 4,3,1,6,5,4,7,3,9,5,3,7,8,4,1,3,5,9,1,1,4
     */

    vector<int> nums1 {8,6,9};
    vector<int> nums2 {1,7,5};
    int k = 3;	//

    vector<int> r = sol.maxNumber(nums1, nums2, k);
    for (int a: r) {
        cout << a << ' ';
    }
    cout << '\n';
    
    return 0;
}