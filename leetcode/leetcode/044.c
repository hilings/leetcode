//
//  044.c
//  leetcode
//
//  Created by Hang Zhang on 6/23/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isMatch(char* s, char* p) {
    int l1 = (int)strlen(s);
    int l2 = (int)strlen(p);

    int ast = 0;
    for (int j = 0; j < l2; j++) {
        if (p[j] == '*')
            ast++;
    }
    if (l1 < l2 - ast)
        return false;

    bool m[l1+1];
    memset(m+1, false, l1);
    m[0] = true;

    for (int j = 0; j < l2; j++) {
        if (p[j] == '*') {
            for (int i = 1; i <= l1; i++) {
                m[i] = m[i-1] || m[i];
            }
        } else {
            for (int i = l1; i > 0; i--) {
                m[i] = m[i-1] && (s[i-1] == p[j] || p[j] == '?');
            }
            m[0] = false;
        }
    }
    return m[l1];
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 044 Wildcard Matching, C ...\n\n");

    /*
     isMatch("aa","a") → false
     isMatch("aa","aa") → true
     isMatch("aaa","aa") → false
     isMatch("aa", "*") → true
     isMatch("aa", "a*") → true
     isMatch("ab", "?*") → true
     isMatch("aab", "c*a*b") → false
     */
    
    char s[] = "abc";
    char p[] = "*abd*";

    printf("%s  %s\n", s, p);
    printf("%s\n", isMatch(s, p) ? "true" : "false");

    return 0;
}