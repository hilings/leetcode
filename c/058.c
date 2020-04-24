//
//  058.c
//  leetcode
//
//  Created by Hang Zhang on 12/15/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int ns, len = 0;
    for (ns = (int)strlen(s)-1; ns >= 0 && s[ns] == ' '; ns--) {}
    for (; ns >=0 && s[ns] != ' '; ns--)
        len++;
    return len;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 058 Length of Last Word, C ...\n\n");

    char s[] = " asdf  asdf  ";
    printf("%d\n", lengthOfLastWord(s));

    return 0;
}
