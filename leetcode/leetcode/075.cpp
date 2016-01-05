//
//  075.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/4/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printV(vector<int> v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = (int)nums.size()-1;
        while (i < j) {
            while (i < nums.size() && nums[i] == 0)
                i++;
            while (j >= 0 && nums[j] >= 1)
                j--;
            if (i < j) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        j = (int)nums.size()-1;
        while (i < j) {
            while (i < nums.size() && nums[i] == 1)
                i++;
            while (j >= 0 && nums[j] == 2)
                j--;
            if (i < j) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }

    void sortColors2(vector<int>& nums) {
        int i = 0, zero = 0, two = (int)nums.size()-1;
        while (i <= two) {
            if (nums[i] == 0) {
                int tmp = nums[i];
                nums[i] = nums[zero];
                nums[zero] = tmp;
                zero++;
                i++;
            } else if (nums[i] == 2) {
                int tmp = nums[i];
                nums[i] = nums[two];
                nums[two] = tmp;
                two--;
            } else {
                i++;
            }
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 075 Sort Colors, C++ ...\n\n";
    Solution sol;

    vector<int> nums {2,1,0,2,0,2,1,0,2};

    sol.sortColors2(nums);

    printV(nums);
    
    return 0;
}