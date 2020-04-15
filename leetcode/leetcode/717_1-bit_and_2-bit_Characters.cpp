//
//  717_1-bit_and_2-bit_Characters.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/24/19.
//  Copyright © 2019 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for (int i = 0; i < bits.size(); i += bits[i] + 1) {
            if (i == bits.size()-1) {
                return true;
            }
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 717. 1-bit and 2-bit Characters, C++ ...\n\n";
    Solution sol;

    vector<int> bits {
//        1,0,0   // true
        1,1,1,0 // false
    };
    bool r = sol.isOneBitCharacter(bits);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}

