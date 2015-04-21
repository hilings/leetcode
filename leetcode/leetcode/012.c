//
//  012.c
//  leetcode
//
//  Created by Hang Zhang on 4/20/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* intToRoman(int num) {
    const int    n[] = {  1,    4,   5,    9,  10,   40,  50,   90, 100,  400, 500,  900, 1000};
    const char * c[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    
    char *str = (char*)malloc(sizeof(char)*32);
    int i = sizeof(n)/sizeof(int) - 1;
    while (num) {
        if (num < n[i]) {
            i--;
            continue;
        }
        strcat(str, c[i]);
        num -= n[i];
        
    }
    return str;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 012 Integer to Roman, C ... ...\n");
    
    for (int num = 0; num < 15; num++) {
        printf("%d %s\n", num, intToRoman(num));
    }

    return 0;
}