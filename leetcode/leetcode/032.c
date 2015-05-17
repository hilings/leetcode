//
//  032.c
//  leetcode
//
//  Created by Hang Zhang on 5/10/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int n = (int)strlen(s);
    int stack[n];
    int top = -1;
    stack[++top] = -1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            stack[++top] = i;
        else if (stack[top] != -1 && s[stack[top]] == '(')
            count = count < i - stack[--top] ? i - stack[top] : count;
        else
            stack[++top] = i;
    }
    return count;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 032 Longest Valid Parentheses, C ...\n\n");

    char *s = "()()";
    printf("%s\n", s);

    printf("%d\n", longestValidParentheses(s));
    return 0;
}