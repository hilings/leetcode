//
//  167.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/9/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        for (int index1 = 0, index2 = (int)numbers.size()-1; index1 < index2; ) {
            if (numbers[index1] + numbers[index2] < target) {
                index1++;
            } else if (numbers[index1] + numbers[index2] > target) {
                index2--;
            } else {
                return vector<int> {index1+1, index2+1};
            }
        }
        return v;
    }
};
int main(int arg, char *argv[]) {
    // insert code here...
    cout << "167. Two Sum II - Input array is sorted, C++ ...\n\n";
    Solution sol;

    vector<int> numbers = {2, 9, 11, 15};
    int target = 11;
    vector<int> v = sol.twoSum(numbers, target);
    for (int a: v) {
        cout << a << ' ';
    }
    return 0;
}
