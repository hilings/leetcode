//
//  028.c
//  leetcode
//
//  Created by Hang Zhang on 5/3/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int l2 = (int)strlen(needle);
    if (l2 == 0)
        return 0;
    int l1 = (int)strlen(haystack);
    for (int i = 0; i < l1; i++) {
        if (haystack[i] != needle[0])
            continue;
        int k = i;
        int j;
        for (j = 0; j < l2; j++) {
            if (k == l1)
                return -1;
            if (haystack[k] == needle[j])
                k++;
            else
                break;
        }
        if (j == l2)
            return i;
    }
    return -1;
}

int strStr0(char* haystack, char* needle) {
    if (strlen(needle) == 0)
        return 0;
    int index = (int)(strstr(haystack, needle) - haystack);
    if (index < 0 || index >= strlen(haystack))
        index = -1;
    return index;
}

int strStr2(char* haystack, char* needle) { //  KMP
    int l2 = (int)strlen(needle);
    if (l2 == 0)
        return 0;
    int T[l2];
    T[0] = -1;
    for (int j = 1; j < l2; j++) {
        if (T[j-1] > -1 && needle[j-1] == needle[T[j-1]])
            T[j] = T[j-1] + 1;
        else
            T[j] = 0;
        printf("%c %d\n", needle[j], T[j]);
    }
    int l1 = (int)strlen(haystack);
    int i = 0, j = 0;
    while (i + j < l1) {
        if (haystack[i+j] == needle[j]) {
            if (j == l2 - 1)
                return i;
            else
                j++;
        } else {
            if (T[j] > -1) {
                i = i + j - T[j];
                j = T[j];
            } else {
                i++;
                j = 0;
            }
        }
    }
    return -1;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 028 Implement strStr(), C ...\n\n");

    char *haystack = "ABC ABCDAB ABCDABCDABDE";
    char *needle = "ABCDABD";
    int index = strStr2(haystack, needle);
    printf("index = %d\n", index);

    return 0;
}