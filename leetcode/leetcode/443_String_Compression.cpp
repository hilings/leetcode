//
//  443_String_Compression.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/16/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        for (int i = 0, j, l, size = (int)chars.size(); i < size; i = j+1) {
            chars[index++] = chars[i];
            for (j = i, l = 1; j+1 < size && chars[j+1] == chars[i]; j++, l++);
            if (l > 1) {
                for (; l > 0; l /= 10) {
                    chars.push_back(l % 10 + '0');
                }
                for (; chars.size() > size; chars.pop_back()) {
                    chars[index++] = chars.back();
                }
            }
        }
        chars.erase(chars.begin()+index, chars.end());
        return (int)chars.size();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 443. String Compression, C++ ...\n\n";
    Solution sol;

    vector<char> chars {
        //'a', 'a', 'b', 'b', 'c', 'c', 'c'   // 6
        //'a' // 1
        //'a','b','b','b','b','b','b','b','b','b','b','b','b' // 4
        'o','o','o','o','o','o','o','o','o','o' // 3
    };
    int r = sol.compress(chars);
    for (char c: chars) {
        cout << c << ' ';
    }
    cout << '\n';

    cout << r << '\n';

    return 0;
}
