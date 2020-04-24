//
//  679_24_Game.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/31/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    float eps = 0.0001;
    bool op2to24(float a, float b) {
        for (float ab: op2tomany(a, b)) {
            if (abs(ab-24) < eps) {
                return true;
            }
        }
        return false;
    }
    vector<float> op2tomany(float a, float b) {
        vector<float> r {a+b, a-b, b-a,a*b};
        if (b > eps) {
            r.push_back(1.0*a/b);
        }
        if (a > eps) {
            r.push_back(1.0*b/a);
        }
        return r;
    }
    bool op3to24(vector<float> v) {   // expect v.size() == 3
        for (int i = 0; i <= 1; i++) {
            for (int j = i+1; j <= 2; j++) {
                int k = 3-i-j;
                for (float ab: op2tomany(v[i], v[j])) {
                    if (op2to24(ab, v[k])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        for (int i = 0; i <= 2; i++) {
            for (int j = i+1, k, l; j <= 3; j++) {
                for (k = 0; k <= 3 && (k == i || k == j); k++);
                l = 6-i-j-k;
                for (float ab: op2tomany(nums[i], nums[j])) {
                    if (op3to24(vector<float> {ab, (float)nums[k], (float)nums[l]})) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool judgePoint24b(vector<int>& nums) {
        vector<float> v;
        for (int a: nums) {
            v.push_back((float)a);
        }
        return helper(v);
    }
    bool helper(vector<float>& v) {
        if (v.size() == 1) {
            return abs(v[0] - 24) < eps;
        }
        for (int i = 0; i < v.size()-1; i++) {
            for (int j = i+1; j < v.size(); j++) {
                float a = v[i], b = v[j];
                v.erase(v.begin()+j);
                v.erase(v.begin()+i);
                for (float ab: op2tomany(a,b)) {
                    v.push_back(ab);
                    if (helper(v)) {
                        return true;
                    }
                    v.pop_back();
                }
                v.insert(v.begin()+i, a);
                v.insert(v.begin()+j, b);
            }
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 679. 24 Game, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,2,3,4     // true
        //4,1,8,7     // true
        //8,1,6,6     //true
        3,3,8,5     // true
    };

    bool r = sol.judgePoint24(nums);
    cout << (r ? "true" : "false") << '\n';

    bool r2 = sol.judgePoint24b(nums);
    cout << (r2 ? "true" : "false") << '\n';

    return 0;
}
