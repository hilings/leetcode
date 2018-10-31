//
//  20181029_airbnb2_nestedarray.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/29/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> input;
    size_t i, j;

    void init(vector<vector<int>> myinput) {
        input = myinput;
        j = 0;
        for (i = 0; i < input.size(); i++) {
            for (; j < input[i].size(); j++) {
                return;
            }
            j = 0;
        }
    }

    bool hasNext() {
        if (i == input.size()) {
            return false;
        }
        return true;
    }

    int next() {
        if (!hasNext()) {
            return -1;  //
        }
        int r = input[i][j];
        j++;
        for (; i < input.size(); i++) {
            for (; j < input[i].size(); j++) {
                return r;
            }
            j = 0;
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 000 XXX, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> input {
        {},
        {},
        {1,2,3},
        {4,5},{},{},
        {6},{7,8},{},{9},{10},{}
    };

    sol.init(input);

    cout << input[0].size() << std::endl;

    while (sol.hasNext()) {
        cout << sol.next() << ' ';
    }
    cout << '\n';

    return 0;
}
