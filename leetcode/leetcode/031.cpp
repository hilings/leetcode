//
//  031.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/9/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1)
            return;
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i+1])
            i--;
        if (i >= 0) {
            int next = i+1;
            for (int j = i + 1; j < n; j++)
                if (nums[j] > nums[i] && nums[j] < nums[next])
                    next = j;
            int tmp = nums[i];
            nums[i] = nums[next];
            nums[next] = tmp;
        }
        sort(nums.begin()+i+1, nums.end());
        return;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 031 Next Permutation, C++ ...\n\n";

    int a[] = {1, 2, 2, 5};
    int n = sizeof(a) / sizeof(int);
    vector<int> nums;
    nums.assign(a, a+n);
    printVector(nums);

    Solution sol;
    for (int i = 0; i < 16; i++) {
        sol.nextPermutation(nums);
        printVector(nums);
    }

    return 0;
}