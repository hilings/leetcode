//
//  030.c
//  leetcode
//
//  Created by Hang Zhang on 5/9/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(int a[], int n) {
    printf("[%d", a[0]);
    for (int i = 1; i < n; i++) {
        printf(", %d", a[i]);
    }
    printf("]\n");
}

void printWords(char **words, int wordsSize) {
    for (int i = 0; i < wordsSize; i++) {
        printf("%d -> %s\n", i, words[i]);
    }
    printf("\n");
}

int wordIndex(char** dict, int dictSize, char *word) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(dict[i], word) == 0)
            return i;
    }
    return -1;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    printf("s = %s\n", s);
    //printWords(words, wordsSize);

    int* v;
    if (wordsSize == 0)
        return v;
    int size = (int)strlen(words[0]);
    if (size == 0)
        return v;

    int len = (int)strlen(s);
    int sublen = size * wordsSize;
    v = (int*)malloc(sizeof(int) * (len-sublen+1));
    *returnSize = 0;

    char** dict = (char**)malloc(sizeof(char*)*wordsSize);
    int dictCount[wordsSize];
    int dictSize = 0;
    int j;

    int tindex;
    for (j = 0; j < wordsSize; j++) {   // put words in dict
        tindex = wordIndex(dict, dictSize, words[j]);
        if (tindex == -1) {
            dict[dictSize] = words[j];
            dictCount[dictSize] = 1;
            dictSize++;
        } else {
            dictCount[tindex]++;
        }
    }

    for (j = 0; j < dictSize; j++) {
        printf("%s -> %d\n", dict[j], dictCount[j]);
    }

    char word[size+1];
    word[size] = '\0';

    for (j = 0; j < size; j++) {
        int left = j;
        int tdictCount[dictSize];
        for (int k = 0; k < dictSize; k++)
            tdictCount[k] = 0;
        for (int i = j; i <= len - size; i += size) {
            tindex = wordIndex(dict, dictSize, strncpy(word, s+i, size));
            if (tindex > -1) {
                tdictCount[tindex]++;
                while (tdictCount[tindex] > dictCount[tindex]) {
                    tdictCount[wordIndex(dict, dictSize, strncpy(word, s+left, size))]--;
                    left += size;
                }
                if (i - left == sublen - size) {    // found one
                    v[(*returnSize)++] = left;
                    tdictCount[wordIndex(dict, dictSize, strncpy(word, s+left, size))]--;
                    left += size;
                }
            } else {    // word not in dict
                left = i + size;
                for (int k = 0; k < dictSize; k++)
                    tdictCount[k] = 0;
            }
        }
    }
    return v;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 030 Substring with Concatenation of All Words, C ...\n\n");

    //char *s = "barfoothefoobarman";
    //char *words[] = {"foo", "bar"};

    char* s = "abababab";
    char* words[] = {"a","b"};

    int wordsSize = sizeof(words) / sizeof(char*);

    int *returnSize = (int*)malloc(sizeof(int));

    int* v = findSubstring(s, words, wordsSize, returnSize);
    printArray(v, *returnSize);

    return 0;
}