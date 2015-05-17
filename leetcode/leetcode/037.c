//
//  037.c
//  leetcode
//
//  Created by Hang Zhang on 5/13/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

char *binaryToStr(int a) {
    char *str = (char*)malloc(sizeof(char)*10);
    for (int i = 1; i <= 9; i++)
        str[i-1] = (a >> i & 1) == 1 ? '0'+i : ' ';
    str[9] = '\0';
    return str;
}

bool isValid(char** board, int co, char value) {
    int i = co / 9, j = co % 9;
    for (int k = 0; k < 9; k++) {
        if (board[i][k] == value || board[k][j] == value || board[i/3*3+k/3][j/3*3+k%3] == value)
            return false;
    }
    return true;
}
bool solve(char** board, int co) {
    if (co == 81)
        return true;
    int i = co / 9, j = co % 9;
    if (board[i][j] != '.')
        return solve(board, co+1);
    for (int k = 1; k <= 9; k++) {
        if (isValid(board, co, '0'+k)) {
            board[i][j] = '0'+k;
            if (solve(board, co+1))
                return true;
            board[i][j] = '.';
        }
    }
    return false;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    solve(board, 0);
    return;
}

// like human
int candidate[81];
int uniqueCandidate() {
    for (int co = 0; co < 81; co++) {
        int d = candidate[co];
        if (d == 0)
            continue;
        while ((d & 1) == 0)
            d = d >> 1;
        if (d == 1)
            return co;
    }
    return -1;
}
int binaryToInt(int a) {
    for (int i = 1; i <= 9; i++) {
        if ((a>>i) == 1)
            return i;
    }
    return 0;
}

void solveSudoku2(char** board, int boardRowSize, int boardColSize) {
    for (int co = 0; co < 81; co++) {
        candidate[co] = 0;
        if (board[co/9][co%9] == '.') {
            for (int d = 1; d <= 9; d++) {
                if (isValid(board, co, '0'+d))
                    candidate[co] |= 1 << d;
            }
        }
        if (candidate[co] > 0) {
            //printf("%d %d = [%s]\n", i, j, binaryToStr(candidate[co]));
        }
    }

    int u = uniqueCandidate();
    while (u > -1) {
        printf("unique candidate cell: %d %d <- %d\n", u/9, u%9, binaryToInt(candidate[u]));
        int i = u / 9, j = u % 9, d = binaryToInt(candidate[u]);
        board[i][j] = '0'+d;
        for (int k = 0; k < 9; k++) {
            candidate[9*i+k] &= ~(1<<d);
            candidate[9*k+j] &= ~(1<<d);
            candidate[9*(i/3*3+k/3) + (j/3*3+k%3)] &= ~(1<<d);
        }
        u = uniqueCandidate();
    }

    for (int co = 0; co < 81; co++) {
        int i = co / 9, j = co % 9;
        if (candidate[co] > 0) {
            printf("%d %d = [%s]\n", i, j, binaryToStr(candidate[co]));
        }
    }

    solve(board, 0);
    return;
}


int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 037 Sudoku Solver, C ...\n\n");

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

    solveSudoku2(board, boardRowSize, boardColSize);
    printBoard(board, boardRowSize, boardColSize);

    return 0;
}