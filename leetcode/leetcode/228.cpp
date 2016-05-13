//
//  228.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/10/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        for (int i = 0; i < nums.size(); i++) {
            int j = i;
            while (j+1 < nums.size() && nums[j+1] == nums[j]+1)
                j++;
            if (i < j) {
                ret.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
                i = j;
            } else {
                ret.push_back(to_string(nums[i]));
            }
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 228. Summary Ranges, C++ ...\n\n";
    Solution sol;

    vector<int> nums {0,1,2,4,5,7};
    
    vector<string> r = sol.summaryRanges(nums);
    for (string s: r) {
        cout << s << '\n';
    }
    
    return 0;
}