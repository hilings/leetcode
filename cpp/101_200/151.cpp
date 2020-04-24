//
//  151.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/3/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int length = (int)s.size(), tail = (int)s.find_last_not_of(' ');
        if (tail < 0) {
            s.clear();
            return;
        }
        while (tail >= 0) {
            int head = tail;
            while (head-1 >= 0 && s[head-1] != ' ')
                head--;
            s += " " + s.substr(head, tail+1-head);
            tail = head-1;
            while (tail >= 0 && s[tail] == ' ')
                tail--;
        }
        s = s.substr(length+1);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 151. Reverse Words in a String, C++ ...\n\n";
    Solution sol;

    string s = "  the sky is blue  ";
    s = "";
    cout << "^" << s << "$\n";
    
    sol.reverseWords(s);
    cout << "^" << s << "$\n";
    
    return 0;
}