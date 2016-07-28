//
//  330.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/27/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPatches0(vector<int>& nums, int n) {
        vector<bool> covered (n+1, false);
        vector<int> reachable;

        for (int i = 1; i <= n; i++) {
            //cout << i << ' ';
        }
        cout << '\n';

        for (int i = 0; i < nums.size(); i++) {
            int k = (int)reachable.size();
            for (int j = 0; j < k; j++) {
                int tmp = reachable[j]+nums[i];
                if (tmp <= n && covered[tmp] == false) {
                    covered[tmp] = true;
                    reachable.push_back(tmp);
                }
            }
            if (nums[i] <= n && covered[nums[i]] == false) {
                covered[nums[i]] = true;
                reachable.push_back(nums[i]);
            }

        }

        //sort(reachable.begin(), reachable.end());
        for (int a: reachable) {
            //cout << a << ' ';
        }
        cout << '\n';

        int ret = 0;
        for (int i = 1; i <= n; i++) {
            if (covered[i] == true)
                continue;
            cout << "adding: " << i << '\n';

            int k = (int)reachable.size();
            for (int j = 0; j < k; j++) {
                int tmp = reachable[j]+i;
                if (tmp <= n && covered[tmp] == false) {
                    covered[tmp] = true;
                    reachable.push_back(tmp);
                }
            }
            covered[i] = true;
            reachable.push_back(i);
            ret++;

            //sort(reachable.begin(), reachable.end());
            for (int a: reachable) {
                //cout << a << ' ';
            }
            cout << '\n';
        }
        return ret;
    }
    int minPatches(vector<int>& nums, int n) {	// greedy
        int ret = 0, i = 0;
        long int cur = 1;
        while (cur <= n) {
            if (i < nums.size() && nums[i] <= cur) {
                cur += nums[i++];
            } else {
                cur += cur;
                ret++;
            }
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 330. Patching Array, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {1,3};
    int n = 6;
    
    //vector<int> nums {1,5,10};
    //int n = 20;
    
    //vector<int> nums {1,2,2};
    //int n = 5;
    
    //vector<int> nums {1,2,31,33};
    //int n = 2147483647;
    
    //int r0 = sol.minPatches0(nums, n);
    //cout << r0 << '\n';
    
    int r = sol.minPatches(nums, n);
    cout << r << '\n';
    
    return 0;
}