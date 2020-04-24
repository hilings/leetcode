//
//  605_Can_Place_Flowers.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/18/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int r = 0, l = (int)flowerbed.size();
        for (int i = 0; i < l; ) {
            if (flowerbed[i] == 1) {
                i += 2;
            } else if (i-1 >= 0 && flowerbed[i-1] == 1) {
                i++;
            } else if (i+1 < l && flowerbed[i+1] == 1) {
                i += 3;
            } else {
                r++;
                i += 2;
            }
        }
        return r >= n;
    }

    bool canPlaceFlowers2(vector<int>& flowerbed, int n) {
        int r = 0, l = (int)flowerbed.size();
        for (int i = 0; i < l; i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == l-1 || flowerbed[i+1] == 0)) {
                r++;
                i++;
            }
        }
        return r >= n;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 605. Can Place Flowers, C++ ...\n\n";
    Solution sol;

    vector<int> flowerbed {
        1,0,0,0,1   // true
    };
    int n = 1;
    n = 2;  // false

    bool r = sol.canPlaceFlowers(flowerbed, n);
    cout << (r ? "true" : "false" ) << '\n';

    return 0;
}
