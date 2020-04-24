//
//  088.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/8/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printV(vector<int> v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while (i>=0 && j>=0) {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while (i>=0) {
            nums1[k--] = nums1[i--];
        }
        while (j>=0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 088 Merge Sorted Array, C++ ...\n\n";
    Solution sol;
    vector<int> nums1 {1,3,5,7};
    int m = (int)nums1.size();
    vector<int> nums2 {2,4,6,8};
    int n = (int)nums2.size();
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    
    printV(nums1);
    printV(nums2);
    
    sol.merge(nums1, m, nums2, n);
    printV(nums1);
    
    return 0;
}