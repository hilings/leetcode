//
//  003.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/7/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int inStr(char *s, int begin, int end, char c) {
    while (begin < end) {
        if (s[begin] == c) {
            return begin;
        }
        begin++;
    }
    return -1;
}

int lengthOfLongestSubstring(char *s) {
    int longest = 0;
    int tmp = 0;
    int begin = 0;
    int end = 0;
    
    while (end < (int)strlen(s)) {
        char cur = s[end];
        int isFound = inStr(s, begin, end, cur);
        if (isFound == -1) {
            tmp++;
        } else if (s[begin] == cur) {
            begin++;
        } else {
            tmp = end - begin;
            if (tmp > longest) {
                longest = tmp;
            }
            begin = isFound + 1;
            tmp = end - begin + 1;
        }
        end++;
    }
    if (tmp > longest) {
        longest = tmp;
    }
    return longest;
}

int main(int argc, const char * argv[]) {
    // insert code here...    
    printf("LeetCode 003 Longest Substring Without Repeating Characters, C ... ...\n");

    //char s[] = "epqcrkeyjzbkvkrganbg";
    char s[] = "abcdbef";
    printf("%s\n", s);

    printf("\n%d\n", lengthOfLongestSubstring(s));


    return 0;
}