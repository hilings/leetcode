//
//  005.c
//  leetcode
//
//  Created by Hang Zhang on 4/11/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestPalindrome(char *s) {
// central expansion
    int slen = (int)strlen(s);
    if (slen <= 1) {
        return s;
    }
    
    int longest_start = 0;
    int longest_len = 1;
    
    for (int i = 1; i < slen; i++) {
        // palindrome even length
        int p = i;
        int q = p - 1;
        while (q >= 0 && p < slen && s[q] == s[p]) {
            p++;
            q--;
        }
        int tlen = p - q - 1;
        if (tlen > longest_len) {
            longest_start = q + 1;
            longest_len = tlen;
        }
        // palindrome odd length
        p = i;
        q = p - 2;
        while (q >= 0 && p < slen && s[q] == s[p]) {
            p++;
            q--;
        }
        tlen = p - q - 1;
        if (tlen > longest_len) {
            longest_start = q + 1;
            longest_len = tlen;
        }
    }
    char *substring = (char*)malloc(sizeof(char)*(longest_len + 1));
    strncpy(substring, s + longest_start, longest_len);
    substring[longest_len] = '\0';
    return substring;
}

char *longestPalindrome2(char *s) {
// Manacher's algorithm
    int slen = (int)strlen(s);
    if (slen <= 1)
        return s;
    
    int tlen = 2*slen + 4;
    char *T = (char*)malloc(sizeof(char)*tlen);
    strcpy(T, "^#");
    for (int i = 0; i < slen; i++) {
        T[i*2+2] = s[i];
        T[i*2+3] = '#';
    }
    strcat(T, "$");
    
    int P[tlen];
    P[0] = 0;
    int R = 0;
    int C = 0;
    int maxC = 0;
    for (int i = 1; i < tlen - 1; i++) {
        if (i >= R) {
            P[i] = 0;
        } else {
            P[i] = (R-i < P[2*C-i]) ? R-i : P[2*C-i];
        }
        while (T[i+P[i]+1] == T[i-P[i]-1]) {
            P[i]++;
        }
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
            if (P[i] > P[maxC])
                maxC = C;
        }
    }
    char *res = (char*)malloc(sizeof(char)*(P[maxC]+1));
    strncat(res, s + (maxC-P[maxC]-1) / 2, P[maxC]);
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("LeetCode 005 Longest Palindromic Substring, C ... ...\n");
    
    //char s[] = "";
    //char s[] = "a";
    //char s[] = "aa";
    //char s[] = "ab";
    //char s[] = "abc";
    //char s[] = "abb";
    //char s[] = "aba";
    //char s[] = "aaa";
    char s[] = "forgeeksskeegfor";
    //char s[] = "cabcbabcbabcba";
    //char s[] = "habacdedcabag";
    //char s[] = "ABCBAHELLOHOWRACECARAREYOUIAMAIDOINGGOOD";

    char * res = longestPalindrome2(s);
    printf("%s\n", res);

    return 0;
}