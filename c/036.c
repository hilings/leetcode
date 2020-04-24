//
//  036.c
//  leetcode
//
//  Created by Hang Zhang on 5/11/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void printBoard(char** board, int boardRowSize, int boardColSize) {
    printf("\n");
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            printf("%c ", board[i][j]);
            if (j % 3 == 2)
                printf("  ");
        }
        printf("\n");
        if (i % 3 == 2)
            printf("\n");
    }
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    bool set1[10], set2[10], set3[10];
    for (int i = 0; i < 9; i++) {
        memset(set1+1, false, 9);
        memset(set2+1, false, 9);
        memset(set3+1, false, 9);
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];   //  check row
            if (c != '.') {
                int k = c - '0';
                if (set1[k])
                    return false;
                set1[k] = true;
            }
            c = board[j][i];    //  check column
            if (c != '.') {
                int k = c - '0';
                if (set2[k])
                    return false;
                set2[k] = true;
            }
            c = board[i/3*3 + j/3][i%3*3 + j%3];    //  check block
            if (c != '.') {
                int k = c - '0';
                if (set3[k])
                    return false;
                set3[k] = true;
            }
        }
    }
    return true;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 036 Valid Sudoku, C ...\n\n");

    char c[][10] = {
        "..9748...",
        "7........",
        ".2.1.9...",
        "..7...24.",
        ".64.1.59.",
        ".98...3..",
        "...8.3.2.",
        "........6",
        "...2759.."
    };
    int boardRowSize = 9;
    int boardColSize = 9;
    char **board = (char**)malloc(sizeof(char*)*boardRowSize);
    for (int i = 0; i < boardRowSize; i++) {
        board[i] = (char*)malloc(sizeof(char) * boardColSize);
        memcpy(board[i], c[i], sizeof(char) * boardColSize);
    }
    printBoard(board, boardRowSize, boardColSize);

    printf("%s", isValidSudoku((char**)board, boardRowSize, boardColSize) ? "true" : "false");

    return 0;
}