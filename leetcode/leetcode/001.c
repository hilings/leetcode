//
//  001.c
//  leetcode
//
//  Created by Hang Zhang on 4/5/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int compare (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int findInArray(int array[], int n, int value, int begin) {
    for (int i = begin; i < n; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

int *twoSum(int numbers[], int n, int target) {
    int index1 = 0, index2 = 0;
    int b[n];
    for (int i = 0; i < n; i++) {
        b[i] = numbers[i];
    }
    qsort(b, n, sizeof(int), compare);
    int i = 0, j = n - 1;
    while (i < j) {
        if (b[i] + b[j] < target) {
            i++;
        } else if (b[i] + b[j] > target) {
            j--;
        } else {
            index1 = findInArray(numbers, n, b[i], 0);
            index2 = findInArray(numbers, n, b[j], 0);
            if (index2 == index1) {
                index2 = findInArray(numbers, n, b[j], index1 + 1);
            }
            if (index2 > -1) {
                break;
            }
        }
    }
    int *result = (int *)malloc(2 * sizeof(int));
    if (index1 < index2) {
        result[0] = index1 + 1;
        result[1] = index2 + 1;
    } else {
        result[0] = index2 + 1;
        result[1] = index1 + 1;
    }
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("LeetCode 001 Two Sum, C ... ...\n");
    
    //int numbers[] = {4, 2, 1, 8, 5, 6};
    int numbers[] = {3, 2, 4};
    //int numbers[] = {3, 2, 5, 3};
    int n = sizeof(numbers)/sizeof(int);
    int target = 6;
    printArray(numbers, n);
    
    printArray(twoSum(numbers, n, target), 2);
    
    return 0;
}


