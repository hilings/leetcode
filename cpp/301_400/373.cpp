//
//  373.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/3/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

bool cmp (pair<int,int> a, pair<int,int> b) {
    return a.first+a.second < b.first+b.second;
}

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs0(vector<int>& nums1, vector<int>& nums2, int k) {	// brute force
        vector<pair<int,int>> r;
        for (int a: nums1) {
            for (int b: nums2) {
                pair<int,int> p (a, b);
                r.insert(lower_bound(r.begin(), r.end(), p, cmp), p);
                if (r.size() > k) {
                    r.pop_back();
                }
            }
        }
        return r;
    }

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {	// priority_queue
        vector<pair<int,int>> r;
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first+a.second > b.first+b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> minHeap(cmp);

        for (int a: nums1) {
            for (int b: nums2) {
                minHeap.push(pair<int,int> (a, b));
            }
        }
        while (minHeap.size() && k--) {
            r.push_back(minHeap.top());
            minHeap.pop();
        }
        return r;
    }

    vector<pair<int, int>> kSmallestPairs2(vector<int>& nums1, vector<int>& nums2, int k) {	// index array
        vector<pair<int,int>> r;
        int m = (int)nums1.size(), n = (int)nums2.size();
        vector<int> indices (m, 0);
        int size = min(k, m*n);
        while (size) {
            vector<int> tv {};
            for (int i = 0; i < m; i++) {
                if (indices[i] == n)
                    continue;
                int cur = nums1[i] + nums2[indices[i]], tmax = tv.empty() ? INT_MAX : nums1[tv.back()] + nums2[indices[tv.back()]];
                if (cur < tmax) {
                    tv.clear();
                    tv.push_back(i);
                } else if (cur == tmax) {
                    tv.push_back(i);
                }
            }
            for (int i: tv) {
                r.push_back(pair<int,int> (nums1[i], nums2[indices[i]++]));
                if (--size == 0)
                    break;
            }
        }
        return r;
    }

    vector<pair<int, int>> kSmallestPairs3(vector<int>& nums1, vector<int>& nums2, int k) {	// combine priority_queue and index array
        vector<pair<int,int>> r;
        if (nums1.empty() || nums2.empty())
            return r;
        auto cmp = [&nums1, &nums2](const pair<int,int>& a, const pair<int,int>& b) {
            return nums1[a.first]+nums2[a.second] > nums1[b.first]+nums2[b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> minHeap(cmp);
        minHeap.push(pair<int,int> (0, 0));

        while (!minHeap.empty() && k--) {
            int i = minHeap.top().first, j = minHeap.top().second;
            minHeap.pop();
            r.push_back(pair<int,int> (nums1[i], nums2[j]));
            if (j+1 < nums2.size()) {
                minHeap.push(pair<int,int> (i, j+1));
            }
            if (j == 0 && i+1 < nums1.size()) {
                minHeap.push(pair<int,int> (i+1, j));
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 373. Find K Pairs with Smallest Sums, C++ ...\n\n";
    Solution sol;

    /*
     vector<int> nums1 {1,7,11};
     vector<int> nums2 {2,4,6};	//[1,2],[1,4],[1,6]
     int k = 3;

     vector<int> nums1 {1,1,2};
     vector<int> nums2 {1,2,3};	//[1,1],[1,1]
     int k = 2;

     vector<int> nums1 {1,2};
     vector<int> nums2 {3};	//[1,3],[2,3]
     int k = 3;

     vector<int> nums1 {1,2,4,5,6};
     vector<int> nums2 {3,5,7,9};	//[1,3],[2,3],[1,5]
     int k = 3;

     */

    vector<int> nums1 {1,1,2};
    vector<int> nums2 {1,2,3};	//[1,1],[1,1],[2,1],[1,2],[1,2],[2,2],[1,3],[1,3],[2,3]
    int k = 10;
    
    
    vector<pair<int,int>> r0 = sol.kSmallestPairs0(nums1, nums2, k);
    for (pair<int,int> p: r0) {
        cout << p.first << "," << p.second << '\n';
    }
    cout << '\n';
    
    vector<pair<int,int>> r = sol.kSmallestPairs(nums1, nums2, k);
    for (pair<int,int> p: r) {
        cout << p.first << "," << p.second << '\n';
    }
    cout << '\n';
    
    vector<pair<int,int>> r2 = sol.kSmallestPairs2(nums1, nums2, k);
    for (pair<int,int> p: r2) {
        cout << p.first << "," << p.second << '\n';
    }
    cout << '\n';
    
    vector<pair<int,int>> r3 = sol.kSmallestPairs3(nums1, nums2, k);
    for (pair<int,int> p: r3) {
        cout << p.first << "," << p.second << '\n';
    }
    cout << '\n';
    
    return 0;
}
