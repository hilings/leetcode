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

    char * res = longestPalindrome(s);
    printf("%s\n", res);

    return 0;
}
