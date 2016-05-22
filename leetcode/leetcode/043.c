//
//  043.c
//  leetcode
//
//  Created by Hang Zhang on 5/19/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int l1 = (int)strlen(num1);
    int l2 = (int)strlen(num2);
    char *s = (char*)malloc(sizeof(char)*(l1+l2+1));
    memset(s, '0', l1+l2);
    s[l1+l2] = '\0';
    for (int i = l1-1; i >= 0; i--) {
        int carry = 0;
        for (int j = l2-1; j >= 0; j--) {
            int tmp = (s[i+j+1]-'0') + (num1[i]-'0') * (num2[j]-'0') + carry;
            s[i+j+1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        s[i] += carry;
    }
    for (int i = 0; i < l1+l2; i++)
        if (s[i] != '0')
            return s+i;
    return "0";
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 43. Multiply Strings, C ...\n\n");

    char num1[] = "12";
    char num2[] = "23";
    printf("%s * %s = %s\n", num1, num2, multiply(num1, num2));

    return 0;
}