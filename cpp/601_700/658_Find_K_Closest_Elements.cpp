//
//  658_Find_K_Closest_Elements.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/26/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> r;
        int begin = (int)arr.size() - k;
        for (; begin-1 >= 0 && abs(arr[begin-1]-x) <= abs(arr[begin-1+k]-x); begin--);
        return vector<int> (arr.begin()+begin, arr.begin()+begin+k);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 658. Find K Closest Elements, C++ ...\n\n";
    Solution sol;

    vector<int> arr {
        //1,2,3,4,5     // 1,2,3,4
        //1     // 1
        0,0,0,1,3,5,6,7,8,8     // 1,3
    };
    int k = 3;
    k = 1;
    k = 2;

    int x = 5;
    x = 0;
    x = 2;

    vector<int> r = sol.findClosestElements(arr, k, x);
    for (int a: r) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}
