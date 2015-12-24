//
//  068.c
//  leetcode
//
//  Created by Hang Zhang on 12/21/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *joinLine(char **line, int size, int maxWidth, bool last) {
    char *s = (char*)malloc(sizeof(char) * (maxWidth));
    strcpy(s, "");
    if (size == 1 || last == true) {
        for (int i = 0; i < size-1; i++) {
            strcat(s, line[i]);
            strcat(s, " ");
            maxWidth -= strlen(line[i])+1;
        }
        strcat(s, line[size-1]);
        maxWidth -= strlen(line[size-1]);
        s[strlen(s)+maxWidth] = '\0';        
        memset(s+strlen(s), ' ', maxWidth);
        return s;
    }
    for (int i = 0; i < size; i++)
        maxWidth -= strlen(line[i]);
    int space = maxWidth / (size-1);
    int extra = maxWidth % (size-1);
    for (int i = 0; i < extra; i++) {
        strcat(s, line[i]);
        s[strlen(s)+space+1] = '\0';
        memset(s+strlen(s), ' ', space+1);
    }
    for (int i = extra; i < size-1; i++) {
        strcat(s, line[i]);
        s[strlen(s)+space] = '\0';
        memset(s+strlen(s), ' ', space);
    }
    strcat(s, line[size-1]);
    return s;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char **v = (char**)malloc(sizeof(char*) * wordsSize);
    char **line = (char**)malloc(sizeof(char*) * wordsSize);
    *returnSize = 0;
    int length = 0;
    int index = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (strlen(words[i]) > maxWidth) {
            return v;
        } else if (length == 0) {
            line[index++] = words[i];
            length += strlen(words[i]);
        } else if (length + strlen(words[i]) + 1 <= maxWidth) {
            line[index++] = words[i];
            length += strlen(words[i]) + 1;
        } else {
            v[(*returnSize)++] = joinLine(line, index, maxWidth, false);
            index = 0;
            length = 0;
            i--;
        }
    }
    v[(*returnSize)++] = joinLine(line, index, maxWidth, true);
    return v;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 068 Text Justification, C ...\n\n");

    int wordsSize = 42;
    int maxWidth = 26;
    int *returnSize = (int*)malloc(sizeof(int));
    char *words[] = {
        //"This", "is", "an", "example", "of", "text", "justification."
        //"Imagination", "is", "more", "important", "than", "knowledge."
        //"My", "momma", "always", "said,", "\"Life", "was", "like", "a", "box", "of", "chocolates.", "You", "never", "know", "what", "you're", "gonna", "get."
        "Do", "all", "the", "good", "you", "can,", "By", "all", "the", "means", "you", "can,", "In", "all", "the", "ways", "you", "can,", "In", "all", "the", "places", "you", "can,", "At", "all", "the", "times", "you", "can,", "To", "all", "the", "people", "you", "can,", "As", "long", "as", "ever", "you", "can."
    };
    char **r = fullJustify(words, wordsSize, maxWidth, returnSize);
    for (int i = 0; i < *returnSize; i++) {
        printf("\"%s\"\n", r[i]);
    }

    return 0;
}
