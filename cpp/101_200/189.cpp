//
//  189.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void reverse(vector<int> &nums, int i, int j) {
        while (i < j) {
            int tmp = nums[i];
            nums[i++] = nums[j];
            nums[j--] = tmp;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {	// in place
        int N = (int)nums.size();
        k %= N;
        reverse(nums, N-k, N-1);
        reverse(nums, 0, N-k-1);
        reverse(nums, 0, N-1);
    }

    void rotate0(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> v (nums.end()-k, nums.end());
        v.insert(v.end(), nums.begin(), nums.end()-k);
        nums.swap(v);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 189. Rotate Array, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,2,3,4,5,6,7};
    int k = 3;
    
    sol.rotate(nums, k);
    
    for (int a: nums) {
        cout << a << ' ';
    }
    cout << '\n';
    
    return 0;
}