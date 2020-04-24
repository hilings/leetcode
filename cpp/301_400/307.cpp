//
//  307.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/22/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class NumArray0 {
    vector<int> numi;
    vector<int> sumi;
public:
    NumArray0(vector<int> &nums) {
        sumi.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            numi.push_back(nums[i]);
            sumi.push_back(sumi[i]+nums[i]);
        }
    }

    void update(int i, int val) {
        int diff = val - numi[i];
        numi[i] = val;
        for (int j = i+1; j < sumi.size(); j++) {
            sumi[j] += diff;
        }
    }

    int sumRange(int i, int j) {
        int ret = sumi[j+1] - sumi[i];
        cout << ret << '\n';
        return sumi[j+1] - sumi[i];
    }
};

class NumArray {
    vector<int> numi;
    vector<int> sumi;
    int n;

    void updateSum(int i, int diff) {
        i++;
        while (i <= n) {
            sumi[i] += diff;
            i += i & -i;
        }
    }
    int getSum(int i) {
        i++;
        int ret = 0;
        while (i > 0) {
            ret += sumi[i];
            i -= i & -i;
        }
        return ret;
    }
public:
    NumArray(vector<int> &nums) {
        n = (int)nums.size();
        sumi.insert(sumi.end(), n+1, 0);
        for (int i = 0; i < n; i++) {
            numi.push_back(nums[i]);
            updateSum(i, nums[i]);
        }
    }

    void update(int i, int val) {
        updateSum(i, val-numi[i]);
        numi[i] = val;
    }

    int sumRange(int i, int j) {
        int ret = getSum(j) - getSum(i-1);
        cout << ret << '\n';
        return getSum(j) - getSum(i-1);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 307. Range Sum Query - Mutable, C++ ...\n\n";

    // Your NumArray object will be instantiated and called as such:
    vector<int> nums {1,3,5};
    
    NumArray numArray(nums);
    
    numArray.sumRange(0, 2);	// 9
    numArray.update(1, 2);
    numArray.sumRange(0, 2);	// 8
    
    numArray.sumRange(0, 1);	// 3
    numArray.update(1, 10);
    numArray.sumRange(1, 2);	// 15
    
    return 0;
}