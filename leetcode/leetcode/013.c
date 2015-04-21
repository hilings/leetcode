//
//  013.c
//  leetcode
//
//  Created by Hang Zhang on 4/20/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int romanToInt(char* s) {
    const int  n[] = {  1,   5,  10,  50, 100, 500, 1000};
    const char c[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M' };
    int num = 0;
    int i = sizeof(n)/sizeof(int) - 1;
    int len = (int)strlen(s);
    int p = 0;
    while (p < len) {
        if (s[p] == c[i+2]) {
            num = num - n[i] * 2 + n[i+2];
            i--;
            p++;
        } else if (s[p] == c[i+1]) {
            num = num - n[i] * 2 + n[i+1];
            i--;
            p++;
        } else if (s[p] == c[i]) {
            num += n[i];
            p++;
        } else {
            i--;
        }
    }
    return num;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 012 Integer to Roman, C ... ...\n");

    char *s = "I";
    printf("%s %d\n", s, romanToInt(s));
    
    return 0;
}