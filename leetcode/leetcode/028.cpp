//
//  028.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/3/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] != needle[0])
                continue;
            int k = i;
            int j;
            for (j = 0; j < needle.size(); j++) {
                if (k == haystack.size())
                    return -1;
                if (haystack[k] == needle[j])
                    k++;
                else
                    break;
            }
            if (j == needle.size())
                return i;
        }
        return -1;
    }

    int strStr0(string haystack, string needle) {
        return (int)haystack.find(needle);
    }

    int strStr2(string haystack, string needle) {   //  KMP
        if (needle.size() == 0)
            return 0;

        int T[needle.size()];
        T[0] = -1;
        for (int j = 1; j < needle.size(); j++) {
            if (T[j-1] > -1 && needle[j-1] == needle[T[j-1]])
                T[j] = T[j-1] + 1;
            else
                T[j] = 0;
            cout << needle[j] << ' ' << T[j] << '\n';
        }

        int i = 0, j = 0;
        while (i + j < haystack.size()) {
            if (haystack[i+j] == needle[j]) {
                if (j == needle.size() - 1)
                    return i;
                else
                    j++;
            } else {
                if (T[j] > -1) {
                    i = i + j - T[j];
                    j = T[j];
                } else {
                    i++;
                    j = 0;
                }
            }
        }
        return -1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 028 Implement strStr(), C++ ...\n\n";

    string haystack = "ABC ABCDAB ABCDABCDABDE";
    string needle = "ABCDABD";

    Solution sol;
    int index = sol.strStr2(haystack, needle);
    cout << "index = " << index << '\n';


    return 0;
}