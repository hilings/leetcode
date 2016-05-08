//
//  215.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/25/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (const int& a, const int& b) {
        return a > b;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
    int findKthLargest2(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, cmp> q;
        for (int a: nums) {
            q.push(a);
            if (q.size() > k)
                q.pop();
        }
        return q.top();
    }
    int findKthLargest3(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        int ret = nums[0];
        for (int i = 0; i < k; i++) {
            ret = nums.front();
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return ret;
    }

    int findKthLargest4(vector<int>& nums, int k) {	// QuickSelect
        int left = 0, right = (int)nums.size()-1;
        while (left < right) {
            int i = left+1, j = right, pivot = nums[left];
            while (i <= j) {
                while (i <= j && nums[i] >= pivot)
                    i++;
                while (i <= j && nums[j] <= pivot)
                    j--;
                if (i < j)
                    swap(nums[i], nums[j]);
            }
            //cout << "i = " << i << ", j = " << j << '\n';
            swap(nums[left], nums[j]);
            if (j == k-1)
                return nums[j];
            else if (j < k-1)
                left = j+1;
            else
                right = j-1;
        }
        return nums[left];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 215. Kth Largest Element in an Array, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {2,1};
    int k = 1;
    
    int r = sol.findKthLargest4(nums, k);
    cout << r << '\n';
    
    return 0;
}