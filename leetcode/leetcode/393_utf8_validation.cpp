//
//  393_utf8_validation.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/15/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void itob(int i) {
        string s = "";
        for (int flag = 1<<7; flag > 0; flag = flag >> 1) {
            s += '0' + (i&flag ? 1 : 0);
        }
        cout << s << '\n';
    }

    bool validUtf8(vector<int>& data) {
        for (int i = 0, n = 1; i < data.size(); i++) {
            itob(data[i]);
            if ((data[i]>>7) == 0) {	// 1 byte
                continue;
            } else if ((data[i]>>5) == 0b110) {	// 2 bytes	110xxxxx 10xxxxxx
                n = 2;
            } else if ((data[i]>>4) == 0b1110) {	// 3 bytes	1110xxxx 10xxxxxx 10xxxxxx
                n = 3;
            } else if ((data[i]>>3) == 0b11110) {	// 4 bytes	11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
                n = 4;
            } else {	// unknown
                return false;
            }
            for (int j = i+1; j < i+n; j++) {
                itob(data[j]);
                if (j == data.size() || (data[j]>>6) != 0b10) {
                    return false;
                }
            }
            i += n-1;
        }
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 393. UTF-8 Validation, C++ ...\n\n";
    Solution sol;
    
    vector<int> data {
        //197, 130, 1	// true
        235, 140, 4	// false
    };
    
    bool r = sol.validUtf8(data);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}
