//
//  017.c
//  leetcode
//
//  Created by Hang Zhang on 4/23/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(char **v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", i, v[i]);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    char **r;
    int len = (int)strlen(digits);
    if (len == 0) {
        *returnSize = 0;
        return r;
    }

    char *map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int size = 1;
    for (int i = 0; i < len; i++) {
        int d = digits[i] - '0';
        if (d > 1)
            size *= (int)strlen(map[d]);
    }

    r = (char**)malloc(sizeof(char*) * size);
    for (int i = 0; i < size; i++) {
        r[i] = (char*)malloc(sizeof(char*) * (len+1));
    }

    int block = size;
    for (int i = 0; i < len; i++) {
        int d = digits[i] - '0';
        char *letters = map[d];
        int num_letters = (int)strlen(letters);
        block /= num_letters;
        for (int j = 0; j < num_letters; j++) {
            int p = j * block;
            while (p < size) {
                for (int k = 0; k < block; k++) {
                    r[p+k][i] = letters[j];
                    r[p+k][i+1] = '\0';
                }
                p += block * num_letters;
            }
        }
    }
    *returnSize = size;
    return r;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 017 Letter Combinations of a Phone Number, C ... ...\n");
    
    char digits[] = "29";
    printf("%s\n", digits);

    int *returnSize = (int*)malloc(sizeof(int));
    *returnSize = 3;
    
    char **v = letterCombinations(digits, returnSize);
    printArray(v, *returnSize);
    
    return 0;
}