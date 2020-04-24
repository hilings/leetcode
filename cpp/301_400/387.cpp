//
//  387.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/27/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n = (int)s.size(), r = n;
        vector<int> cache (26, n);
        for (int i = 0; i < n; i++) {
            int c = s[i]-'a';
            if (cache[c] == n) {
                cache[c] = i;
            } else if (cache[c] < n) {
                cache[c] = n+1;
            }
        }
        for (int i: cache) {
            if (i < r)
                r = i;
        }
        return r < n ? r : -1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 387. First Unique Character in a String, C++ ...\n\n";
    Solution sol;

    string s = "leetcode";
    int r = sol.firstUniqChar(s);
    cout << r << '\n';

    s = "loveleetcode";
    r = sol.firstUniqChar(s);
    cout << r << '\n';

    return 0;
}
