//
//  009.c
//  leetcode
//
//  Created by Hang Zhang on 4/14/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include <string.h>

bool isPalindrome(int x) {
//  scan from two ends
    if (x < 0)
        return false;
    long int shade = 1;
    while (x >= shade * 10) {
        shade *= 10;
    }
    while (shade >= 10 && (x / shade == x % 10)) {
        x %= shade;
        x /= 10;
        shade /= 100;
    }
    return shade < 10;
}

bool isPalindrome2(int x) {
//  reverse and compare
    if (x < 0)
        return false;
    int y = x;
    long int z = 0;
    while (y) {
        z = z * 10 + y % 10;
        y /= 10;
    }
    if (z > INT_MAX)
        return false;
    return (int)z == x;
}

bool isPalindrome3(int x) {
//  itoa
    if (x < 0)
        return false;
    char s[11];
    sprintf(s, "%d", x);
    for (int i = 0, j = (int)strlen(s) - 1; i < j; i++, j--) {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 009 Palindrome Number, C ... ...\n");
    
    int x = -1874994781;
    printf("%d %s\n", 1, isPalindrome3(x) ? "True" : "False");
    
    return 0;
}