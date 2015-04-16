//
//  008.c
//  leetcode
//
//  Created by Hang Zhang on 4/14/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int myAtoi(char* str) {
    int len = (int)strlen(str);
    int i = 0;
    while (i < len && isspace((int)str[i])){
        i++;
    }
    
    int sign = 1;
    if (i < len && (str[i] == '+' || str[i] == '-')) {
        sign = (str[i] == '+') ? 1 : -1;
        i++;
    }
    
    long int z = 0;
    while (i < len && isdigit(str[i]) && z < INT_MAX) {
        z = z * 10 + (int)(str[i] - '0');
        i++;
    }
    if (z > INT_MAX) {
        return (sign == 1) ? INT_MAX : INT_MIN;
    }
    return (int)(sign * z);
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 008 String to Integer (atoi), C ... ...\n");

    printf("%d", myAtoi("\r+2147483648"));
    return 0;
}
