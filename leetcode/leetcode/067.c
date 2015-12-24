//
//  067.c
//  leetcode
//
//  Created by Hang Zhang on 12/21/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    if (strlen(a) < strlen(b))
        return addBinary(b, a);
    int i = (int)strlen(a)-1, j = (int)strlen(b)-1, c = 0;
    while (j >= 0) {
        int t = a[i]-'0' + b[j]-'0' + c;
        a[i] = '0' + t%2;
        c = t / 2;
        i--;
        j--;
    }
    while (i >= 0) {
        int t = a[i]-'0' + c;
        a[i] = '0' + t%2;
        c = t / 2;
        i--;
    }
    if (c == 1) {
        char *r = (char*)malloc(sizeof(char)*(strlen(a)+1));
        strcpy(r, "1");
        strcat(r, a);
        return r;
    }
    return a;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 067 Add Binary, C ...\n\n");

    char a[] = "11000111110010001100000111110110100110011110100010010101";
    char b[] = "111101001101010101001010000100001111010100101111010011";

    char *r = addBinary(a, b);
    printf("%s\n", r);

    return 0;
}