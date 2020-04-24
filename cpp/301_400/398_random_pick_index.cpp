//
//  398_random_pick_index.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/20/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>	// rand()
using namespace std;

class Solution {
    vector<int> v;
public:
    Solution(vector<int> nums) {
        v = nums;
    }

    int pick(int target) {
        int r = -1;
        for (int i = 0, k = 0; i < v.size(); i++) {
            if (v[i] != target) {
                continue;
            }
            k++;
            if (rand() % k == 0) {	// reservoir sampling, 1/k probability to replace, (k-1)/k probability to keep
                r = i;
            }
        }
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 398. Random Pick Index, C++ ...\n\n";

    vector<int> nums {1,2,3,3,3};
    Solution sol(nums);
    
    printf("%d: %d\n", 3, sol.pick(3));
    
    return 0;
}
