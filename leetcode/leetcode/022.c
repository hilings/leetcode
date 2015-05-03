//
//  022.c
//  leetcode
//
//  Created by Hang Zhang on 4/29/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printVector(char**v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", v[i]);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int size = (int)pow(3, n);
    char **stack = (char**)malloc(sizeof(char*) * size);
    if (n == 0)
        return stack;
    
    int front = 0, back = 0;
    stack[back++] = "(";

    while (strlen(stack[front]) < 2*n) {
        /*
        for (int i = 0; i < size; i++)
            printf("stack[%d] %s\n", i, stack[i]);
         */
        
        char *s = stack[front++];
        //printf("front = %d back = %d s = %s\n", front, back, s);
        int l = 0, r = 0;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '(')
                l++;
            else
                r++;
        }
        //printf("l = %d r = %d\n", l, r);
        
        char *tmp1 = (char*)malloc(sizeof(char*)*(2*n+1));
        strcpy(tmp1, s);
        if (l < n) {
            stack[back++] = strcat(tmp1, "(");
            //printf("l<n, push stack[%d] %s\n", back, stack[back-1]);
        }
        
        char *tmp2 = (char*)malloc(sizeof(char*)*(2*n+1));
        strcpy(tmp2, s);
        if (l > r) {
            stack[back++] = strcat(tmp2, ")");
            //printf("l>r, push stack[%d] %s\n", back, stack[back-1]);
        }
    }
    
    *returnSize = back-front;
    
    char **v = (char**)malloc(sizeof(char*) * *returnSize);
    int i = 0;
    while (front != back) {
        v[i++] = stack[front++];
    }
    
    //printVector(v, *returnSize);
    printf("returnSize = %d\n", *returnSize);
    
    return v;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 022 Generate Parentheses, C ... ...\n");

    int n = 4;
    printf("n = %d\n", n);
    
    int *returnSize = (int*)malloc(sizeof(int));
    *returnSize = 2;
    
    generateParenthesis(n, returnSize);
    
    return 0;
}