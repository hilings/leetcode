//
//  384.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/14/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
    vector<int> mynums;
public:
    Solution(vector<int> nums) {
        mynums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return mynums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> r = mynums;
        for (int i = (int)mynums.size()-1; i >= 0; i--) {
            int index = rand() % (i+1);
            int pick = r[index];
            r[index] = r[i];
            r[i] = pick;
        }
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 384. Shuffle an Array, C++ ...\n\n";

    // Init an array with set 1, 2, and 3.
    vector<int> nums {1,2,3};
    Solution solution(nums);

    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
    solution.shuffle();

    // Resets the array back to its original configuration [1,2,3].
    solution.reset();

    // Returns the random shuffling of array [1,2,3].
    solution.shuffle();

    for (int i = 0; i < 10; i++) {
        for (int a: solution.shuffle()) {
            cout << a << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
