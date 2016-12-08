//
//  331.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/28/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int count = 1;
        for (int i = 0; i < preorder.size(); i+=2) {
            if (count == 0)
                return false;
            if (isdigit(preorder[i])) {
                count++;
                while (i+1 < preorder.size() && preorder[i+1] != ',')
                    i++;
            } else {	// #
                count--;
            }
        }
        return count == 0;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 331. Verify Preorder Serialization of a Binary Tree, C++ ...\n\n";
    Solution sol;

    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    preorder = "1,#";
    preorder = "9,#,#,1";
    
    bool r = sol.isValidSerialization(preorder);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}