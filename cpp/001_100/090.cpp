//
//  090.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/8/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void printV(vector<int> v) {
    cout << "[";
    for (auto a: v) {
        cout << ' ' << a;
    }
    cout << " ]\n";;
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> m {vector<int> {}};
        map<int,int> om;
        for (auto a: nums)
            om.find(a) == om.end() ? om[a] = 1 : om[a]++;
        size_t index = 0;
        for (auto it = om.begin(); it != om.end(); it++) {
            size_t size = m.size();
            for (; index < size; index++)
                for (int k = 0; k <= it->second; k++) {
                    vector<int> tv (m[index]);
                    vector<int> tmp (k, it->first);
                    tv.insert(tv.end(), tmp.begin(), tmp.end());
                    m.push_back(tv);
                }
        }
        m.erase(m.begin(), m.begin()+index);
        return m;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 090 Subsets II, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {1,2,2};
    
    vector<vector<int>> r = sol.subsetsWithDup(nums);
    for (auto v: r) {
        printV(v);
    }
    
    return 0;
}