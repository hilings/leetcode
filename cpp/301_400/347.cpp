//
//  347.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/13/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent0(vector<int>& nums, int k) {	// insert sort
        unordered_map<int,int> map_count;
        for (int a: nums) {
            map_count[a] = map_count.find(a) == map_count.end() ? 1 : map_count[a]+1;
        }
        vector<int> v_count;
        vector<int> v_num;
        for (pair<int,int> p: map_count) {
            auto pos = lower_bound(v_count.begin(), v_count.end(), p.second) - v_count.begin();
            v_count.insert(v_count.begin() + pos, p.second);
            v_num.insert(v_num.begin()+pos, p.first);
        }
        return vector<int> (v_num.rbegin(), v_num.rbegin()+k);
    }

    vector<int> topKFrequent1(vector<int>& nums, int k) {	// bucket sort
        unordered_map<int,int> um;
        for (int a: nums) {
            um[a] = um.find(a) == um.end() ? 1 : um[a]+1;
        }
        vector<vector<int>> bucket (nums.size()+1, vector<int> {});
        for (pair<int,int> p: um) {
            bucket[p.second].push_back(p.first);
        }
        vector<int> r;
        for (int i = (int)bucket.size()-1; i >= 0; i--) {
            for (int a: bucket[i]) {
                r.push_back(a);
                if (r.size() == k)
                    return r;
            }
        }
        return r;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {	// priority_queue
        unordered_map<int,int> um;
        for (int a: nums) {
            um[a] = um.find(a) == um.end() ? 1 : um[a]+1;
        }
        vector<int> r;
        priority_queue<pair<int,int>> pq;
        for (pair<int,int> p: um) {
            pq.push(pair<int,int> (p.second, p.first));
            if (pq.size() > um.size()-k) {
                r.push_back(pq.top().second);
                pq.pop();
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 347. Top K Frequent Elements, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,1,1,2,2,3};
    int k = 2;
    
    vector<int> r0 = sol.topKFrequent0(nums, k);
    for (auto a: r0) {
        cout << a << ", ";
    }
    
    cout << '\n';
    
    vector<int> r1 = sol.topKFrequent1(nums, k);
    for (auto a: r1) {
        cout << a << ", ";
    }
    
    cout << '\n';
    
    vector<int> r = sol.topKFrequent(nums, k);
    for (auto a: r) {
        cout << a << ", ";
    }
    
    
    return 0;
}
