//
//  010.c
//  leetcode
//
//  Created by Hang Zhang on 4/17/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    while (*p) {
        if (*(p+1) == '*') {
            if (*s != *p && *p != '.') {
                p+=2;
            } else if (isMatch(s, p+2)) {
                return true;
            } else if (*s == *p || (*p == '.' && *s != '\0')) {
                s++;
            } else {
                return false;
            }
        } else if (*s == *p || (*p == '.' && *s != '\0')) {
            s++;
            p++;
        } else {
            return false;
        }
    }
    return *s == '\0' && *p == '\0';
}

bool isMatch2(char *s, char *p){
    int l1 = (int)strlen(s);
    bool* m = malloc(sizeof(bool) * (l1+1));
    m[0] = true;
    for (int i = 1; i <= l1; i++) {
        m[i] = false;
    }

    for (; *p != '\0'; p++) {
        if (*(p+1) == '*') {
            continue;
        } else if (*p == '*') {
            char c = *(p-1);
            for (int i = 1; i <= l1; i++) {
                m[i] = m[i] || (m[i - 1] && (s[i - 1] == c || c == '.'));
            }
        } else {
            char c = *p;
            for (int i = l1; i > 0; i--) {
                m[i] = m[i - 1] && (s[i - 1] == c || c == '.');
            }
            m[0] = false;
        }
    }

    bool r = m[l1];
    free(m);
    return r;
}


int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 010 Regular Expression Matching, C ... ...\n");
    /*
     isMatch("aa","a") → false
     isMatch("aa","aa") → true
     isMatch("aaa","aa") → false
     isMatch("aa", "a*") → true
     isMatch("aa", ".*") → true
     isMatch("ab", ".*") → true
     isMatch("aab", "c*a*b") → true
     */
    char s[] = "";
    char p[] = "a";
    //char s[] = "aaa";
    //char p[] = "a*a";
    //char s[] = "ab";
    //char p[] = ".*..c*";
    //char s[] = "baccbbcbcacacbbc";
    //char p[] = "c*.*b*c*ba*b*b*.a*";
    //char s[] = "aa";
    //char p[] = ".*";

    printf("%s  %s\n", s, p);
    printf("%s\n", isMatch2(s, p) ? "true" : "false");
    
    return 0;
}