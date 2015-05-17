//
//  038.c
//  leetcode
//
//  Created by Hang Zhang on 5/14/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char* countAndSay(int n) {
    char* s = (char*)malloc(sizeof(char)*pow(2,n/2)+10);
    strcpy(s, "1");
    for (int i = 1; i < n; i++) {
        printf("%d -> %s    %ld\n", i, s, strlen(s));
        int l = (int)strlen(s);
        int count = 1;
        char *tmp = (char*)malloc(sizeof(char)*pow(2,n/2)+10);
        int index = 0;
        int j;
        for (j = 1; j < l; j++) {
            if (s[j] == s[j-1])
                count++;
            else {
                tmp[index++] = '0'+count;
                tmp[index++] = s[j-1];
                count = 1;
            }
        }
        tmp[index++] = '0'+count;
        tmp[index++] = s[j-1];
        tmp[index] = '\0';
        strcpy(s, tmp);
    }
    printf("%d -> %s    %ld", n, s, strlen(s));
    return s;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 038 Count and Say, C ...\n\n");

    int n = 30;
    countAndSay(n);

    return 0;
}