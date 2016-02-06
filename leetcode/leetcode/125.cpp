//
//  125.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/5/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = (int)s.size()-1;
        while (i < s.size() && j >= 0 && i < j) {
            if (!isdigit(s[i]) && !isalpha(s[i]))
                i++;
            else if (!isdigit(s[j]) && !isalpha(s[j]))
                j--;
            else if (tolower(s[i++]) != tolower(s[j--]))
                return false;
        }
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 125 Valid Palindrome, C++ ...\n\n";
    Solution sol;

    string s = "A man, a plan, a canal: Panama";	//true
    //s = "race a car";		//false
    //s = "";	//true
    s = ".,";	//true
    bool r = sol.isPalindrome(s);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}