//
//  591_Tag_Validator.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/14/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
    bool isValidTAGNAME(string s) {
        size_t n = s.size();
        if (n == 0 || n > 9) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!isupper(s[i])) {
                return false;
            }
        }
        return true;
    }
    void printTab(size_t n) {
        for (size_t i = 0; i < n; i++) {
            printf("\t");
        }
    }
public:
    bool isValid(string code) {
        size_t n = code.size();
        stack<string> stk;
        for (size_t i = 0; i < n; ) {
            if (i > 0 && stk.empty()) { // not wrapped
                printf("not wrapped\n");
                return false;
            } else if (code.substr(i, 9) == "<![CDATA[") {  // CDATA
                printTab(stk.size());
                printf("<![CDATA]\n");
                size_t pos = code.find("]]>", i+9);
                if (pos == string::npos) {
                    printf("no ]]> for CDATA\n");
                    return false;
                }
                string CDATA_CONTENT = code.substr(i+9, pos-i-9);
                printTab(stk.size()+1);
                printf("%s\n", CDATA_CONTENT.c_str());
                printTab(stk.size());
                printf("]]>\n");
                i = pos+3;
            } else if (code.substr(i, 2) == "</") { // TAG_NAME end
                printTab(stk.size()-1);
                size_t pos = code.find('>', i+2);
                if (pos == string::npos) {  // no > for TAG_NAME
                    printf("no > for TAG_NAME\n");
                    return false;
                }
                string TAG_NAME = code.substr(i+2, pos-i-2);
                if (!isValidTAGNAME(TAG_NAME)) {
                    printf("invalid TAG_NAME: %s\n", TAG_NAME.c_str());
                    return false;
                }
                if (stk.empty() || stk.top() != TAG_NAME) {    // unmatched TAG_NAME
                    printf("unbalanced TAG_NAME: %s %s\n", stk.top().c_str(), TAG_NAME.c_str());
                    return false;
                }
                printf("</%s>\n", TAG_NAME.c_str());
                stk.pop();
                i = pos+1;
            } else if (code[i] == '<') {   // TAG_NAME start
                printTab(stk.size());
                size_t pos = code.find('>', i+1);
                if (pos == string::npos) {  // no > for TAG_NAME
                    printf("no > for TAG_NAME\n");
                    return false;
                }
                string TAG_NAME = code.substr(i+1, pos-i-1);
                if (!isValidTAGNAME(TAG_NAME)) {
                    printf("invalid TAG_NAME %s\n", TAG_NAME.c_str());
                    return false;
                }
                printf("<%s>\n", TAG_NAME.c_str());
                stk.push(TAG_NAME);
                i = pos+1;
            } else {    // regular
                printTab(stk.size());
                size_t pos = code.find('<', i+1);
                if (pos == string::npos) {  // through end
                    printf("not wrapped\n");
                    return false;
                }
                string regular = code.substr(i, pos-i);
                printf("%s\n", regular.c_str());
                i = pos;
            }
        }
        if (!stk.empty()) {
            printf("unmatched tag <%s>\n", stk.top().c_str());
        }
        return stk.empty();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 591. Tag Validator, C++ ...\n\n";
    Solution sol;

    string code = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"; // true
    //code = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";  // true

    //code = "<A>  <B> </A>   </B>";  // false
    //code = "<DIV>  div tag is not closed  <DIV>";   // false
    //code = "<DIV>  unmatched <  </DIV>";    // false
    //code = "<DIV> closed tags with invalid tag name  <b>123</b> </DIV>";    // false
    //code = "<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>"; // false
    //code = "<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>";    // false

    code = "<![CDATA[wahaha]]]><![CDATA[]> wahaha]]>";    // false
    code = "<A></A><B></B>";    // false    not wrapped
    //code = "<A><A></A></A>";    // true

    bool r = sol.isValid(code);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
