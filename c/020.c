//
//  020.c
//  leetcode
//
//  Created by Hang Zhang on 4/28/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    char stack[80];
    int p = -1;
    for (int i = 0; i < strlen(s); i++) {
        if (p == -1)
            stack[++p] = s[i];
        else if ( (s[i] == ')' && stack[p] == '(') || (s[i] == ']' && stack[p] == '[') || (s[i] == '}' && stack[p] == '{') )
            p--;
        else
            stack[++p] = s[i];
    }
    return p == -1;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 020 Valid Parentheses, C ... ...\n");
    
    char *s = "]";
    printf("%s\n", s);
    printf("%s\n", isValid(s) ? "True" : "False");
    return 0;
}