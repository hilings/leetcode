//
//  179.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/14/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp (string a, string b) {
    return a+b > b+a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (int a: nums) {
            v.push_back(to_string(a));
        }
        sort(v.begin(), v.end(), cmp);
        if (v[0] == "0")
            return "0";
        string ret = "";
        for (string s: v) {
            ret += s;
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 179. Largest Number, C++ ...\n\n";
    Solution sol;

    //vector<int> nums {3, 30, 34, 5, 9};
    //vector<int> nums {1440,7548,4240,6616,733,4712,883,8,9576};
    //vector<int> nums {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> nums {1,2,0};
    
    string r = sol.largestNumber(nums);
    cout << r << '\n';
    
    return 0;
}