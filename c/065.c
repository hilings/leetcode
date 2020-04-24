//
//  065.c
//  leetcode
//
//  Created by Hang Zhang on 12/18/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void mylog(int i, char* s) {
    printf("%d %s\n", i, s);
}

bool myisdigit(char* s, int i) {
    if (i < 0 || i >= strlen(s))
        return false;
    return isdigit(s[i]);
}

bool isNumber(char* s) {
    int i = 0;
    while (s[i] == ' ') {
        mylog(i, "leading space");
        i++;
    }
    if (i == strlen(s))
        return false;

    if (s[i] == '+' || s[i] == '-') {
        mylog(i, "+/-");
        i++;
    }

    while (isdigit(s[i])) {
        mylog(i, "d");
        i++;
    }

    if (s[i] == '.') {
        mylog(i, ".");
        if (!myisdigit(s, i-1) && !myisdigit(s, i+1))
            return false;
        i++;
    }

    while (isdigit(s[i])) {
        mylog(i, "d");
        i++;
    }

    if (s[i] == 'e') {
        mylog(i, "e");
        if (!myisdigit(s, i-1) && !myisdigit(s, i-2))
            return false;
        if (!myisdigit(s, i+1) && !myisdigit(s, i+2))
            return false;
        i++;

        if ((s[i] == '+' || s[i] == '-') && myisdigit(s, i+1)) {
            mylog(i, "+/-");
            i++;
        }
    }

    while (isdigit(s[i])) {
        mylog(i, "d");
        i++;
    }

    while (s[i] == ' ') {
        mylog(i, "trailing space");
        i++;
    }

    return i == strlen(s);
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 065 Valid Number, C ...\n\n");

    char *s = "  ";

    bool r = isNumber(s);
    printf("%s\n", r ? "true" : "false");
    
    return 0;
}
