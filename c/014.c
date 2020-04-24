//
//  014.c
//  leetcode
//
//  Created by Hang Zhang on 4/20/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0)
        return "";
    int l0 = (int)strlen(strs[0]);
    char *prefix = (char*)malloc(sizeof(char) * (l0+1));
    prefix[0] = '\0';
    for (int i = 0; i < l0; i++) {
        char c = strs[0][i];
        for (int j = 0; j < strsSize; j++) {
            if (i >= (int)strlen(strs[j]) || strs[j][i] != c)
                return prefix;
        }
        prefix[i] = c;
        prefix[i+1] = '\0';
    }
    return prefix;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 014 Longest Common Prefix, C ... ...\n");
    
    int strsSize = 2;
    char **strs = (char**)malloc(sizeof(char*) * strsSize);
    strs[0] = "abc";
    strs[1] = "";
    //strs[2] = "abe";

    for (int i = 0; i < strsSize; i++) {
        printf("%s\n", strs[i]);
    }
    printf("prefix = %s\n", longestCommonPrefix(strs, strsSize));
    return 0;
}