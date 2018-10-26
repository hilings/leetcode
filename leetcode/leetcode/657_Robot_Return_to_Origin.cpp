//
//  657_Robot_Return_to_Origin.cpp
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
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c: moves) {
            switch (c) {
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
            }
        }
        return x == 0 && y == 0;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 657. Robot Return to Origin, C++ ...\n\n";
    Solution sol;

    string moves = "UD";

    bool r = sol.judgeCircle(moves);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
