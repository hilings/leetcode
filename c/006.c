//
//  006.c
//  leetcode
//
//  Created by Hang Zhang on 4/12/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *convert(char *s, int nRows) {
    int len = (int)strlen(s);
    char *str = (char*)malloc(sizeof(char)*(len + 1));
    if (nRows == 1) {
        strcpy(str, s);
        return str;
    }
    int index = 0;
    for (int r = 0; r < nRows; r++) {
        for (int i = r; i < len; i += 2*nRows - 2) {
            str[index++] = s[i];
            if (r != 0 && r != nRows - 1) {
                int t = i + 2*nRows - 2 - 2*r;
                if (t < len) {
                    str[index++] = s[t];
                }
            }
        }
    }
    str[len] = '\0';
    return str;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 006 ZigZag Conversion, C ... ...\n");
               // 01234567890123
    //char s[] = "PAYPALISHIRING";
             // PAHNAPLSIIGYIR
    char s[] = "0123456789";
    //char s[] = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
    int nRows = 4;

    printf("%s\n", s);
    printf("%s\n", convert(s, nRows));
    return 0;
}